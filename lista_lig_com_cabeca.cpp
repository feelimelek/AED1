/*
A lista ligada dinâmica com cabeça e circular facilita a inserção no início da lista

(FALTA  CORRIGIR PARA CAB E NÃO SENTINELA)
*/

#include <stdio.h>

typedef struct{
	int chave;
	struct s* prox;
} NO;

typedef struct{
	NO* cab; 
} LISTA_CAB;

void inicializar(LISTA_CAB* l){
	NO* cab = (NO*)malloc(sizeof(NO));
	l-> cab->prox = l->cab; //crio a circularidade
}

void imprimir(LISTA_CAB* l){
	NO* p = l->cab->prox; //começo da lista
		 //usaremos esse ponteiro para percorrer a lista
	while(p != l->cab){ //enquanto não for a cabeça, a gente imprime, chegando nela, não imprime mais
		printf("%d", p->chave);
		p = p->prox; //o ponteiro auxiliar anda para o próximo
	}
}

NO* buscanord(LISTA_SENT* l, int ch, NO** ant){ //na função busca com sentinela, inserimos a chave procurada na sentinela e percorremos
	*ant = NULL;
	l->sent->chave = ch;
	NO* p = l->inicio; //auxiliar que vai andar
	while(p->chave != ch){ //aqui já começamos a ver os benefícios da sentinela
		*ant = p; //armazeno o valor, para caso seja retornado
		p = p->prox;
	} //quando p->chave for igual ao ch, teremos armazenado tanto a posição de p, quanto a de seu anterior
	if(p == l->sent) //se o caractere encontrado foi aquele adicionado na sentinela, então ele não foi encontrado na lista
		return NULL;
	else 
		return p;
	}

NO* busca(LISTA_SENT* l, int ch, NO** ant){
	*ant = NULL;
	l->sent->chave = ch;
	NO* p = l->inicio;
	while(p->chave < ch) { // vai sair do loop quando p->chave >=ch
		*ant = p;
		p = p->prox;
	}

	if(p == l->sent)
		return NULL; //não encontrou
	else if(p->chave > ch)
		return NULL; //salva no ant onde deve adicionar o próximo
	else //p->chave == ch
		return p; 
}

bool inserir(LISTA_SENT* l, int ch){
	NO* ant;
	NO* p = busca(l, ch, &ant);
	NO* novo = (NO*)malloc(sizeof(NO));
	novo->chave = ch;
	if(p)
		return false;//já existe, não rola adicionar igual
	if(ant){
	novo->prox = ant->prox;
	ant->prox = novo;
	} else{ //pode ser o inicio da lista ou a o inicio da lista inicializada, que seria a sentinela
		if(l->inicio == l->sent){
			novo->prox = l->sent;
			l->inicio = novo;
		} 
		else{
			novo->prox = l->inicio;
			l->inicio = novo;
		}
	}
	return true;
}

bool excluir(LISTA_SENT* l, int ch){
	NO* ant;
	NO* p = busca(l, ch, &ant);
	if(!p)
		return false;//não há elemento par excluir
	if(ant){
		ant->prox = p->prox; //pulou
	}
	else{
		l->inicio = p->prox;

	}
	return true;

}

NO* ultimo(LISTA_SENT* l){
	NO* p = l->inicio;
	while(p!=l->sent){
		if(p->prox == l->sent)
			return p;
		p = p->prox;
	}
	return NULL;
}

bool moverchparafimdalista(LISTA_SENT* l, int ch){
	NO* ant;
	NO* p = busca(l, ch, &ant);
	if(!p)
		return false; //não há essa chave para mover
	excluir(l, ch);
	p->prox = l->sent;
	NO* ultimo = ultimo(l);
	ulimo->prox = p;
	return true;
}

int main(){
	LISTA_SENT l;
	inicializar(&l);

	int ant;

}