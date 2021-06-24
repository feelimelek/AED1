#include <stdio.h>
#include <stdbool.h>

						
typedef struct{
	int chave;
						
} REGISTRO; 			

#define MAX 1000		
typedef struct{
	REGISTRO A[MAX]; 
	int nroElem; 	
					
} LISTA_SEQ; 			

void inicializar(LISTA_SEQ *l){
	l->nroElem = 0;
}

int busca(LISTA_SEQ *l, int ch){ 
	for (int i = 0; i < l->nroElem; i++){
		if(l->A[i].chave == ch) 
		return i; 
	}
	return -1;
}

bool listaCheia(LISTA_SEQ *l){
	if (l->nroElem >= MAX) 
		return true;
	else 
		return false;
}

bool anexar(LISTA_SEQ *l, int ch){
	if(listaCheia(l))
		return false; 
	else if (busca(l, ch) == -1) {
		l->A[l->nroElem].chave = ch;
		l->nroElem ++;
		return true;
	} 
}
bool incluir_i(LISTA_SEQ *l, int ch, int i){
	if(listaCheia(l))
		return false;
	if(busca(l, ch) != -1)
		return false;
	if(i < 0 || i > l->nroElem-1)
	    return false;
	else {
		for(int x = l->nroElem; x > i; x--){
			l->A[x] = l->A[x-1];
		}
		l->A[i].chave = ch;
		l->nroElem ++;
		return true;
	}
	
}
int procurar_i(LISTA_SEQ *l, int ch){
	if(ch < l->A[0].chave)
		return 0; 
	else if(ch > l->A[l->nroElem-1].chave && (l->nroElem!= MAX))			
		return l->nroElem;
	else if (busca(l, ch) != -1)
		return -1;
	else{
		int inicio = 0;
		int fim = l-> nroElem;
		int meio = (inicio + fim)/2;
		while(inicio <= fim){
			if(l->A[meio].chave > ch){
				if(l->A[meio-1].chave < ch)
					return meio;
				else
					fim = meio; 
			}
			else {
				if (l->A[meio+1].chave > ch)
					return meio+1;
				else 
					inicio = meio;
			}
		}
	}
}


bool excluir(LISTA_SEQ *l, int ch){
    int pos = busca(l, ch);
    if(pos == -1) 
        return false;
    else{
        for(int i = pos; i < l-> nroElem - 1; i++){ 
            l->A[i] = l->A[i + 1];
         }
    	l->nroElem --;
        return true;
    }
        
}

bool exibir(LISTA_SEQ *l){
	for(int i = 0; i < l->nroElem; i++){
		printf("%d", l->A[i].chave);
	}
}

  

int main(){
	LISTA_SEQ l;
	inicializar(&l);
	int ch;
	printf("%s", "insira a chave dos 3 primeiros registros:");
	l.nroElem = 4;
	for(int i = 0; i < l.nroElem; i++){
		scanf("%d", &l.A[i].chave);
	}
	exibir(&l);
	printf("%s", "insira a chave a ser anexada:");
	scanf("%i", &ch);
	if(anexar(&l, ch)){
	 exibir(&l);  
	}
	int i;
	printf("%s", "insira a posição chave a ser incluída:");
	scanf("%d", &ch);
	if(incluir_i(&l, ch, procurar_i(&l, ch)))
	    exibir(&l);
	
	return 0;
}