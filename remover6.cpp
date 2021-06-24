#include<stdio.h>

#define MAX 20
// y é o elemento, n tamanho do vertor, ini é inicio da parte relevante, fim indica fim-1 (ultima posição da parte relevante), v é vetor
void remover6 (int y, int n, int ini, int fim, int * v);

void imprimir(int* v, int n){
    for(int i = 0; i < n; i++){
    printf("%d", v[i]);
    }
}


void  remover6(int y, int n, int ini, int fim, int * v){
	//casos que dão errado
	if(n==0) //está vazio
		return;
	if((ini < 0) || ini > n-1 )//impossível
		return;
	if((fim < 0) || (fim > n-1)) //impossível
		return;

	for(int i = ini; i < fim-1; i++){
		if(v[i] == y){
            if(i == n-1)
		    n--;
		    else{ 
			    for(int j = i; j < n; j++){
				    v[j] = v[j+1];
			    }
		    }
			n--;
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
	int ini = 0;
	int fim = 0;
	printf("Intervalo relevante: (ini e fim)");
	scanf("%d %d", &ini, &fim);
	printf("Elemento a ser removido");
	int y = 0;
	scanf("%d", &y);

	remover6(y, n, ini, fim, v);

return 0;

}