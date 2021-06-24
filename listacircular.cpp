/*
A lista ligada dinâmica circular dá voltas
*/

#include <stdio.h>

typedef struct{
	int chave;
	struct s* prox;
} NO;

typedef struct{
	NO* inicio;
} LISTA_CIRC;

void inicializar(LISTA_CIRC* l){
	l-> inicio = NULL; 	//assim como na lista ligada dinamica simples ao inicializar atribuímos NULL ao l->inicio, 
}

void imprimir(LISTA_CIRC* l){
	NO* p = l->inicio; //usaremos esse ponteiro para percorrer a lista
	
	if(!p)
		return;//não há elemetnos
	printf("%d", p->chave);
	p = p->prox;
	while(p != l->inicio){ //enquanto não for o início de novo, a gente imprime
		printf("%d", p->chave);
		p = p->prox; //o ponteiro auxiliar anda para o próximo
	}
}

NO* busca(LISTA_CIRC* l, int ch, NO** ant){
	*ant = NULL;
	NO* p = l->inicio;
	if(!p)
		return NULL;
	if(p->chave == ch)
		return p;
	p = p->prox;
	while(p!=l->inicio) { // vai sair do loop quando recomeçar
		if(p->chave == ch)
			return p;
		*ant = p;
		p = p->prox;
	}
	return NULL; //ant é o último elemento nesse caso e o p, virou de volta o início
}

//ISTO NÃO É SOBRE LISTA CIRCULAR
NO* ultimo(LISTA_SENT* l){
	NO* p = l->inicio;
	while(p!=l->sent){
		if(p->prox == l->sent)
			return p;
		p = p->prox;
	}
	return NULL;
}




int main(){
	LISTA_SENT l;
	inicializar(&l);

	int ant;

}