//--------------------------------------------------------------
// NOMES DOS RESPONSÁVEIS: Fernanda Elimelek E Giovanna de Oliveira Pinheiro
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h> //
#include <conio.h>//pesquisar
#include <malloc.h>
#include <string.h>//pesquisar

// ######### ESCREVA O NROUSP DO PRIMEIRO INTEGRANTE AQUI
char* nroUSP1() {
    return("11208155");
}

// ######### ESCREVA O NROUSP DO SEGUNDO INTEGRANTE AQUI (OU DEIXE ZERO)
char* nroUSP2() {
    return("11218793");
}

// ######### ESCREVA O NRO DO SEU GRUPO TAL QUAL CADASTRADO (LINK NO PDF DO EP) 
char* grupo() {
    return("08");
}


// elemento da lista ligada a ser gerada
// observando que cada nó contém apenas um caractere (ch)
typedef struct estr {
        char ch;
        struct estr *prox;
} NO;

typedef struct{
  NO* inicio; 
} LISTA_DIN;

void inicializar(LISTA_DIN *l){
    l->inicio = NULL;
    
}



//lista ligada que queremos imprimir/já decodificada MUDAR
bool inserir(char letra, LISTA *l) { RESOLVER COMO A INSERIR DEVE FICAR
 NO* novo;

novo = (NO*) malloc(sizeof(NO));
novo->ch = letra;
 if(!l -> inicio) { // 1a. inserção em lista vazia
 l->inicio = novo;
 novo -> prox = NULL;
 }
 if(ant){//adiciono quando não é no primeiro espaço

    novo->prox = ant->prox;
    ant->prox = novo;
 }
 else{     
    novo -> prox = l->inicio;
    l->inicio = novo; 
}
 
}

NO* stringpLista(char entrada[], int tam){
    NO* resp;
    resp = NULL;
 for (int i = tam-1; i >= 0 ; i--){
     inserir(&resp, entrada[i]);
 }
    return resp;

}

/*NO* stringpLista(char* entrada, LISTA_DIN *l){
    
    inicializar(l);
    
    int tam = strlen(entrada);
    
    for(int i = 0; i<tam; i++){
        inserir(entrada[i],l);
    }
    
    return //ponteiro inicio;
}*/

// funcao principal
NO* decodificar(char* entrada);


//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
NO* decodificar(char* entrada) {

	NO* resp;
	resp = NULL; //PENSAR ONDE FICA O RESP
    
    LISTA_DIN l;
    NO* p = l->inicio; 
    int tam = strlen(entrada); //calcular o tamanho da string = tamanho x 
                            // int x = strlen(frase); // retorna o tamanho da frase 

    int ASC = 0;
    int n = 0; //numero de caracteres a serem repetido
    while(p){
        
        //testar se o proximo elemento é um numero, se for, vai ter que repetir o caractere na lista
        int ASC_next = (int) (p->prox->ch); //converti em int, na tabela ASC para saber que tipo de caractere é
        if(ASC_next >= 48 || ASC-next <= 57){ //é um número
            //fazer o typecast e verificar os casos
            n = stoi(p->prox->ch);                        // converto o char em int para saber quantas vezes repete 
            //PENSAR NO CASO QUANDO FOR 0
            for(int j = 0; j < n -1){ //incluo n-1 termos na lista
                inserir() //insiro o NO do repetido, o ultimo repetido conectado com o proximo do numero a ser excluído (aquele q fez repetir)
                //INSERIR NA LISTA OS CARACTERES QUE DEVEM SER REPETIDOS, TIRAR O NO QUE TEM O NUMERO QUE DISSE PARA REPETIR
            }
        } else { //é uma letra ou simbolo ou espaço colocar na lista. Todos caracteres especiais?
                inserir() // insiro o proprio NO
                continue; // função inserir dentro de um laço x vezes  (passar lista por referência)
            }
        return resp;    
    }
            
// considerações a serem feitas:(ifs) // algum laço para inserir todos os chars
           // retornar ponteiro do inicio da lista

	return resp;
}



//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------
int main() {

	NO* p = null;

	   // aqui vc pode incluir codigo para transformar 
	// o string entrada em uma lista ligada p

	// o EP sera testado com chamadas deste tipo
	NO* teste = null;
	char entrada[] = "frase de teste5!"
	teste = decodificar(entrada);

}






/*------
Duvidas: como ler o espaço na string
Pesquisas:

Para ler e imprimir caracteres, utilize '%c' no scanf e no printf. Quando uma tecla é digitada (lida pelo scanf) o código correspondente à tecla é traduzido para o número binário correspondente, e armazenado na variável utilizada no scanf. Quando uma variável caractere é utilizada no printf, esse número é utilizado para imprimir o caractere correspondente na tabela ASCII.
https://www.quora.com/Why-is-the-value-of-char-value-48-a-zero
*/

