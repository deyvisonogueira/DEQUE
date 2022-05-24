//Deyvison Nogueira RA:20211940042
#include <stdio.h>
#include <stdlib.h>
typedef int tdado;
typedef struct no{
	tdado dado;
	struct no *prox, *ant;
}tno;
typedef struct{
	tno *ini,*fim; //head e tale
}tdeque;
//-------------------------------
void inicializa(tdeque *f){
	f->ini = NULL;
	f->fim = NULL;
}
//------------------------------
int enqueueFim(tdeque *f, tdado x){
	tno *novo = malloc(sizeof(tno));
	if(novo==NULL) // memoria ta cheia
	  return 0;
	novo->dado = x;
	novo->prox = NULL;
	novo->ant = f->fim; // alteração DEQUE
	if(f->ini==NULL) // testando se esta vazia
	  f->ini = novo;
	else
	  f->fim->prox = novo;
	
	f->fim = novo;    	
	return 1;
}
//---------------------------------------------
int enqueueIni(tdeque *f, tdado x){
	tno *novo = malloc(sizeof(tno));
	if(novo==NULL) // memoria ta cheia
	  return 0;
	novo->dado = x;
	novo->ant = NULL;
	novo->prox = f->ini; // alteração DEQUE
	if(f->ini==NULL) // testando se esta vazia
	  f->fim = novo;
	else
	  f->ini->ant = novo;
	
	f->ini = novo;    	
	return 1;
}
//---------------------------------------------
tdado dequeueIni(tdeque *f){
	tdado r = f->ini->dado; // pegando o dado armazenado no nó
	tno *aux = f->ini; // guardando o endereço para limpar a memoria
	f->ini = f->ini->prox; // removendo, deslocando o apontamento
	if(f->ini == NULL) // era o ultimo elemento
	   f->fim = NULL;
	else  
	   f->ini->ant = NULL; // Alteração da DEQUE  
	free(aux); // limpando a memoria
	return r; // retorno o dado removido
}
//----------------------
tdado dequeueFim(tdeque *f){
	tdado r = f->fim->dado; // pegando o dado armazenado no nó
	tno *aux = f->fim; // guardando o endereço para limpar a memoria
	f->fim = f->fim->ant; // removendo, deslocando o apontamento
	if(f->fim == NULL) // era o ultimo elemento
	   f->ini = NULL;
	else  
	   f->fim->prox = NULL; // Alteração da DEQUE  
	free(aux); // limpando a memoria
	return r; // retorno o dado removido
}
//----------------------
int isEmpty(tdeque f){
	if(f.ini == NULL) // se estiver vazio ini e fim ==NULL
	  return 1;
	else
	  return 0;  
}
//-----------------------------
void printQueue(tdeque f){
	while(f.ini != NULL){
		printf("%d -",f.ini->dado); // mostro o dado
		f.ini = f.ini->prox; // deslocando para o prox
	}// fim while
	printf("\n");
}
//-----------------------------
void printQueueInvertida(tdeque f){
	while(f.fim != NULL){
		printf("%d -",f.fim->dado); // mostro o dado
		f.fim = f.fim->ant; // deslocando para o ant
	}// fim while
	printf("\n");
}
//-----------------------------
void mostraEndereco(tdeque f){
	while(f.ini != NULL){
		printf("%x| %d [%x] | %x \n ",
		        f.ini->ant, f.ini->dado, f.ini , f.ini->prox); // mostro o dado
		f.ini = f.ini->prox; // deslocando para o prox
	}// fim while
	printf("\n");
}
//-----------------------------
int menu(){
	int op;
	printf("*** Estrutura de Dados I ***\n");
	printf("*** Fila Encadeada ***\n");
	printf("1-Enqueue Fim (Inserir)\n");
	printf("2-Dequeue Ini  (Remover)\n");
	printf("3-Primeiro e ultimo da fila\n");//?
	printf("4-Mostrar Fila Inversa\n");//?
	printf("5-Enqueue Ini (Inserir)\n");//?
	printf("6-Dequeue Fim (Remover)\n");//?
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}
//--------------------
int main(){
	int op;
	tdado x;
	tdeque f1;
	inicializa(&f1);
	do{
		printf("Ini:%x | Fim:%x\n",f1.ini, f1.fim);
		printQueue(f1);
		//mostraEndereco(f1);
		op = menu();
		switch(op){
			case 1: printf("Valor para inserir:");
					scanf("%d",&x);
					if(enqueueFim(&f1,x)) // ==1
					   printf("Valor inserido:)\n");
					else
					   printf("Fila cheia:(\n");   
				break;
			case 2: if(!isEmpty(f1)){
				      x = dequeueIni(&f1);
				      printf("Removido: %d\n",x);
					}// fim if
					else
					  printf("Fila vazia :(\n");
			   break;
			case 3: if(!isEmpty(f1)){
				      //printf("Inicio: %d\n",primeiro(f1));
				      //printf("Fim: %d\n",ultimo(f1));
			         }// fim if 
					 else
					    printf("Fila vazia :(\n");
			case 4: if(!isEmpty(f1)){
				      printQueueInvertida(f1);
			break;
			case 5: printf("Valor para inserir no inicio:");
					scanf("%d",&x);
					if(enqueueIni(&f1,x)) 
					   printf("Valor inserido:)\n");
					else
					   printf("Fila cheia:(\n");   
			break;
			case 6: if(!isEmpty(f1)){
				      x = dequeueFim(&f1);
				      printf("Removido no fim: %d\n",x);
					}// fim if
					else
					  printf("Fila vazia :(\n");
			   break;
			         }// fim if 
					 else
					    printf("Fila vazia :(\n"); 			 
			break;
			case 0: printf("Saindo...");  
			break;	
		}// fim switch
		getch();
		system("cls"); 
	}while(op!=0);
}// fim main

