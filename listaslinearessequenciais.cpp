/*
Listas lineares são aquelas cujos elementos possuem sempre um antecessor, com exceção do primeiro, e sempre um sucessor, 
com exceção do último.
Listas lineares sequenciais são aquelas na qual a ordem lógica coincide com a ordem física dos elementos, isto é, os elementos
seguem a ordem da memória.
Na prática estamos falando de vetores.
Para exemplificar, faremos uma lista de registros, que terão minimamente uma chave, essa chave é uma mão na roda em várias situações,
é por ela que manipulamos as informações 
*/
#include <stdio.h>
#include <stdbool.h>

						//definindo o tipo registro
typedef struct{
	int chave;
						//aqui poderiam ser adicionados outros atributos como nomes, datas etc
} REGISTRO; 			// é uma boa prática colocar o novo tipo criado em letra maiúscula

						//agora, criaremos a lista linear sequencial dos registros
#define MAX 1000		//antes, atribuo 1000 a variável MAX que será utilizada várias vezes
typedef struct{			
	REGISTRO A[MAX]; 	//crio um vetor do tipo registro, ou seja, em cada espaço do vetor há um registro, o espaço é limitado a MAX (1000)
	int nroElem; 		//em c não há uma função que dê o tamanho do vetor ou de quanto está preenchido, essa variável armazena a quantidade
						// de elementos em um vetor (no caso, os elementos são registros)
} LISTA_SEQ; 			//criei o tipo lista linear sequencial

/*
O que eu posso fazer com uma lista?
Inicializar
Buscar - é pré-requisito das duas seguintes e é essencial para a eficiência do algoritmo
Adicionar registro/anexar
Excluir registro
Imprimir
Ordenar
Duplicar
*/
void inicializar(LISTA_SEQ *l){
	l -> nroElem = 0; 	//defino que não há nenhum elemento
}

/*
Para adicionar um registro preciso saber se ele já não existe, pois não podem existir dois registros com mesma chave, a função que
verificará isso retornará a posicao da chave se existir ou -1 se não existir. Será a função busca
 */

/* Busca Sequencial - pior caso: N comparações
int busca(LISTA_SEQ *l, int ch){ // busca sequencial
	for (int i = 0; i < l -> nroElem; i++){
		if(l -> A[i].chave == ch) //quando estamos passando por referência usamos ->, quando não é .
		return i; 
	}
	return -1;
}
*/

int busca(LISTA_SEQ *l, int ch){ // busca binária - pior caso ln(N)
	int inicio = 0;
	int fim = l->nroElem-1;
	int meio = 0;
	if((inicio == fim) && (l->A[inicio].chave == ch))
	   return inicio;
	else{
    	while(inicio < fim){
    	    meio = (inicio + fim)/2;
    	    if(l->A[meio].chave == ch)
    			return meio;
    		else if(l->A[meio].chave < ch)
    			inicio = meio + 1; //se eu colocasse só meio, estaria considerando de novo o meio, mas já testei no primeiro if se é ou não
    		else
    			fim = meio - 1;
    	}
	}
	return -1;
}

/*
Considerações importantes a serem analisadas antes de se escolher um algoritmo:
- qual é o pior caso? ou aquele que poderia dar erro, pois difere do padrão geral. O seu algoritmo o resolve?
- o algoritmo é o mais eficiente do que poderia ser? há mais "fors" do que poderia ter?
Vejamos no caso da busca...
- o pior caso seria se o elemento não existisse, pois para chegar nessa conclusão, teria que fazer  nroElem comparações
- em termos de eficiência, isso não é bom, pois deixa o programa mais devagar. 
Uma alternativa, no caso da lista estar ordenada, seria fazer a busca binária, que reduziria em muito as comparãções.
No nosso exemplo, a lista não está ordenada, então seguimos com a busca sequencial.
Voltemos ao exercício.
Se queremos adicionar um registro no final da lista, precisamos, além de verificar se ele já não existe, ver se tem espaço para ele
*/

bool listaCheia(LISTA_SEQ *l){
	if (l -> nroElem >= MAX) //coloca-se o > no caso de ocorrer um bug, mas nunca vai chegar a ser > / QUE TIPO DE BUG?
		return true;
	else 
		return false;
}

