/*
Lista ligada
Ordem lógica!= ordem física
Implementaremos em vetor por enquanto - estático
Cada elemento da lista, possui o próprio valor e uma variável que armazena a posição do próximo registro da lista
Ou seja, teremos que modificar um pouco o tipo REGISTRO usado para as listas sequenciais
*/

#include <stdio.h>
#include <stdbool.h>

//criando o tipo registro
typedef struct {
	int chave;
	int prox;
	// poderiam ter outros atributos
} REGISTRO;

/*Agora, para criarmos a lista sequencial precisamos considerar algumas coisas: 
	Como a ordem lógica não segue a ordem física, precisamos saber onde a lista inicia (variável inicio),
	bem como quais são os espaços em branco (variavel q da o inicio da lista de disponiveis).
	A lista em si, nada mais é, do que um vetor do tipo REGISTRO com um máximo de espaços delimitado por MAX
*/
#define MAX 20
typedef struct{
	REGISTRO A[MAX];
	int inicio; //inicio da lista com elementos existentes
	int dispo; //inicio da lista paralela de espaços vazios do vetor/disponíveis
} LISTA_LIG;

/*
Operações básicas em uma lista:
- Inicializar
- Imprimir
- Contar elementos
- Buscar - em lista ligada não dá para fazer busca binária
- Encontrar o último elemento
- Encontrar o n-ésimo elemento
- Excluir
- Inserir
- Devolver
- Obter
*/

void inicializar(LISTA_LIG *l){
	l-> inicio = -1; //como não há elementos/estamos inicializando, não há uma posição na qual começa a lista de registros existentes
	l-> dispo = 0; //todos os espaços são vazios então, posso seguir a ordem física para a lista de espaços disponíveis
	for(int i = 0; i < MAX; i++){
		l->A[i].prox = i + 1; //estou referenciando o próximo da lista de disponíveis, sem colocar valor na ch
	}
	l->A[MAX - 1].prox = -1; //quando eu chego no último registro da lista, não há próximo, então, o prox é -1
}

void imprimir(LISTA_LIG *l){
	int i = l->inicio; //peguei o começo da lista de registros existentes (com chave), vai ser o começo do meu laço
	while(i != -1){//enquanto não estiver no fim, eu imprimo
	printf("%d", l-> A[i].chave);
	i = l->A[i].prox; //não é ++, pois como é lista ligada e não sequencial, eu não posso assumir que depois da posição 0 vem a 1, por exemplo
	}
}

int contar(LISTA_LIG *l){
	int i = l->inicio;
	int contador = 0;
	while(i != -1){
		i = l->A[i].prox;
		contador++;
	}
	return contador;
}
/*
int buscarChave(LISTA_LIG *l, int ch){ 	//a função retorna a posição i do elemento (lembrando que não necessariamente segue a ordem física)
										//em lista ligada não rola fazer busca binária
    int i = l->inicio;
    while(i != -1){
        if(l->A[i].chave == ch)
            return i;
        else 
            i = l->A[i].prox;
    }
    return -1;
}
*/
int buscarChave(LISTA_LIG *l, int ch, int* ant){ //nesse caso, diferentemente do anterior, eu quero que me retorne a posição i e a posição do anterior (ant)
    int i = l->inicio;
    while(i != -1){
        if(l->A[i].chave == ch)
            return i;
        else {
        	*ant = i;//estou modificando o conteúdo de ant, q nesse caso é um ponteiro
            i = l->A[i].prox;
        }
    }
    return -1;
}
int ultimaPosicao(LISTA_LIG* l){
	int i = l-> inicio;
	while(i != -1){
		if(l->A[i].prox == -1)
			return i;
		else
			i = l->A[i].prox;
	}
	return -1;
}

int ultimaChave(LISTA_LIG *l){
	int i = l-> inicio;
	while(i != -1){
		if(l->A[i].prox == -1)
			return l->A[i].chave;
		i = l-> A[i].prox;
	}
	return -1;
}

