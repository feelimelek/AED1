#include<stdio.h>

#define MAX 20

//posição, tamanho, pos_inicio, pos_fim,vetor
int remover2 (int k, int n, int ini, int fim, int * v){
	if((k >= fim) || (k < ini) || k < 0 )
		return -1;
	if(n==0) //está vazio
		return -1;
	if((ini < 0) || ini > n-1 )//impossível
		return -1;
	if((fim < 0) || (fim > n-1)) //impossível
		return -1;
	if((k >= fim) || k < ini)//não está na parte relevante
		return -1;

	int tpr = fim - ini + 1; //tamanho da parte relevante
	if((fim-1) - k >= k - ini){ //se o lado da direita for maior, então queremos que o lado da esquerda se mova para o custo ser menor e já resolve o problema do empate
		for(int i = k; i > ini; i--){
			v[i] = v[i-1]; // movi para a esquerda
   	}
	ini++;
	tpr--;
	} 
	else if(fim - k < k - ini){//se o lado da direita for menor, então queremos que o lado da direita se mova para o custo ser menor
		for(int i = k; i < fim-1; i++){
			v[i] = v[i+1]; //movi para a direita
		}
		fim--;
		tpr--;
		} 
	return tpr;
}
/*
Programa 2 : Refa¸ca todo o problema da remo¸c˜ao sob condi¸c˜oes mais gerais. Suponha que a parte
relevante do vetor v ´e v[ini..fim-1]; para remover v[k], puxe v[k+1..fim-1] para a esquerda ou
empurre v[ini..k-1] para a direita, dependendo de qual das alternativas seja mais “barata”. O
m´etodo devolve o novo tamanho da parte relevante do vetor. Qualquer situa¸c˜ao que n˜ao permita
a remo¸c˜ao, deve-se retornar -1.
*/
void imprimir(int* v, int n){
    for(int i = 0; i < n; i++){
    printf("%d", v[i]);
    }
}
int main() {

int v[MAX];
int n;
printf("Qual é o valor de n?");
scanf("%d", &n);
for(int i = 0; i < n; i++){
scanf("%d", &v[i]);
}	
int k = 0;
int ini = 0;
int fim = 0;
printf("Insira k(posição do elemento a ser removido), ini (começo da parte relevante) e fim (da pr):"); //testando remover
scanf("%d %d %d", &k, &ini, &fim);
printf("%d\n", remover2(k, n, ini, fim-1, v));
imprimir(v, n);


return 0;
}