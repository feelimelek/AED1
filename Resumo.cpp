#include <stdio.h>
using namespace std;

// em C precisamos inicializar o vetor ou variável, caso contrário, ele fica com lixo de memória
void zerar (int *v, int n){
	for (int i = 0; i < n; i++){
	v[i] = 0;
	}
}

void incremento (int *a){
	*a = *a + 1;
} // por que foi feita essa função?

//criando o tipo ALUNO


int main (){
	int n = 0;
	scanf ("%d", &n);
	int v[n];
	zerar (v, n);
	incremento (&v[n-1]);
}
