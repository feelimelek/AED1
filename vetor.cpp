#include <stdio.h>
using namespace std;

// em C precisamos inicializar o vetor ou variável, caso contrário, ele fica com lixo de memória, para isso criamos a função zerar
void zerar (int *v, int n){
	for (int i = 0; i < n; i++){
	v[i] = 0;
	}
}

//a é um ponteiro, isto é, aponta para a variável a e armazena endereço de memória em si.

void incremento (int *a){ //Para definir colocamos * antes do nome da variável.
	*a = *a + 1;
	//Para acessar o conteúdo dessa variável e alterá-lo devemos colocar * antes. Para alterar o endereço, colocamos só o nome da variável, sem o *
} 


int main (){
	int n = 0;
	scanf ("%d", &n);
	int v[n];
	zerar (v, n);
	incremento (&v[n-1]);

}
