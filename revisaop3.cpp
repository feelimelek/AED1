
#include <stdio.h>
#include <stdlib.h> //para usar malloc precisa
#include <stdbool.h>
//-----------------------------------------pilha----------------------------------------------------
typedef struct{
	int chave;
	struct s* prox;
} NOP;

typedef struct {
	NOP* topo;
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

NO* pop(PILHA_DIN* p){ //quero a chave do elemento retirado
	int resp = NULL;
	if(p->topo){//se existir
		resp = p->topo; //armazeno o valor da chave do elemento a ser retirado
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
//-----------------------------------------------------ELEMENTOS CHAVE DA ÁRVORE BINÁRIA-----------------
typedef struct s{
		int chave;
		struct s *dir;
		struct s* esq;
} NO;





//-------------------------------------------------------EXERCÍCIOS--------------------------------

void visitar(){

}
//1. Escrever um algoritmo de percurso pré ordem em árvore utilizando uma pilha
void preOrdemPilha(NO* raiz) { //onde começa
		PILHA* pi;
		inicializar(&pi);
		NO* p = raiz; //ponteiro iterador do tipo NO
		while(p){
			visitar(p);
			if(p->dir) push(&pi, p->dir); //guardo o endereço da direita
			p = p->esq; //o ponteiro muda, vai para a esquerda
			if(!p){ //se não existir, mais esquerda, vai para a última direita salva
				p = pop(&pi); //ponteiro vai para a direita
			}
		}

}

//2. Escrever o mesmo algoritmo de percurso anterior utilizando recursão
void preOrdem(NO* raiz){ //usando recursão, usamos a pilha de execução, logo, não precisa implementar uma pilha
	if(p){
		visitar(p);
		preOrdem(p->esq); 	//não precisa testar se existe primeiro, porque a função já testa isso no começo, no caso anterior,
							//precisava, pois precisávamos guardar a info da direita, sem saber se existia (testamos primeiro isso)
		preOrdem(p->dir);
	}
}
//-----------------------------------------------FILA-------------------------------------------------------------
typedef struct {
	struct s* chave;
	struct s* prox;	
} NOF;

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
	NOF* aux = f->inicio; //o elemento que sairá
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

void entrarFila(FILA_DIN* f, NO* p){ 
	NOF* novo = (NOF*)malloc(sizeof(NO));
	novo->chave = p; //é necessário inicializar o NO
	novo->prox = NULL;
	if(f->fim){
		f->fim->prox = novo;
	} else
		f->inicio = novo; 	//como não há f-> fim significa que a lista está vazia, portanto precisamos referenciar o NO criado,
							//que é tanto o inicio, quanto o fim
	f->fim = novo;
}

//3. Escrever um algoritmo de percuso em nível (utilizando uma fila como estrutura auxiliar)

void emNivel(NO* raiz){
	FILA* f;
	inicializar(&f);
	entrarFila(&f, raiz); //guardo a raiz na primeira posição, quando eu tirar, preciso ter os dois proximos na fila
	while(f.inicio){
		NO* p = sairFila(&f); //o primeiro iterador será a raíz, primeiro nivel e ai vai pegando o início a cada iteração
		visitar(p); //fazer o comando
		if(p->esq) entrarFila(&f, p->esq);
		if(p->dir) entrarFila(&f, p->dir); //se não tiver a condição, ele pode tentar acessar algo que não existe
	}

}

//4. Encontrar o nó pai de uma chave apontada por *p

void acharPai(NO* raiz, NO* p, NO**pai){ //melhor percurso: pré ordem
	if(raiz){
		if(raiz == p) //não tem pai
		return;
		if(raiz->dir == p || raiz->esq == p) { //visitar
			*pai = raiz;
			return;
		}
		acharPai(raiz->esq, p, pai); //esq, como a função é void, ela retornará nada e precisa de algo no escopo que retorne a acharPai
		if(*pai) return; //achei pai
		acharPai(raiz->dir, p, pai); //dir, se achar, a recursão achará e retornará, o pai já terá sido modificado pela recursão	
	} 
}

//5. Contar quantos elementos existem na árvore
int contar(NO* raiz){
	if(raiz){
		return 1 + contar(raiz->esq) + contar(raiz->dir);		
	}
	else return 0;
}

//6. Contar as ocorrências de ch em uma árvore
int contarCh(NO* raiz, int ch){
	if(raiz){
		if(raiz->chave == ch){
			return 1 + contarCh(raiz->esq) + contarCh(raiz->dir);	//pré-ordem	
		}
		else return 0;
	}
}

//7. Fazer um algoritmo de busca em uma ABB
NO* buscar(NO* raiz, int ch){ //recursão
	if(raiz){
		if(raiz->chave == ch){
			return raiz;
		}
		if(raiz->chave > ch){
			return buscar(raiz->esq, ch);
		}
		else{
			return buscar(raiz->dir, ch);
		}
	}
	return NULL;
}

NO* buscar(NO* raiz, int ch){ //recursão
	while(raiz){
		if(raiz->chave == ch) return raiz;
		if(raiz->chave > ch) raiz = raiz->esq;  //vou para a esquerda procurar
		else raiz = raiz->dir;
	}
	return NULL;
}

//8. Repetir o mesmo algoritmo anterior, mas também retornando o pai do elemento procurado
NO* buscar(NO* raiz, int ch, NO** pai){ //recursão
	*pai = NULL;
	while(raiz){
		if(raiz->chave == ch){
				return NULL; //não tem pai	
		} 
		*pai = raiz;
		if(raiz->chave > ch) raiz = raiz->esq;
		else raiz = raiz->dir;
	return NULL;
}

//9. Exibir todos os ancestrais de uma chave ch em uma ABB
void ancestral(NO* raiz, int ch){
	if(raiz){
		if(raiz->chave == ch) return; //não quero que exiba o próprio elemento, só seus ancestrais
		printf(%d, raiz->chave); //vou imprimindo os ancestrais até achar = visitar
		if(raiz->chave > ch){ //se o elemento atual possui chave maior que o procurado, então o procurado está à esquerda dele por ser ABB
			ancestral(raiz->esq, ch); 
		}
		else 
			ancestral(raiz->dir, ch);
	}

}

//10. Espelhar uma árvore ABB
void espelhar(NO* raiz){
	if(raiz){
		//visitar
		NO* aux = raiz->esq;
		raiz->esq = raiz->dir;
		p->dir = aux;
		espelhar(raiz->esq);
		espelhar(raiz->dir);
	}
}

//11.a Exibir todas chaves menores que X em uma ABB
void exibirMenoresX(NO* raiz, int X){ 	
	if(raiz){
		if(raiz->chave < X) printf("%d", raiz->chave); //imprimo	
		exibirMenores(raiz->esq, ch); //vou tudo que dá para a esquerda
		exibirMenores(raiz->dir, ch); //vou para a direita
	}

}

//11.b Exibir até n chaves menores que X em uma ABB
void exibirMenoresX(NO* raiz, int X, int* n){ 	//o percurso em-ordem me dá os elementos em sua ordem crescente, então esse é o percurso 
												//ideal para resolver esse problema, o n precisa ser passado por referência, pois na
												//recursão, estamos manipulando os mesmos ns
	if(raiz){
		if(raiz->chave < X && n > 0){ //se atende a condição de ser menor que x e se ainda pode exibir chaves (max n) 
			printf("%d", raiz->chave); //imprimo
			*n = *n-1;//reduzo a quantidade de chaves que ainda podem ser impressas
		}		
		if(n>0) exibirMenores(raiz->esq, ch, n); //vou tudo que dá para a esquerda
		if(n>0) exibirMenores(raiz->dir, ch, n); //vou para a direita
	}
}

//12. Remover todas as folhas de uma árvore (a árvore garantidamente possui mais de um elemento)
bool ehFolha(NO* p){
		if(!p->esq && !p->dir){ //se não tiver nenhum filho é folha (grau zero), então posso remover
			return true; //é folha		
		}
		else return false;
	
}

void removerFolhas(NO* raiz){
	if(raiz){
		if(raiz->esq && ehFolha(raiz->esq)){ //se o elemento da esquerda for uma folha, eu preciso dar free e mudar os ponteiros
			free(raiz->esq);
			raiz->esq = NULL;
		}
		if(raiz->dir && ehFolha(raiz->dir)){ //se o elemento da direita for uma folha, eu preciso dar free e mudar os ponteiros
			free(raiz->dir);
			raiz->dir = NULL;
		}
		//se não tiver filhos folhas, preciso procurar, então vamos de pré - ordem (o visitar já foi, agr falta esq e dir)
		removerFolhas(raiz->esq);
		removerFolhas(raiz->dir);
	}

}

//13. Calcular a altura de um elemento p
int maior(int x, int y){
	if(x >= y)
		return x;
	else return y;
}

int h(NO* p){ 	//lembrando que a altura é a maior altura dos filhos + 1 e a altura das folhas é 1, então precisa da altura do filho
	if(p){			// esquerdo e do direito para comparar primeiro e depois definir, nesse caso, o pós ordem será o percurso mais adequado	
		int h1 = h(p->esq);
		int h2 = h(p->dir);
		if(ehFolha(p))
			return 1 + maior(h1, h2);
	}
	else return 0; //achou a folha 
}
// 14. Exibir uma árvore até um dado nível

typedef struct s{
	NO* pont; //ao inves de ser uma fila com chaves, tera ponteiros de espaços de memória do tipo NO da árvore (c esq, dir, chave)
	struct s* prox;
	int nivel; 
} NOF2;
void exibirAteI(NO* raiz, int i){ //i = nível, modificamos o typedef da fila para ter o nivel
	FILA* f;
	int n = 1;
	inicializar(&f);
	entrarFila(&f, raiz);
	while(f.inicio){
		NO* aux = sairFila(&f); //percurso em nível começa assim
		if(aux->nivel <= i) //visitar
			printf("%d", aux->pont->chave);
		if(aux->pont->esq) entrarFila(&f, aux->pont->esq); //salvo esq
		
		if(aux->pont->dir) entrarFila(&f, aux->pont->dir); ////salvo dir
	}

}

//15. Verificar se uma árvore é ABB
//Lembrando que para ser ABB, os elementos do lado esquerdo devem ser menores q p, e os da direita, maiores
bool ehABB(NO* p, int* aux){ //o aux armazenará a chave que estamos comparando (a da raíz), começando com -1 	
	bool ok;
	if(p){
		ok = ehABB(p->esq, aux);
		if(ok){ //se for ok, sobre o nó atual 
			if(p->chave <= *aux) return false; //se o valor de cima, ou o valor da direita for menor que o de baixo/esquerda, não é ABB
			*aux = p->chave; //guardo o valor da chave, se ela n for 
			ok = ehABB(p->dir, aux); //se isso der false, terá que retornar false
		}
		return ok;
	}
	return true; //para se n existir p, mas chegou na folha então não se pode dizer se não é ABB, então a princípio é
}

//16. Verificar se duas árvores são identicas

bool identicas(NO* p1, NO* p2){
	bool id;
	if(p1 && p2){
		id = identicas(p1->esq, p2->esq);
		if(id){ //se dois nós forem idênticos
			if(p1->chave != p2->chave) return false; //não são idênticas  
			id = identicas(p1->dir, p2->dir);
		}
		return id;
	}
	if(p1) return false;
	if(p2) return false;	
	return true;
}

/*17. Copiar uma árvore
18. Dado dois elementos p1 e p2 não subordinados em uma ABB, retornar o primeiro ancestral em comum
19.Inserir elemento dada a posição
*/

//20. Exibir os elementos de uma árvore em ordem crescente
void exibirCrescente(NO* raiz){//o percurso em-ordem me dá os elementos em sua ordem crescente, então é o percurso ideal para resolver 
	if(raiz){
		exibirCrescente(raiz->esq);//vou tudo que dá para a esquerda primeiro
		printf("%d", raiz->chave); //visitar
		exibirCrescente(raiz->dir);//vou pegando os elementos da direita que foram sendo pulados
	}

}


int main(){

	return 0;
}