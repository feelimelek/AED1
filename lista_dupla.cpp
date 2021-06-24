#include<stdio.h>

typedef struct{
	int chave;
	struct s* prox;
	struct s* ant;
} NO; //o NO da lista dupla possui um ant

typedef struct{
	NO* cab;
} LISTA_DUPLA;

void inicializar(LISTA_DUPLA* l){
	l->cab = (NO*)malloc(sizeof(NO));
	l->cab->prox = l->cab;
	l->cab->ant = l->cab; 
}