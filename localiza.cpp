#include<stdio.h>

#define MAX 20
// x é o elemento a ser encontrado
int localiza (int x, int n, int ini, int fim, int * v);

void imprimir(int* v, int n){
    for(int i = 0; i < n; i++){
    printf("%d", v[i]);
    }
}

int localiza (int x, int n, int ini, int fim, int * v){  //para percorrer o vetor usaremos ini como se fosse a variável auxiliar pos
	//casos que dão errado
	if(n==0) //está vazio
		return -1;
	if((ini < 0) || ini > n-1 )//impossível
		return -1;
	if((fim < 0) || (fim > n-1)) //impossível
		return -1;
	if(ini >= fim) //se a posição considerada for maior que á última do intervalo, significa que não há
		return -1; //não encontrei nada
	else{
		if(v[ini] == x) //encontrei
			return ini;
		else {
			return localiza(x, n, ini+1, fim, v); //chamo a função novamente, agora considerando uma posição a frente, ini++;
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
	int x = 0;
	printf("Qual é o valor de x?");
	scanf("%d", &x);
	
	printf("%d", localiza(x, n, ini, fim, v));
return 0;

}