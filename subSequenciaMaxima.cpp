#include<stdio.h>

#define MAX 20
/*
n ´e o tamanho do vetor v. O valor de retorno ´e um ponteiro para um vetor que cont´em
a subsequˆencia m´axima. Para C, h´a um parˆametro adicional (tamret) que ´e o tamanho do vetor
retornado. Esse parˆametro ´e passado por referˆencia e dever´a ser atualizado dentro da fun¸c˜ao
subSequenciaMaxima
*/
void imprimir(int* x, int n){
    for(int i = 0; i < n; i++){
    printf("%d\n", *(x+i));
    }
}

int * subSequenciaMaxima (int n, int * v, int * tamret);

//retona vetor, n é o tamanho do vetor, v é o vetor, tamret é o tamanho do novo vetor passado por referência
int * subSequenciaMaxima (int n, int * v, int * tamret){
	int suf = 0; //sufixo
	int GlobalMax = 0;
	int novotemp[n]; //para armazenar os elementos da subsequencia
	int pos = 0; //posição de tamret
	*tamret = 0; //tamanho do novo vetor
	if(n<=0) //está vazio
		return NULL;

	for(int i = 0; i < n; i++){ //com esse for eu descubro a subsequência máxima
		if(suf + v[i] >GlobalMax){ //se o sufixo mais o elemento do vetor for maior que a maior soma consecutiva, esse será o novo sufixo e novo global max
			suf = suf + v[i];
			GlobalMax = suf;
			novotemp[pos] = v[i]; 
			pos++;
			*tamret = pos;
		}
		else {
			if(suf + v[i] > 0){ //se for positiva a soma, pode ser que um numero depois vai ser maior que global max, então guardamos essa soma
				suf = suf + v[i];
				novotemp[pos] = v[i];
			    pos++;
			}
			else {
				suf = 0; //se for negativa a soma, a subsequencia é vazia
				for(int j = 0; j < pos; j++){
				    novotemp[j] = 0;
				}
				pos = 0;
			}  
		}
	}
 
	int* pont = novotemp;
	//imprimir(pont, *tamret);
	return pont;
}


int main(){
	int v[] = {11,12,10,11,13,9,7,3,3,-1,-1,-1,-1,-1,-1};
	int tamret;
	int* x = subSequenciaMaxima(15, v, &tamret);
	imprimir(x, tamret);

	return 0;

}