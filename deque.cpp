/* Deques: double ended queue, ou, fila de duas pontas
	O que significa isso? os elementos podem entrar e sair de ambos os lados, mas só por eles.
	Porém existe um problema, sendo de duas mãos, como eu sei qual é o anterior?
	Usando implementação dinâmica com listas duplas (usaremos esse) ou lista estática circular. 
	Haverá portanto dois ponteiros de inicio (um para cada extremidade): inicio1 (o da esquerda) e inicio2 (o da direita).
*/

#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h> //se for usar malloc precisa dessa biblioteca

/*Operações principais:
	Inicializar
	Do lado direito:
	Inserir ou excluir
	Do lado esquerdo:
	Inserir ou excluir
*/
typedef struct{
	int chave;
	struct s* prox;
	struct s* ant;

}NO;

typedef struct{
	NO* inicio1;
	NO* inicio2;
} DEQUE;

void inicializar(DEQUE* d){
	d->inicio1 = NULL;
	d->inicio2 = NULL;
}

//saindo pelo ínicio 1 (esquerda)
int sairInicio1(DEQUE* d){ //retorna chave do que saiu
	int resp = -1; //variável do valor que será retornado
	if(d->inicio1){ //se existe, vamos remover
		resp = d->inicio1->chave; //guardo a chave
		NO* aux = d->inicio1;
		d->inicio1 = d->inicio1->prox;
		free(aux);
		if(!d->inicio1){//se depois de removido, não houver um d->inicio1, precisamos arrumar o d->fim
			d->inicio2 = NULL;
		}
		else
			d->inicio1->ant = NULL; //precisamos arrumar o ant do d->inicio
	}
	return resp;
}

void entrarInicio1(DEQUE* d, int ch){
	NO* novo = (NO*)malloc(sizeof(NO));
	novo->chave = ch;
	novo->prox = d->inicio1; //conectei no começo
	novo->ant = NULL;
	if(d->inicio1){ //se existir d->inicio
		d->inicio1->ant = novo; //ponteiro da volta
	}
	else
		d->inicio2 = novo;
	d->inicio1 = novo;
}

int sairInicio2(DEQUE* d){
	int resp = -1;
	if(d->inicio2){
		resp = d->inicio2->chave;
		NO* aux = d->inicio2;
		d->inicio2 = d->inicio1->ant;
		free(aux);
		if(!d->inicio2){//se não existir significa que só havia um elemento
			d->inicio1 = NULL;
		}
		else{
			d->inicio2->prox = NULL;
		}
		return resp;
	}

	return resp;

}

//(direita)
void entrarInicio2(DEQUE* d, int ch){
	NO* novo = (NO*)malloc(sizeof(NO));
	novo->chave = ch;
	novo->ant = d->inicio2;
	if(d->inicio2){
		d->inicio2->prox = novo;
	}
	else
		d->inicio1 = novo; //primeira inserção
	d->inicio2 = novo;
}

int main(){
	DEQUE d;
	inicializar(&d);
 	NO* x = (NO*)malloc(sizeof(NO)); 	//basicamente o que essa função faz é: tipo a ser apontado por x (x terá um endereço que apontará 
										//para uma variável do tipo NO) = (tipo de endereço a ser retornado, se não coloca, vem um genérico)
										//memory allocation (tamanho em bytes do espaço que quero alocar)
										//na hora de criarmos uma lista, ao invés do termo inexistente estar na posição -1, o endereço dele
										//é NULL
	x-> chave = 20; //segue o mesmo esquema da estática. Coloquei 20 na variável chave existente dentro do NO, apontado por x
	x-> prox = NULL; //de onde está o 20 não vai a outro NO
	NO* y = (NO*)malloc(sizeof(NO));
	y-> chave = 10; //criei uma nova bolinha que contém 10 
	y-> prox = x; 	//liguei ela a X, ou seja, armazenei na variável prox - que espera um endereço/ponteiro - o endereço de x
	x->	ant = y;			//agora tenho dois ponteiros visíveis: o que aponta para onde está 20 sozinho (x)  o que aponta para onde está 10 (y) 
	NO* ant = NULL;		//também tenho dois ponteiros ocultos: o que vai de onde está 10 para onde está 20 e o que vai até NULL (fim da lista)	
	d.inicio1 = y;
	d.inicio2 = x;

	printf("%d", sairInicio1(&d));
	entrarInicio1(&d, 6);
	printf("%d", sairInicio2(&d));
	entrarInicio2(&d, 5);
	return 0;
}