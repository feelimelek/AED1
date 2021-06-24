/*
Agora, vamos para a outra representação: matrizes esparsas representadas por listas cruzadas.
Queremos entrar numa linha sem ter que percorrer tudo, espetando ponteiros em cada NO, a partir da linha e coluna, isto é, há um
vetor início para linhas e um vetor início para colunas.
É mais rápido, mas gasta mais memória.

*/

#include <stdio.h>
#include <stlib.h>
#include <stdbool.h>

#define MAXLIN 10
#define MAXCOL 10

//Dentro do NO, as coordenadas são armazenadas, pois são necessárias em alguns algoritmos, por mais redundante que seja 

typedef struct{
	int chave;
	NO* proxC; //para a direita, próxima coluna
	NO* proxL; //para baixo, próxima linha
	int i; //linha
	int j; //coluna
}NO;

typedef struct{
	NO* lin[MAXLIN+1]; 	//vou adicionar 1, para começar a contagem de 1 e facilitar minha vida de programadora, o primeiro elemento
						//desse vetor será sempre 0 e o último maxlin
	NO* col[MAXCOL+1];

} LISTACRZ;

void inicializar(LISTACRZ* l){
	for(int i = 1; i <= MAXLIN; i++){
		l->lin[i] = NULL;
	}
	for(int i = 1; i <= MAXCOL; i++){
		l->col[i] = NULL;
	}
}

//Para fazer qualquer algoritmo em listas cruzadas, preciso lembrar que um elemento pertence a duas listas

void exibir(LISTACRZ* l){
	int j;
	for(j = 1; j <= MAXCOL; j++){ //percorre a coluna
		NO* p = l->lin[j];
		while(p){ //percorre a linha
			printf("%d", p->chave);
			p = p->proxL;
		}
	}
}

/*NO* busca(LISTACRZ* l, int i, int j, NO**esq, NO**acima){
	if(i<1||i>MAXLIN||j<1||j>MAXCOL) return -1;//não está incluído na matriz
	//escolho se quero percorrer pela linha ou pela coluna, vamos percorrer a linha
	NO* p = l->col[j]; //quero a coluna j
	while(p->i != i){ //se a linha não for a mesma, continua procurando
		p = p->proxL;//vai um pra baixo
	}//encontrei onde é igual
	if(p)
		return p->chave;
	else
		return 0; //se não encontrei o elemento, quer dizer que é 0


}
*/

/*
Comparando as estruturas de matriz:
					Espaço					Acessar o elemento i,j		Percorre a coluna
Matriz  normal		MAXLIN*MAXCOL			O(1) 						O(MAXLIN)  =>Se tem espaço, essa é a melhor
Linhas				Ñ zeros					O(n)						O(n)
Listas cruzadas 	Ñ zeros+MAXLIN+MAXCOL	O(MAXLIN) ou O(MAXCOL)		O(MAXLIN)  =>Espaços pioram, mas o acesso melhora

*/
int main(){

	return 0;
}