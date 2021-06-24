#include<stdio.h>

#define MAX 20
// x é o elemento a ser encontrado, n tamanho do vetor, v é vetor
int onde (int x, int n, int * v);

void imprimir(int* v, int n){
    for(int i = 0; i < n; i++){
    printf("%d", v[i]);
    }
}

int onde (int x, int n, int * v){ 
	static int pos = 0; //para percorrer o vetor criamos essa variável auxiliar, como é static ela só lê a declaração uma única vez
	if(n == 0) //não há posições no vetor
		return -1;
	if(pos >= n)
		return -1; //não encontrei nada
	else{
		if(v[pos] == x) //encontrei
			return pos;
		else {
			pos++; //vamos para a próxima posição
			return onde(x, n, v);
		}
	}

}

int main(){
	int v[MAX];
	int n;
	printf("Qual é o valor de n?");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}	
	int x = 0;
	printf("Qual é o valor de x?");
	scanf("%d", &x);
	
	printf("%d", onde(x, n, v));
return 0;

}