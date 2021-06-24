/*
Listas lineares s�o aquelas cujos elementos possuem sempre um antecessor, com exce��o do primeiro, e sempre um sucessor, 
com exce��o do �ltimo.
Listas lineares sequenciais s�o aquelas na qual a ordem l�gica coincide com a ordem f�sica dos elementos, isto �, os elementos
seguem a ordem da mem�ria.
Na pr�tica estamos falando de vetores.
Para exemplificar, faremos uma lista de registros, que ter�o minimamente uma chave, essa chave � uma m�o na roda em v�rias situa��es,
� por ela que manipulamos as informa��es 
*/
#include <stdio.h>
#include <stdbool.h>

						//definindo o tipo registro
typedef struct{
	int chave;
						//aqui poderiam ser adicionados outros atributos como nomes, datas etc
} REGISTRO; 			// � uma boa pr�tica colocar o novo tipo criado em letra mai�scula

						//agora, criaremos a lista linear sequencial dos registros
#define MAX 1000		//antes, atribuo 1000 a vari�vel MAX que ser� utilizada v�rias vezes
typedef struct{			
	REGISTRO A[MAX]; 	//crio um vetor do tipo registro, ou seja, em cada espa�o do vetor h� um registro, o espa�o � limitado a MAX (1000)
	int nroElem; 		//em c n�o h� uma fun��o que d� o tamanho do vetor ou de quanto est� preenchido, essa vari�vel armazena a quantidade
						// de elementos em um vetor (no caso, os elementos s�o registros)
} LISTA_SEQ; 			//criei o tipo lista linear sequencial

/*
O que eu posso fazer com uma lista?
Inicializar
Buscar - � pr�-requisito das duas seguintes e � essencial para a efici�ncia do algoritmo
Adicionar registro/anexar
Excluir registro
Imprimir
Ordenar
Duplicar
*/
void inicializar(LISTA_SEQ *l){
	l -> nroElem = 0; 	//defino que n�o h� nenhum elemento
}

/*
Para adicionar um registro preciso saber se ele j� n�o existe, pois n�o podem existir dois registros com mesma chave, a fun��o que
verificar� isso retornar� a posicao da chave se existir ou -1 se n�o existir. Ser� a fun��o busca
 */
int busca(LISTA_SEQ *l, int ch){ // busca sequencial
	for (int i = 0; i < l -> nroElem; i++){
		if(l -> A[i].chave == ch) //quando estamos passando por refer�ncia usamos ->, quando n�o � .
		return i; 
	}
	return -1;
}

/*
Considera��es importantes a serem analisadas antes de se escolher um algoritmo:
- qual � o pior caso? ou aquele que poderia dar erro, pois difere do padr�o geral. O seu algoritmo o resolve?
- o algoritmo � o mais eficiente do que poderia ser? h� mais "fors" do que poderia ter?
Vejamos no caso da busca...
- o pior caso seria se o elemento n�o existisse, pois para chegar nessa conclus�o, teria que fazer  nroElem compara��es
- em termos de efici�ncia, isso n�o � bom, pois deixa o programa mais devagar. 
Uma alternativa, no caso da lista estar ordenada, seria fazer a busca bin�ria, que reduziria em muito as compar���es.
No nosso exemplo, a lista n�o est� ordenada, ent�o seguimos com a busca sequencial.
Voltemos ao exerc�cio.
Se queremos adicionar um registro no final da lista, precisamos, al�m de verificar se ele j� n�o existe, ver se tem espa�o para ele
*/

bool listaCheia(LISTA_SEQ *l){
	if (l -> nroElem >= MAX) //coloca-se o > no caso de ocorrer um bug, mas nunca vai chegar a ser > / QUE TIPO DE BUG?
		return true;
	else 
		return false;
}

//agora j� temos tudo para poder anexar
bool anexar(LISTA_SEQ *l, int ch){
	if(listaCheia(l))
		return false; 				// n�o � poss�vel anexar, pois a lista est� cheia
	else if (busca(l, ch) == -1) { 	// POR QUE AQUI N�O PRECISA COLOCAR &? PORQUE EST� DENTRO DA FUN��O COM PAR�METRO *l,� ENDERE�O DE MEM�RIA
		l->A[l->nroElem].chave = ch;
		l->nroElem ++;
		return true;				 // n�o � poss�vel anexar, pois a chave j� existe
	} 
}

//e se eu quiser inserir um elemento em i? Preciso saber, previamente, se est� cheio, se n�o existe a mesma chave e se tem que mover os outros
bool incluiri(LISTA_SEQ *l, int ch, int i){
	if(listaCheia(l))
		return false;
	if(busca(l, ch) != -1)
		return false;
	if(i == l -> nroElem - 1){ //�ltimo lugar
		l -> A[i].chave = ch;
		l-> nroElem ++;
		return true;
	}
	else {
		REGISTRO aux1, aux2;
		for(int x = i; x < l -> nroElem - 1; x++){
			if(x == i){
				aux1 = l -> A[x+1];
				l-> A[x+1] = l-> A[x];
				l-> A[x].chave = ch;
				continue;
			}
			else{
				aux2 = l-> A[x+1];
				l-> A[x+1] = l-> A[x];
				l-> A[x] = aux1;
				aux1 = l-> A[x+1];
			}
		}
		l-> nroElem ++;
		return true;
	}
	
}
//e se quero descobrir em que posi��o eu posso incluir de modo que a lista fique ordenada, considerando que ela j� estava
int procurar_i(LISTA_SEQ *l, int ch){
	if(ch < l->A[0].chave)
		return 0; //se for menor que qualquer valor do vetor, dever� ser inclu�do na posi��o 0

	else if(ch > l->A[l->nroElem-1].chave && (l->nroElem!= MAX))	//se for maior que qualquer valor do vetor, ser� inclu�do na �ltima posi��o			
		return l->nroElem;
	else if (busca(l, ch) != -1)
		return -1;
	else{
		int inicio = 0;
		int fim = l-> nroElem;
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
}



//e excluir? como faz? Em c n�o d� para simplismente apagar um elemento. Para isso, devemos sobrepor os elementos
bool excluir(LISTA_SEQ *l, int ch){
    int pos = busca(l, ch);//para saber a posi��o que quero excluir
    if(pos == -1) //significa que n�o uma posi��o na qual o registro tem chave chave
        return false;
    else{
        for(int i = pos; i < l-> nroElem - 1; i++){ //devemos colocar - 1 se n�o acessaremos uma posi��o inv�lida
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
	int i;
	printf("%s", "insira a chave a ser encontrada:");
	scanf("%d", &ch);
	if(incluiri(&l, ch, procurar_i(&l, ch)))
	    exibir(&l);
	
	return 0; //n�o precisa em c?
}