//agora já temos tudo para poder anexar
bool anexar(LISTA_SEQ *l, int ch){
	if(listaCheia(l))
		return false; 				// não é possível anexar, pois a lista está cheia
	else if (busca(l, ch) == -1) { 	// se já não existir essa chave para registro
									// POR QUE AQUI NÃO PRECISA COLOCAR &? PORQUE ESTÁ DENTRO DA FUNÇÃO COM PARÂMETRO *l,É ENDEREÇO DE MEMÓRIA
		l->A[l->nroElem].chave = ch;
		l->nroElem ++;
		return true;				
	}  else
	return false;					// não é possível anexar, pois a chave já existe
}

//e se eu quiser inserir um elemento em i? Preciso saber, previamente, se está cheio, se não existe a mesma chave e se tem que mover os outros
bool incluir_i(LISTA_SEQ *l, int ch, int i){
	if(listaCheia(l))
		return false;
	if(busca(l, ch) != -1)
		return false;
	if(i < 0 || i > l->nroElem-1)
	    return false;
	else {
		for(int x = l->nroElem; x > i; x--){
			l->A[x] = l->A[x-1];
		}
		l->A[i].chave = ch;
		l->nroElem ++;
		return true;
	}	
}

//e se quero descobrir em que posição eu posso incluir de modo que a lista fique ordenada, considerando que ela já estava
int procurar_i(LISTA_SEQ *l, int ch){
	if(ch < l->A[0].chave) //se for menor que qualquer valor do vetor, deverá ser incluído na posição 0
		return 0; 
	else if(ch > l->A[l->nroElem-1].chave && (l->nroElem!= MAX))//se for maior que qualquer valor do vetor, será incluído na última posição						
		return l->nroElem; 
	else if (busca(l, ch) != -1)
		return -1; //não quero chaves iguais na lista
	else{
		int inicio = 0;
		int fim = l-> nroElem; 	//como, possivelmente, vou mover tudo, preciso contar a partir do nroElem 
								//(1 valor a mais do que a última posição com registros) 
		int meio = (inicio + fim)/2;
		while(inicio <= fim){
			if(l->A[meio].chave > ch){
				if(l->A[meio-1].chave < ch)
					return meio;
				else
					fim = meio; 
			}
			else {
				if (l->A[meio+1].chave > ch)
					return meio+1;
				else 
					inicio = meio;
			}
		}
	}
	return -1;
}
 
//e excluir? como faz? Em c não dá para simplismente apagar um elemento. Para isso, devemos sobrepor os elementos
bool excluir(LISTA_SEQ *l, int ch){
    int pos = busca(l, ch);//para saber a posição do elemento que quero excluir
    if(pos == -1) //significa que não há uma posição na qual o registro tem chave ch
        return false;
    else{
        for(int i = pos; i < l-> nroElem - 1; i++){ //devemos colocar - 1 se não acessaremos uma posição inválida
            l -> A[i] = l -> A[i + 1];
         }
    	l -> nroElem --;
        return true;
    }
        
}

bool exibir(LISTA_SEQ *l){
	for(int i = 0; i < l -> nroElem; i++){
		printf("%d", l -> A[i].chave);
	}
}

int main(){
	LISTA_SEQ l;
	inicializar(&l);
	int ch;
	printf("%s", "insira a chave dos 3 primeiros registros:");
	l.nroElem = 4;
	for(int i = 0; i < l.nroElem; i++){
		scanf("%d", &l.A[i].chave);
	}
	exibir(&l);
	printf("%s", "insira a chave a ser anexada:");
	scanf("%i", &ch);
	if(anexar(&l, ch)){
	 exibir(&l);  
	}
	printf("%s", "insira a chave a ser incluída:");
	scanf("%d", &ch);
	if(incluir_i(&l, ch, procurar_i(&l, ch)))
	    exibir(&l);
	return 0;
}
/*Listas Sequenciais
Tipo de algoritmo        Pior Caso
Busca 						lg(N)
Inserção/exclusão 			(N-1) (deslocamento)
Quando usamos as listas sequenciais, dependendo do problema, se aumentamos o programa, o algoritmo pode ficar lento.
Para isso, temos um diferente tipo de lista
*/