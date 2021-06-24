/*
Agora, vamos ao último, o mais monstruoso de todos: as listas generalizadas.
São aquelas listas que possuem sublistas em determinados nós, isto é, são listas comuns com dois tipos de elementos:
nós com chave ou nós que referenciam o começo de uma sublista.
Uma aplicação é escrever polinômios com muitas variáveis
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct(){
	struct s* prox;
	union{ //ou um existe (sublista) ou outro (chave), isto é são mutuamente exclusivos U 
		struct s* sublista;
		int chave;
	}
	int tipo; //1 = chave, 2 = ponteiro
} NO;

