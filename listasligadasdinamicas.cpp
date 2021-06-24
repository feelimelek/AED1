/*
A lista ligada dinâmica chegou para resolver o problema da demora na hora de buscar ou as pioras das outras duas estruturas.
Não tem mais vetor (por isso não é mais estática). Não tem mais lista de disponíveis.
O que eu tenho então?
Pedaços de memória conectados entre si, isto é, cada pedaço de memória, além de possuir o próprio conteúdo (chave), possui o endereço
do próximo pedaço de memória da lista (um ponteiro, isto é, um endereço de memória e não mais uma posição de vetor).
Além disso, há um ponteiro que aponta para o primeiro elemento da lista. 
Agora, ao invés de espaços de vetores, temos NOs. Ao invés de índices, endereços de memória/ponteiros.
*/

//criando um NO

typedef struct s{ //dou inicialmente o nome s para essa variável, para poder usá-la dentro dela mesmo, entenderemos melhor a seguir
	int chave; //poderia ser um tipo registro se eu quisesse também, aqui eu coloco o que quero q tenha dentro dos espaços
	struct s* prox; //crio um ponteiro do tipo Struct s (NO) que apontará para o próximo endereço, estou chamando a própria struct
					//criada aqui, por isso precisava do s, se não, não teria nome para chamar
} NO;

//para conseguirmos criar um espaço precisamos usar a função malloc que alocará um pedaço de memória para o nosso nó, por isso
// incluimos a seguinte biblioteca

#include <malloc.h>

//criando uma lista ligada dinâmica, que na verdade será só um ponteiro apontando para o ínicio
typedef struct {
	NO* inicio;
} LISTA_DIN;

/*
Operações principais:
- Inicializar
- Imprimir
- Busca
- Excluir
- Inserir
*/

void inicializar(LISTA_DIN* l){
	l-> inicio = NULL; //ainda não há um ínicio
}

void imprimir(LISTA_DIN* l){
	NO* p = l->inicio; //auxiliar para percorrer a lista
	while(p){//enquanto p existe, ou seja, não é NULL
		printf("%d", p->chave); //imprimo a chave de p
		p = p->prox; //coloco p como o próximo da lista
	}
}

NO* busca(LISTA_DIN* l, int ch, NO** ant){ //a função deve retornar o endereço do NO encontrado. Queremos que ant aponte para o endereço de NO
	*ant = NULL; //alterando o endereço do NO referenciado por ant. Inicialmente é NULL
	NO* p = l->inicio; //vamos percorrer a lista, iniciando c o inicio;
	while(p){
		if(p->chave == ch)
			return p;
		if(p->chave > ch)
			return NULL; 	//não existe ch, pois se a chave do atual é maior que ch e a lista está ordenada, não há nada menor que essa chave na lista
		*ant = p; 
		p = p->prox; //p tornará a ser o próximo e o ant será armazenado (p antigo) antes 
	}
	return NULL;				
} 

//vamos excluir, testar se existe esse número. Se não existir, testar se excluirá no começo da lista ou no meio
bool excluir(LISTA_DIN* l, int ch){
	NO* ant;
	NO* p = busca(l, ch, &ant); //aqui se tiver ant, vai alterar na variável original, como visto na função acima
	if(!p) //p é NULL
		return false; //não existe elemento com ch na lista para excluir
	if(ant){ //não for NULL, se ant existir
		ant->prox = p->prox; //pulo p
	}
	else{
		l->inicio = p->prox;
	}
	free(p);
	return true;
}

bool inserir(LISTA_DIN* l, int ch){
	NO* ant;
	NO* novo = (NO*)malloc(sizeof(NO));
	NO* p = busca(l, ch, &ant); //se já existir, não pode incluir, se não, o ant armazenará a posição de onde deve ser incluído, se ant for null, significa que é no ínicio
	if(p)
		return false;
	novo->chave = ch; 
	if(ant){
		novo->prox = ant->prox; //conecto o novo com o proximo do anterior
		ant->prox = novo; //agora o anterior deve apontar para o novo e não mais para o no que o novo está apontando
	}
	else{ //é o ínicio
		novo->prox = l->inicio;
		l->inicio = novo;
	}
	return true;

}

bool compara(LISTA_DIN* l1, LISTA_DIN* l2){

	NO* p1 = l1->inicio;
	NO* p2 = l2-> inicio; //começaremos com dois ponteiros, cada um apontando para cada nó inicial, a partir deles percorreremos
	//se ambas forem vazias elas são idênticas
	if((!p1)&&(!p2)) return true;
	while(p1&&p2){ //enquanto os dois existirem
		if(p1->chave == p2->chave){
			p1 = p1->prox;
			p2 = p2->prox;
			continue;
		}
		else
			return false;
	}
	return true;

}

void trocarn1en2(LISTA_DIN* l){
	NO* aux = (NO*)malloc(sizeof(NO));
	if((l->inicio) && (l->inicio->prox)){ //primeiro e segundo elementos existem
		aux->chave = l->inicio->chave; 
		l->inicio->chave = l->inicio->prox->chave;
		l->inicio->prox->chave = aux->chave;
	
    	imprimir(l);
    }
    else return;
    
}

void moverpinicio(LISTA_DIN* l, int ch){
	NO* ant;
	NO* p = busca(l, ch, &ant);
	if(p == l->inicio) return;
	if(!p) return; //não há esse elemento para mover
	ant->prox = p->prox; //exclui p, onde está ch
	p->prox = l->inicio;
	l->inicio = p;
    imprimir(l);

}

NO* listaNumerica(int n){
	//comecemos de trás para frente, pois é mais fácil
	NO* resp = NULL; 
	while(n > 0){
		NO* novo = (NO*)malloc(sizeof(NO));
		novo->chave = n;
		novo->prox = resp;
		resp = novo;
		n--;
	}
	return resp;

}

int main(){
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
					//agora tenho dois ponteiros visíveis: o que aponta para onde está 10 sozinho (y)  o que aponta para onde está 20 (x e y->prox) 
	NO* ant = NULL;		//também tenho dois ponteiros ocultos: o que vai de onde está 20 para onde está 10 e o que vai até NULL (fim da lista)	
	LISTA_DIN l;
	l.inicio = y;
	imprimir(&l);
	int ch;
	scanf("\n%d", &ch);
	inserir(&l, ch);
	imprimir(&l);
	excluir(&l, ch);
	imprimir(&l);
	
	LISTA_DIN l2;
	NO* z = (NO*)malloc(sizeof(NO));
	z->chave = 10;
	l2.inicio = z;
    NO* w = (NO*)malloc(sizeof(NO));
    
	w->chave = 30;
	l2.inicio->prox = w;
	
    if(compara(&l, &l2)){
        printf("Idênticas");
    }
//    trocarn1en2(&l);	nesse código, os dois não funcionam juntos, porque se inverte fica 30 e 10, e ai na busca ele n acha 10, pois acha que está ordenado
//    moverpinicio(&l, 30);
	return 0;
}

/*
Agora que já entendemos como funcionam as listas ligadas dinâmicas, podemos procurar por mais técnicas que 
facilitem nossa vida de programadores. E se queremos simplificar algoritmos que precisam chegar no fim da lista?
E se precisamos repetir a lista várias vezes do começo ao fim? E se quero inserir um elemento no inicio de modo mais simples?
E se quero diminuir meu tempo de busca ou percorrer a mesma lista duas vezes ao mesmo tempo, uma em cada sentido?
Temos métodos para todas essas ocasiões, então vamos lá.
*/