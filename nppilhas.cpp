/*
Seria possível colocar várias pilhas em um vetor?
Sim, seria. 
Apresentamos agora: Pilhas estáticas em vetor compartilhado.
Primeiro vimos a plhas dupla, mas como elas são um exemplo simplificado de um número maior de pilhas no mesmo vetor, veremos 
a estrutura geral para NP pilhas (NP = número de pilhas).
A diferença é que na de pilha dupla á dois topos: topo 1 e topo 2, enquanto na genérica há um vetor para os topos e um vetor para
as bases.
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 10
#define NP 5 //número de pilhas é 5
//As NP pilhas vão de 0 a NP-1, de modo que fica uma NP a mais ficticia
typedef struct{
	int A[MAX]; //o vetor compartilhado
	int topo[NP+1]; //coloco uma casinha a mais para começar do 1 e facilitar a vida de programadora, a primeira casa do vetor
					//sempre ficará vazia. É um gasto de memória, mas facilita a programação.
	int base[NP+1]; //as bases representam uma casa anterior ao início da pilha
} NPPILHAS;

//BASE NÃO É PARTE DA PILHA, e pode ser o último elemento da pilha anterior.

void inicializar(NPPILHAS* p){ 			//para decidir onde começar as pilhas pegamos o MAX e dividimos pelo número de pilhas
	int i;
	for(i = 0; i <= NP; i++) {			//colocamos o =, pois criamos uma NP a mais fictícia para facilitar a programação
		p->topo[i] = (i * (MAX/NP))-1; 	//inicializo com uma casa antes, coincidindo com a base
		p->base[i] = p->topo[i];		// = i * (MAX/NP)-1 
	}
}
//Pilha vazia: base = topo
int contarK(NPPILHAS* p, int k){ 	//contar a quantidade de elementos de uma pilha K
	if(k < 0 || k > NP-1) return -1;//não existe essa pilha
	return p->topo[k] - p->base[k]; //como a base fica uma posição antes 
}

bool pilhaKcheia(NPPILHAS* p, int k){ 				//quero ver se uma pilha determinada está cheia
	return (p->topo[k] == p->base[k+1]); 	//a ultima posição é a base da próxima e não há risco de estourar porque á última pilha
											//é fictícia
}

void deslocar1Direita(NPPILHAS* p, int k){ 	//quero deslocar um pilha para a direita
	if(k < 1 || k > NP-1) return;			//não se desloca a primeira
	if(pilhaKcheia(p, k)) return; //não tem espaço dps para deslocar, pensando que não podemos alterar as outras pilhas
	for(int i = p->topo[k]+ 1; i > p->base[k]; i--){//vou deslocar do último para o primeiro, não vai estourar por causa da última pilha imaginária
		p->A[i] = p->A[i-1]; //puxo os elementos
	}
	p->topo[k] = p->topo[k] + 1; //desloco o índice do topo para onde o topo está agora
	p->base[k] = p->base[k] + 1; //o mesmo para a base
}

void deslocar1Esquerda(NPPILHAS* p, int k){
	if(k < 1 || k > NP-1) return;//não queremos deslocar as extremidades
	if(pilhaKcheia(p, k-1)) return;//se a pilha anterior estiver cheia, isto é, o topo é o mesmo que a base da próxima, então não dá para
							//deslocar
	for(int i = p->base[k]; i < p->topo[k]; i++){
		p->A[i] = p->A[i+1]; //pego os valores das posições seguintes da direita
	}
	p->topo[k] = p->topo[k] - 1;
	p->base[k] = p->base[k] - 1;
}

bool pushK(NPPILHAS* p, int k, int ch){ //queremos adicionar um elemento em uma das pilhas, lembrando as propriedades das pilhas!
	if(k < 0 || k >NP-1) return false;	//não existe essa pilha
	if(pilhaKcheia(p, k)) { 			//eu posso tentar ajustar as pilhas se a pilha em questão estiver lotada
		for(int i = NP-1; i > k; i--){	 	//i > k, pois só queremos deslocar aquelas que vem depois dela, poderíamos ao invés de começar
										//pela última, checar se já não dá para deslocar a próxima, por questões de eficiência
			deslocar1Direita(p, i); //todos os testes/tratamentos necessários já estão inclusos nessa função 
		}
		if(pilhaKcheia(p, k)){ //se continuar cheia, quer dizer que nenhuma outra foi deslocada então ainda não há espaço para o push
			deslocar1Esquerda(p, k);
		}
		if(pilhaKcheia(p, k)) return false; //não há espaço mesmo
	} //uma vez conseguido o espaço, vamos adicionar
	p->topo[k] = p->topo[k] + 1; //desloco o índice do topo para a direita
	p->A[p->topo[k]] = ch; //coloco o valor dentro
	return true; 


} 

int popK(NPPILHAS* p, int k){ //retorna o valor do elemento que foi removido
	if(k < 0 || k > NP-1) return false; //não existe essa pilha
	if(p->topo[k] != p->base[k]){ //se a lista não tiver vazia, tem o que retirar
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
			if(A[aux] == ch)
				return i;
			else 
				aux--;
		}
	}
	return -1;
}

void exibirKpilhas(NPPILHAS* p){
	int aux = -1;
	for(int i = 0; i <= NP-1; i++){
		printf("Pilha %d", i);
		aux = p->topo[i];
		while(aux!=p->base[i]){
			printf("%d", p->A[base]);
		}
	}
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
   		printf("O Topo é: %d", p.topo[2]);
   		printf("\n");
    }
    for(int i = 0; i < 2; i++){
        pushK(&p, 3, i);
        imprimir(&p);
   		printf("O Topo é: %d", p.topo[3]);
   		printf("\n");
    
    }
    
    popK(&p, 3);
    imprimir(&p);
	return 0;
}