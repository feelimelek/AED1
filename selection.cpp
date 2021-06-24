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
//Para fazer o selection percorreremos o vetor e a cada posição acharemos o menor elemento fora os da esquerda no vetor para substituir
void selection(int A[], int n){ //A é o vetor a ser ordenado e n é o comprimento de A, com o vetor começando em 1
	for (int j = 0; j < n-1; j++){
		int menor = j;
		for (int i = j+1; i < n; i++){
			if(A[i] < A[menor]){
				menor = i; //encontrei o menor
			}
		} 
		if(A[j] != A[menor]){
		    int temp = A[j];
		    A[j] = A[menor];
		    A[menor] = temp;
		}
	}
}
int main(){
	int A[10];
	int n = 10;
	inicializarVetorTeste(A, n);
	exibir(A, n);
	cout << "\n";
	selection(A, n);
	exibir(A, n);

}