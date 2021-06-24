/* Acabamos de ver as filas dinâmicas, agora vamos para as estáticas, organizadas em vetores.
	Faremos tipo um vetor circular para não gastar espaço quando remover
	Ao invés de ponteiros, temos índices (inteiros)
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
	int A[MAX];
	int inicio; //por onde sai
	int fim; //por onde entra
} FILA_EST; 

/*Operações principais:
	Inicializar
	Inserir
	Excluir
*/

void inicializar(FILA_EST* f){
	f->inicio = -1;
	f->fim = -1;
}

/* 	Na exclusão, eu incremento o início (não é mudar o ponteiro, é mudar o "conteúdo" do índice) e na inserção, incremento o fim
	Se ta no fim do vetor e preciso incrementar? Vai para a primeira posição, se ela tiver livre. Assim, não gastamos espaço 

*/
int sairFila(FILA_EST* f){ //retorna chave do valor excluído
	int resp = -1;
	if(f->inicio > -1){ //existe 
		resp = f-> A[f->inicio]; //"chave" do elemento que será removido
		if(f->inicio == f->fim){ //só tem um elemento
			f->inicio = -1;
			f->fim = -1;
		} else
		    f-> inicio = ((f->inicio) + 1)% MAX; 	//se divido tenho o índice de onde o ínicio será, a última posição + 1/MAX, dá 1 e 											//sobra 0, o resto 0 será o índice do ínicio, levando a "circularidade"
	}
	return resp;
} 

bool vetorCheio(FILA_EST* f){
	if((f->inicio + 1) %MAX == f->fim) //está cheio, pois a posição seguinte já está sendo "usada" pelo fim
		return true;
	else
	    return false;
}

bool entrarFila(FILA_EST* f, int ch){
	if(vetorCheio(f)) return false;
	f->fim = (f->fim +1)%MAX; //define a circularidade para caso caiba, arrumei o índice de fim
	f->A[f->fim] = ch; 
	if(f->inicio == -1) //se for a primeira inserção, o índice do início também deve mudar
		f->inicio = f->fim;
	return true;
}

int main(){
	FILA_EST f;
    f.inicio = 0;
	f.fim = 2;
	f.A[f.inicio] = 0;
	f.A[1] = 1;
	f.A[f.fim] = 2;
	printf("%d", sairFila(&f));
    inicializar(&f);
    if(entrarFila(&f, 2))
        printf("%s", f.A[fim]);
	return 0;
}