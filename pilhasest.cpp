/*
Agora entramos nos universos das pilhas.
As pilhas são listas lineares com disciplina de acesso, isto é, existe um caminho certo para inserir e excluir elementos.
Elas seguem a filosofia FILO: first in, last out, o que significa que o primeiro que entra é o último a sair, como uma pilha de
livros, se você coloca um livro primeiro e vai empilhando, aquele será o último que conseguirá ser pego.
Nessa estrutura a única porta de entrada e saída é o "topo", o ínicio (à direita na pilha estática).
Ela é muito usada para calcular operações e expressões aritméticas, bem como o mecanismo de adicionar páginas no navegador e 
depois ir excluindo. Recursão usa pilha de execução (não criamos uma pilha para isso, já faz parte do sistema de execução).
Resumindo,
é uma lista linear que só permite incluir no topo e excluir no topo

*/


#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
	int A[MAX];
	int topo; 					//indíce do topo será armazenado nessa variável
} PILHA_EST;

void inicializar(PILHA_EST* p){
	p->topo = -1;
}

/*
Operações básicas:
Inicializar

Push - Entrada
Problemas recorrentes: stack overflow, tento adicionar mais do que cabe.

Pop - Saída
Problemas recorrentes: underflow, tento tirar algo que não existe.

*/

int pop(PILHA_EST* p){ 			//tirar um elemento (pela direita), retorna o valor do elemento retirado
	int resp = -1;
	if(p->topo != -1){ 			//existe
		resp = p->A[p->topo];	//valor que está lá dentro do vetor que pertence a estrutura pilha
		p->topo = p->topo - 1;	//recuo o ponteiro de topo uma vez
}
	return resp;
}

bool push(PILHA_EST* p, int ch){
	if(p->topo < MAX-1){//se não está no limite, dá para adicionar
		p->topo = p->topo + 1; //avanço uma casa
		p->A[p->topo] = ch;
		return true;
	}
	else
		return false;

}

void imprimir(PILHA_EST* p){
    for(int i = 0; i <= p->topo; i++){
        printf("%d", p->A[i]);
    }    
}
 //mesma complexidade assintótica

int main(){
    PILHA_EST p;
    inicializar(&p);
    for(int i = 0; i < 4; i++){
        push(&p, i);
    }
    printf("O Topo é: %d", p.topo);
    imprimir(&p);
    pop(&p);
    imprimir(&p);
    
	return 0;
}