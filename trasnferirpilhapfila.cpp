/*
Seria poss�vel colocar v�rias pilhas em um vetor?
Sim, seria. 
Apresentamos agora: Pilhas est�ticas em vetor compartilhado.
Primeiro vimos a plhas dupla, mas como elas s�o um exemplo simplificado de um n�mero maior de pilhas no mesmo vetor, veremos 
a estrutura geral para NP pilhas (NP = n�mero de pilhas).
A diferen�a � que na de pilha dupla � dois topos: topo 1 e topo 2, enquanto na gen�rica h� um vetor para os topos e um vetor para
as bases.
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 10
#define NP 5 
//As NP pilhas v�o de 0 a NP-1, de modo que fica uma NP a mais ficticia
typedef struct{
	int A[MAX]; //o vetor compartilhado
	int topo[NP+1]; //coloco uma casinha a mais para come�ar do 1 e facilitar a vida de programadora, a primeira casa do vetor
					//sempre ficar� vazia. � um gasto de mem�ria, mas facilita a programa��o.
	int base[NP+1]; //as bases representam uma casa anterior ao in�cio da pilha
} NPPILHAS;

//BASE N�O � PARTE DA PILHA, e pode ser o �ltimo elemento da pilha anterior.

void inicializar(NPPILHAS* p){ 			//para decidir onde come�ar as pilhas pegamos o MAX e dividimos pelo n�mer de pilhas
	int i;
	for(i = 0; i <= NP; i++) {			//colocamos o =, pois criamos uma NP a mais fict�cia para facilitar a programa��o
		p->topo[i] = (i * (MAX/NP))-1; 	//inicializo com uma casa antes, coincidindo com a base
		p->base[i] = p->topo[i];		// = i * (MAX/NP)-1 
	}
}
//Pilha vazia: base = topo
int contarK(NPPILHAS* p, int k){ 	//contar a quantidade de elementos de uma pilha K
	if(k < 0 || k > NP-1) return -1;//n�o existe essa pilha
	return p->topo[k] - p->base[k]; //como a base fica uma posi��o antes 
}

bool pilhaKcheia(NPPILHAS* p, int k){ 				//quero ver se uma pilha determinada est� cheia
	return (p->topo[k] == p->base[k+1]); 	//a ultima posi��o � a base da pr�xima e n�o h� risco de estourar porque � �ltima pilha
											//� fict�cia
}

void deslocar1Direita(NPPILHAS* p, int k){ 	//quero deslocar um pilha para a direita
	if(k < 1 || k > NP-1) return;			//n�o se desloca a primeira
	if(pilhaKcheia(p, k)) return; //n�o tem espa�o dps para deslocar, pensando que n�o podemos alterar as outras pilhas
	for(int i = p->topo[k]+ 1; i > p->base[k]; i--){//vou deslocar do �ltimo para o primeiro, n�o vai estourar por causa da �ltima pilha imagin�ria
		p->A[i] = p->A[i-1]; //puxo os elementos
	}
	p->topo[k] = p->topo[k] + 1; //desloco o �ndice do topo para onde o topo est� agora
	p->base[k] = p->base[k] + 1; //o mesmo para a base
}

void deslocar1Esquerda(NPPILHAS* p, int k){
	if(k < 1 || k > NP-1) return;//n�o queremos deslocar as extremidades
	if(pilhaKcheia(p, k-1)) return;//se a pilha anterior estiver cheia, isto �, o topo � o mesmo que a base da pr�xima, ent�o n�o d� para
							//deslocar
	for(int i = p->base[k]; i < p->topo[k]; i++){
		p->A[i] = p->A[i+1]; //pego os valores das posi��es seguintes da direita
	}
	p->topo[k] = p->topo[k] - 1;
	p->base[k] = p->base[k] - 1;
}

bool pushK(NPPILHAS* p, int k, int ch){ //queremos adicionar um elemento em uma das pilhas, lembrando as propriedades das pilhas!
	if(k < 0 || k >NP-1) return false;	//n�o existe essa pilha
	if(pilhaKcheia(p, k)) { 			//eu posso tentar ajustar as pilhas se a pilha em quest�o estiver lotada
		for(int i = NP-1; i > k; i--){	 	//i > k, pois s� queremos deslocar aquelas que vem depois dela, poder�amos ao inv�s de come�ar
										//pela �ltima, checar se j� n�o d� para deslocar a pr�xima, por quest�es de efici�ncia
			deslocar1Direita(p, i); //todos os testes/tratamentos necess�rios j� est�o inclusos nessa fun��o 
		}
		if(pilhaKcheia(p, k)){ //se continuar cheia, quer dizer que nenhuma outra foi deslocada ent�o ainda n�o h� espa�o para o push
			deslocar1Esquerda(p, k);
		}
		if(pilhaKcheia(p, k)) return false; //n�o h� espa�o mesmo
	} //uma vez conseguido o espa�o, vamos adicionar
	p->topo[k] = p->topo[k] + 1; //desloco o �ndice do topo para a direita
	p->A[p->topo[k]] = ch; //coloco o valor dentro
	return true; 


} 

int popK(NPPILHAS* p, int k){ //retorna o valor do elemento que foi removido
	if(k < 0 || k > NP-1) return false; //n�o existe essa pilha
	if(p->topo[k] != p->base[k]){ //se a lista n�o tiver vazia, tem o que retirar
		p->topo[k] = p->topo[k] - 1;
		return true;
	}
	return false;
}

void imprimir(NPPILHAS* p){
	for(int i = 0; i < MAX; i ++)
		printf(" %d", p->A[i]);
}

int buscarPilhacomElemento(NPPILHAS* p, int ch){
	int aux = -1;
	for(int i = 0; i <= NP-1; i++){
		aux = p->topo[i];
		while(aux!=p->base[i]){
			if(p->A[aux] == ch)
				return i;
			else 
				aux--;
		}
	}
	return -1;
}

int main(){
	NPPILHAS p;
	inicializar(&p);
	for(int i = 0; i < MAX; i++){
	    p.A[i] = -1;
	}
	for(int i = 0; i < 4; i++){
        pushK(&p, 2, i);
   		imprimir(&p);
   		printf("O Topo �: %d", p.topo[2]);
   		printf("\n");
    }
    for(int i = 0; i < 2; i++){
        pushK(&p, 3, i);
        imprimir(&p);
   		printf("O Topo �: %d", p.topo[3]);
   		printf("\n");
    
    }
    
    popK(&p, 3);
    imprimir(&p);
	return 0;
}