int nesimaChave(LISTA_LIG *l, int n){ //a n-ésima chave, vai ser a chave de posição n-1, mas não seguindo a ordem física
	int i = l-> inicio;
	int contador = 0;
	if(n < 0 || n > contar(l))
		return -1; //não existe esse termo
	else {
	    while(contador != n - 1){
		    i = l->A[i].prox;
		    contador++;
	    }   
    }
	return l->A[i].chave; //se eu colocasse o contador, eu estaria seguindo a ordem física da memória, mas como é lista ligada, não há essa ordem
}

//Quero colocar um espaço na lista de disponíveis (o espaço do termo excluído)
void devolver(LISTA_LIG* l, int pos){ 
	l->A[pos].prox = l->dispo; //o próximo do que eu quero inserir é o que seria o primeiro da lista antes (o dispo)
	l->dispo = pos; //o primeiro da lista muda, agora é o pos
	return; //n retorna nada, pois é void, poderia não colocar nada
}

//Quero excluir o registro com a chave ch da lista, para isso preciso saber onde está a posição que quero excluir
bool excluir(LISTA_LIG* l, int ch){
	int ant = 0; //preciso saber qual é o espaço anterior do que eu quero excluir para poder ligar no que o excluído apontaria
	int pos = buscarChave(l, ch, &ant); //a função retorna a posição e armazena em ant, a posição anterior de onde está a chave
	if(pos == -1)
		return false; //não existe essa chave para excluir
	else{
	l->A[ant].prox = l->A[pos].prox; //ligo o de antes do excluído com o depois desse
	devolver(l, pos);
	return true;
	}
}

//Quero pegar um espaço da lista de espaços disponíveis
int obter(LISTA_LIG* l){ //retorna a posição do lugar tirado da lista de disponíveis para ser "usado"
	int resp = l->dispo;
	if(l->dispo > -1) //poderia ser != também
		l->dispo = l->A[l->dispo].prox; //agora, o primeiro elemento de dispo, será o segundo e o primeiro será usado para inserir 
	return resp;
}

//Quero incluir um registro com a chave ch
bool inserir(LISTA_LIG* l, int ch){
	int ant = -1;
	if(l->dispo == -1)
		return false; //não tem espaço disponível
	else{
		int pos = buscarChave(l, ch, &ant);
		if(pos > -1)
			return false; //essa chave já existe
		else{
			pos = obter(l);
			l->A[pos].chave = ch;
			if(ant > -1){ //não é o primeiro termo
				l->A[pos].prox = l->A[ant].prox;
				l->A[ant].prox = pos;
			}
			else{
				l->A[pos].prox = l->inicio;
				l->inicio = pos;
			}
			return true;
		}
    }
}



int main(){
    LISTA_LIG l;
	inicializar(&l);
	imprimir(&l);
	int ch = 0;
	int pos = 0;
    for(int i = 0; i < 4; i++){
		printf("Coloque a chave que deseja inserir:");
		scanf("%d", &ch);
		if(inserir(&l, ch)){
			imprimir(&l);
		}
	}
	printf("Coloque a chave que deseja excluir: ");
	scanf("%d", &ch);
	if(excluir(&l, ch))
		imprimir(&l);
	printf("Quantidade de elementos: \n%d\n", contar(&l));
    printf("Última chave: %d\n", ultimaChave(&l));
    printf("Chave procurada: ");
    scanf("%d", &ch);
    int ant = 0;
    printf("Posição da chave procurada: %d", buscarChave(&l, ch, &ant));
    printf("\nN-ésima chave: ");
    int n = 0;
    scanf("%d", &n);
    printf("%d", (nesimaChave(&l, n)));
    printf("Última posição: %d", (ultimaPosicao(&l)));

	return 0;
}
/*
		LISTA SEQUENCIAL X LISTA LIGADA DE IMPLEMENTAÇÃO ESTÁTICA 
busca      log(N)				N 									Piorou
Inserir/
Excluir 	N 					constante 							

*/