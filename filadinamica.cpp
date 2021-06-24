/* Agora entraremos em uma parte de aplica��es das listas ligadas que formam outras estruturas de dados.
Iniciando a s�rie "Estruturas fant�sticas e onde se alocam":
Era uma vez as listas lineares. Essas estruturas eram t�o magn�ficas que formaram a base de muitas outras estuturas que viriam.

E assim, nasceram as FILAS.
Filas s�o listas lineares com disciplina de acesso, isto �, existe um "caminho" certo para inserir e excluir algo. 
Elas tem uma filosofia chamada "FIFO", cuja tradu��o literal �: "First-in, first-out". O que significa que o primeiro elemento
a entrar na fila, ser� o primeiro a sair, como uma fila de supermercado mesmo.
Portanto, existe a entrada (extremidade direita, fim), na qual acontecem as inser��es e a sa�da (extremidade esquerda, come�o), 
onde ocorrem as exclus�es.
Resumindo:

Inser��es: apenas no fim
Exclus�es: apenas no �nicio.

Esse recurso � muito usado para sistemas operacionais devido as solicita��es que s�o feitas pelo usu�rio ou at� na impress�o de
arquivos. 
Ent�o vamos a estrutura em si
*/
#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>

typedef struct s{
	int chave;
	struct s* prox;	
} NO;

typedef struct{
	NO* inicio;
	NO* fim;
} FILA_DIN;

/*
Opera��es b�sicas
Inicializar
Inserir - entrarFila
Excluir - sairFila

*/

void inicializar(FILA_DIN* f){
	f->inicio = NULL;
	f->fim = NULL;
}

//remover 
int sairFila(FILA_DIN* f){ //retorna a chave ou -1 do elemento que saiu
	int resp = -1; //vai armazenar a chave se houver
	NO* aux = f->inicio; //o elemento que sair�
	if(aux){
		resp = aux->chave; //armazena o valor
		f->inicio = f->inicio->prox; //troca o ponteiro
		free(aux); //libera esse espa�o
		if(!f->inicio){ //se o in�cio for NULL, significa que a lista esvaziou, logo precisamos arrumar o ponteiro do fim
			f->fim = NULL;
		}
	
	}
	return resp;
}

//inserir

void entrarFila(FILA_DIN* f, int ch){ 
	NO* novo = (NO*)malloc(sizeof(NO));
	novo->chave = ch; //� necess�rio inicializar o NO
	novo->prox = NULL;
	if(f->fim){
		f->fim->prox = novo;
	} else
		f->inicio = novo; 	//como n�o h� f-> fim significa que a lista est� vazia, portanto precisamos referenciar o NO criado,
							//que � tanto o inicio, quanto o fim
	f->fim = novo;
}

/* 	Poderia colocar prioridades para inserir ou excluir
	Vantagens: efici�ncia operacional, n�o tem la�os, ent�o o tempo � bom, custo O(1).
*/

int main(){
	FILA_DIN f;
	NO* x = (NO*)malloc(sizeof(NO));
	f.inicio = x;
	x->chave = 2;
	NO* y = (NO*)malloc(sizeof(NO));
	x->prox = y;
	f.fim = y;
	printf("%d", sairFila(&f));
	entrarFila(&f, 5);

	return 0;
}


