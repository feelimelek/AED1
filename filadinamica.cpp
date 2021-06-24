/* Agora entraremos em uma parte de aplicações das listas ligadas que formam outras estruturas de dados.
Iniciando a série "Estruturas fantásticas e onde se alocam":
Era uma vez as listas lineares. Essas estruturas eram tão magníficas que formaram a base de muitas outras estuturas que viriam.

E assim, nasceram as FILAS.
Filas são listas lineares com disciplina de acesso, isto é, existe um "caminho" certo para inserir e excluir algo. 
Elas tem uma filosofia chamada "FIFO", cuja tradução literal é: "First-in, first-out". O que significa que o primeiro elemento
a entrar na fila, será o primeiro a sair, como uma fila de supermercado mesmo.
Portanto, existe a entrada (extremidade direita, fim), na qual acontecem as inserções e a saída (extremidade esquerda, começo), 
onde ocorrem as exclusões.
Resumindo:

Inserções: apenas no fim
Exclusões: apenas no ínicio.

Esse recurso é muito usado para sistemas operacionais devido as solicitações que são feitas pelo usuário ou até na impressão de
arquivos. 
Então vamos a estrutura em si
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
Operações básicas
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
	NO* aux = f->inicio; //o elemento que sairá
	if(aux){
		resp = aux->chave; //armazena o valor
		f->inicio = f->inicio->prox; //troca o ponteiro
		free(aux); //libera esse espaço
		if(!f->inicio){ //se o início for NULL, significa que a lista esvaziou, logo precisamos arrumar o ponteiro do fim
			f->fim = NULL;
		}
	
	}
	return resp;
}

//inserir

void entrarFila(FILA_DIN* f, int ch){ 
	NO* novo = (NO*)malloc(sizeof(NO));
	novo->chave = ch; //é necessário inicializar o NO
	novo->prox = NULL;
	if(f->fim){
		f->fim->prox = novo;
	} else
		f->inicio = novo; 	//como não há f-> fim significa que a lista está vazia, portanto precisamos referenciar o NO criado,
							//que é tanto o inicio, quanto o fim
	f->fim = novo;
}

/* 	Poderia colocar prioridades para inserir ou excluir
	Vantagens: eficiência operacional, não tem laços, então o tempo é bom, custo O(1).
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


