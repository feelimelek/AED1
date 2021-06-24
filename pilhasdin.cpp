/*
As pilhas também podem ser implementadas dinamicamente.
*/
#include <stdio.h>
#include <stdlib.h> //para usar malloc precisa
#include <stdbool.h>

// vamos definir a estrutura, trataremos como uma lista ligada comum com ínicio no topo, de modo que as entradas e saídas só são
// realizadas por ele

typedef struct{
	int chave;
	struct s* prox;
} NO;

typedef struct {
	NO* topo;
} PILHA_DIN;

/*
Operações básicas:
Inicializar
Pop - excluir
Push - inserir
*/

void inicializar(PILHA_DIN* p){
    p->topo = NULL;
}

int pop(PILHA_DIN* p){ //quero a chave do elemento retirado
	int resp = -1;
	if(p->topo){//se existir
		resp = p->topo->chave; //armazeno o valor da chave do elemento a ser retirado
		NO* aux = p->topo; //referencio o topo para n perder 
		p->topo = p->topo->prox; //troco o topo para o próximo elemento
		free(aux); //libero a memória que elemento retirado ocupa
	}
	return resp;
}

//Possui complexidade assintótica O(1);

void push(PILHA_DIN* p ,int ch){
	NO* novo = (NO*)malloc(sizeof(NO)); //crio um novo NO
	novo->chave = ch; //armazeno o valor da chave, indicado como parâmetro da função
	novo->prox = p->topo; //conectei no início
	p->topo = novo;
}

void imprimir(PILHA_DIN* p){
	NO* aux = p->topo;
	while(aux){
		printf("%d", aux-> chave);
		aux = aux->prox;
	}
}

int main(){
	PILHA_DIN p;
    inicializar(&p);
    for(int i = 0; i < 4; i++){
        push(&p, i);
    }
    printf("O Topo é: %d", p.topo->chave);
    imprimir(&p);
    pop(&p);
    imprimir(&p);
}