#include <iostream>
#include <cstdlib>
using namespace std;


void inicializarVetorTeste(int A[], int n){
	for(int i = 0; i < n; i++){
		A[i] = rand() %10; //preencho o vetor com um valor aleatorio entre 1 e 10
	}
}

void exibir(int A[], int n){
	for (int i = 0; i < n; i++){
		cout << A[i] << " ";
	}

}
//Para fazer o insertion dividiremos o vetor em duas partes: a ordenada(esquerda) e a desordenada(direita)
void insertion(int A[], int n){ //A é o vetor a ser ordenado e n é o comprimento de A, com o vetor começando em 1
	int i = 0;
	int chave = 0;
	for (int j = 1; j < n; j++){
		chave = A[j]; //primeiro valor da parte desordenada
		for(i = j-1; i >= 0 && A[i] > chave; i--){ 	// i é o fim da parte ordenada, se parar quer dizer que i é 0 ou que i é
														//um espaço anterior ao lugar onde a chave deverá ser adicionada
			A[i+1] = A[i]; //transferi para o próximo espaço
		}
		A[i+1] = chave;
		cout << "\n";
		exibir(A, n);
	} 
}

int main(){
	int A[10];
	int n = 10;
	inicializarVetorTeste(A, n);
	exibir(A, n);
	cout << "\n";
	insertion(A, n);
	exibir(A, n);

}#include <iostream>
#include <cstdlib>
using namespace std;


void inicializarVetorTeste(int A[], int n){
	for(int i = 0; i < n; i++){
		A[i] = rand() %10; //preencho o vetor com um valor aleatorio entre 1 e 10
	}
}

void exibir(int A[], int n){
	for (int i = 0; i < n; i++){
		cout << A[i] << " ";
	}

}
//Para fazer o insertion dividiremos o vetor em duas partes: a ordenada(esquerda) e a desordenada(direita)
void insertion(int A[], int n){ //A é o vetor a ser ordenado e n é o comprimento de A, com o vetor começando em 1
	int i = 0;
	int chave = 0;
	for (int j = 1; j < n; j++){
		chave = A[j]; //primeiro valor da parte desordenada
		for(i = j-1; i >= 0 && A[i] > chave; i--){ 	// i é o fim da parte ordenada, se parar quer dizer que i é 0 ou que i é
														//um espaço anterior ao lugar onde a chave deverá ser adicionada
			A[i+1] = A[i]; //transferi para o próximo espaço
		}
		A[i+1] = chave;
		cout << "\n";
		exibir(A, n);
	} 
}

int main(){
	int A[10];
	int n = 10;
	inicializarVetorTeste(A, n);
	exibir(A, n);
	cout << "\n";
	insertion(A, n);
	exibir(A, n);

}