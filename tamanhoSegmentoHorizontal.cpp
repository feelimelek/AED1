#include<stdio.h>

#define MAX 20

int tamanhoSegmentoHorizontal (int n, int * v);

//n é tamanho e v é vetor
int tamanhoSegmentoHorizontal(int n, int * v){
	if(n <= 0) //está vazia ou não é possível
	    return -1;
	int tam = 0; //tamanho do segmento
	int suf = 1; //sufixo
	//int aux = 0; //vai armazenar o valor que está repetindo
	for(int i = 0; i < n - 1; i++){
		if(v[i] == v[i+1]){
			suf++;
			if(suf > tam){ //se o sufixo for maior do que o maior tamanho encontrado, então alteramos o tamanho para o sufixo
				tam = suf;
			}
			continue;
		}
		else{
			suf = 1;
			continue;
		}

	}
	if(suf == 1) //não há repetidos
	    return 0;
	return tam;
}

int main(){
	int v[MAX];
	int n;
	printf("Qual é o valor de n?");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}	
	printf("%d", tamanhoSegmentoHorizontal(n, v));


return 0;

}