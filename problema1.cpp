/* 
Entrada: Vetor
Saída: 
-1 se não crescente
1 se não descrescente
0 se não há ordem
99 se for constante
TIRAR DÚVIDA
*/
#include <stdio.h>
#include <stdbool.h> //para usar bool precisa add essa biblioteca em c, iostream e using namespace std é de c++

int analise(int *v, int n){

	bool aumenta = false;
	bool diminui = false;

	for(int i = 0; i < n - 1 ; i++){ //vai até n-1, pois queremos acessar a posição depois, se for n, acessaremos uma posição inexistente
		if(v[i+1] > v[i])
			aumenta = true;
		if(v[i+1] < v[i])
			diminui = true;
		if(aumenta & diminui) // se aumenta e diminui forem verdadeiros, e tiverem o mesmo valor,
			return 0;			// é porque não há uma ordem (crescente ou decrescente)
	}
	if(aumenta) //for true
		return 1;
	else if(diminui)
		return -1;
	else 
		return 99; 
}

int main(){
	int n;
	scanf("%d", &n);
	int v[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}
	printf("%d", analise(&v, n));
}