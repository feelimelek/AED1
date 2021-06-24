/*
A lista ligada dinâmica com sentinela chegou com um objetivo claro: reduzir o número de comparações (if) na função de busca.
Em que ela consiste? Em um elemento chamado de sentinela que fica depois do último elemento da lista, isto é o p->prox (sendo p
o último elemento), é sent
*/

#include <stdio.h>

typedef struct{
	int chave;
	struct s* prox;
} NO;

typedef struct{
	NO* inicio;
	NO* sent; //na hora de definir a lista sentinela, já há um sent, não importa a chave da sentinela, pois ela não é considerada parte da lista
} LISTA_SENT

void inicializar(LISTA_SENT* l){
	l-> sent = (NO*)malloc(sizeof(NO));
	l-> inicio = l->sent; 	//assim como na lista ligada dinamica simples ao inicializar atribuímos NULL ao l->inicio, 
	 						//no caso da lista com sentinela atribuímos a própria sentinela ao início, já que ela não
							//faz parte da lista em si (é como se fosse um "NULL" alocado)
}

void imprimir(LISTA_SENT* l){
	NO* p = l->inicio; //usaremos esse ponteiro para percorrer a lista
	while(p != l->sent){ //enquanto não for a sentinela, a gente imprime, chegando nela, não imprime mais
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
	} else{ //pode ser o inicio da lista ou o inicio da lista inicializada, que seria a sentinela
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
	free(p);
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