//----------------------------------------------------------------------------
// NOMES DOS RESPONSÁVEIS: Fernanda Elimelek E Giovanna de Oliveira Pinheiro
//----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <iostream>
#define MAXLIN 11
#define MAXCOL 11
using namespace std;

char* nroUSP1() {
    return("11208155");
}

char* nroUSP2() {
    return("11218793");
}

char* grupo() {
    return("18");
}

typedef struct estr {
        int info;
	int lin;
	int col;
        struct estr *proxC;   // ponteiro para a direita
        struct estr *proxL;   // ponteiro para baixo
} NO;

// matriz 10 x 10 (a linha e coluna 0 são desprezadas)
typedef struct {
	NO* LIN[11];
	NO* COL[11];
} LISTASCR;



// funcao principal
void substituir(LISTASCR* l, int i, int j);
//funções auxiliares

NO* buscaDirAcima(LISTASCR *l, int lin, int col, NO **dir, NO **acima);
void inserir(LISTASCR *l, int ch, int lin, int col);
void inicializar(LISTASCR* l);
void exibir(LISTASCR* l);


void substituir(LISTASCR* l, int i, int j){

NO* pL; //percorre linha
NO* pC; //percorre coluna
//pL e pC nos primeiros elem da lin e col
pL = l->LIN[i];
pC = l->COL[j];

NO* e1 = NULL;
NO* e2 = NULL;

if(pL && pC){
   while (pL->col<j || pC->lin<i){ //enquanto não chegou no pivô
    e1 = pL;
    e2 = pC;
        if(pL->col == pC->lin){
            //trocar info
            int aux = e1->info;
            e1->info = e2->info;
            e2->info = aux;
        }
        if(pL->col > pC->lin){ //"passou um espaço na linha"
            inserir(l, e2->info, e1->lin, e2->lin);
            //achar acima e dir p/ mover ponteiros e excluir e2
            NO*esqE2=NULL; NO*acimaE2= NULL;
            NO* aux = buscaDirAcima(l,e2->lin, e2->col,&dirE2,&acimaE2);

            if(acimaE2){
            acimaE2->proxL = e2->proxL;
            }
            else{
                l->COL[pC->col] = e2->proxL;
            }
            if(esqE2){
            esqE2->proxC = e2->proxC;
            }
            else{
                l->LIN[pC->lin] = e2->proxC;
            }
            free(e2);
            pC = pC->proxL;
            continue;
        }


    if(pL->col < pC->lin){ //"passou um espaço na coluna"

        inserir(l, e1->info, e1->col, e2->col);

        //achar acima e dir p/ mover ponteiros e excluir e1
        NO*esqE1=NULL; NO*acimaE1= NULL;
        NO* aux = buscaDirAcima(l,e1->lin, e1->col,&dirE1,&acimaE1);

         if(acimaE1){
            acimaE1->proxL = e1->proxL;
            }
            else{
                l->COL[pC->col]->proxL = e1->proxL;
            }
            if(esqE1){
            esqE1->proxC = e1->proxC;
            }
            else{
                l->LIN[pC->lin]->proxC = e1->proxC;
            }
            free(e1);
            pL = pL->proxC;
            continue;

    }

    //fazer o pL e pL ir p/ prox
    pL = pL->proxC;
    pC = pC->proxL;
    }

}

}




//--------------------------------------------------------------
// função main()  APAGAR ANTES DE ENTREGAR
//--------------------------------------------------------------

int main(){
    int i = 4;
    int j = 3;
     LISTASCR l;
     inicializar(&l);

   //MATRIZ TESTE IGUAL NO PDF
    inserir(&l, 1, 1, 1);//
    inserir(&l, 2, 2, 2);//
    inserir(&l, 3, 3, 2);//
    inserir(&l, 4, 4, 3);//
    inserir(&l, 5, 4, 4);//
    inserir(&l, 6, 3, 5);//
    inserir(&l, 7, 2, 5);//
    inserir(&l, 8, 5, 5);//
    inserir(&l, 9, 1, 3);//
    inserir(&l, 10, 2, 3);//
    inserir(&l, 11, 4, 2);//
//quando eu chegar em casa eu posso passar os inserir mas:
/*//- linha e coluna vazias
    inserirMatrizCruzada(&l, 1, 1, 1);
    inserirMatrizCruzada(&l, 2, 2, 2);
    inserirMatrizCruzada(&l, 3, 3, 2);
    inserirMatrizCruzada(&l, 4, 4, 3);
    inserirMatrizCruzada(&l, 5, 4, 4);
    inserirMatrizCruzada(&l, 6, 3, 5);
    inserirMatrizCruzada(&l, 7, 2, 5);
    inserirMatrizCruzada(&l, 8, 5, 5);

- só linha

    inserirMatrizCruzada(&l, 1, 1, 1);
    inserirMatrizCruzada(&l, 2, 2, 2);
    inserirMatrizCruzada(&l, 3, 3, 2);
    inserirMatrizCruzada(&l, 4, 4, 3);
    inserirMatrizCruzada(&l, 5, 4, 4);
    inserirMatrizCruzada(&l, 6, 3, 5);
    inserirMatrizCruzada(&l, 7, 2, 5);
    inserirMatrizCruzada(&l, 8, 5, 5);
    inserirMatrizCruzada(&l, 11, 4, 2);

- só coluna
    inserirMatrizCruzada(&l, 1, 1, 1);
    inserirMatrizCruzada(&l, 2, 2, 2);
    inserirMatrizCruzada(&l, 3, 3, 2);
    inserirMatrizCruzada(&l, 4, 4, 3);
    inserirMatrizCruzada(&l, 5, 4, 4);
    inserirMatrizCruzada(&l, 6, 3, 5);
    inserirMatrizCruzada(&l, 7, 2, 5);
    inserirMatrizCruzada(&l, 8, 5, 5);
    inserirMatrizCruzada(&l, 9, 1, 3);
    inserirMatrizCruzada(&l, 10, 2, 3);

- linha acaba antes do pivot
    inserirMatrizCruzada(&l, 1, 1, 1);
    inserirMatrizCruzada(&l, 2, 2, 2);
    inserirMatrizCruzada(&l, 3, 3, 2);
    inserirMatrizCruzada(&l, 4, 4, 3);
    inserirMatrizCruzada(&l, 6, 3, 5);
    inserirMatrizCruzada(&l, 7, 2, 5);
    inserirMatrizCruzada(&l, 8, 5, 5);
    inserirMatrizCruzada(&l, 9, 1, 3);
    inserirMatrizCruzada(&l, 10, 2, 3);
    inserirMatrizCruzada(&l, 11, 4, 2);

- coluna acaba antes do pivot
 inserirMatrizCruzada(&l, 1, 1, 1);
    inserirMatrizCruzada(&l, 2, 2, 2);
    inserirMatrizCruzada(&l, 3, 3, 2);
    inserirMatrizCruzada(&l, 4, 4, 3);
    inserirMatrizCruzada(&l, 5, 4, 4);
    inserirMatrizCruzada(&l, 6, 3, 5);
    inserirMatrizCruzada(&l, 7, 2, 5);
    inserirMatrizCruzada(&l, 8, 5, 5);
    inserirMatrizCruzada(&l, 9, 1, 3);
    inserirMatrizCruzada(&l, 10, 2, 3);
    inserirMatrizCruzada(&l, 11, 4, 2);

- buracos entre o início e o pivot
    inserirMatrizCruzada(&l, 1, 1, 1);
    inserirMatrizCruzada(&l, 2, 2, 2);
    inserirMatrizCruzada(&l, 3, 3, 2);
    inserirMatrizCruzada(&l, 4, 4, 3);
    inserirMatrizCruzada(&l, 5, 4, 4);
    inserirMatrizCruzada(&l, 6, 3, 5);
    inserirMatrizCruzada(&l, 7, 2, 5);
    inserirMatrizCruzada(&l, 8, 5, 5);
    inserirMatrizCruzada(&l, 9, 1, 3);
    inserirMatrizCruzada(&l, 10, 2, 3);
- buraco um antes do pivo
     inserirMatrizCruzada(&l, 1, 1, 1);
    inserirMatrizCruzada(&l, 2, 2, 2);
    inserirMatrizCruzada(&l, 3, 3, 2);
    inserirMatrizCruzada(&l, 4, 4, 3);
    inserirMatrizCruzada(&l, 5, 4, 4);
    inserirMatrizCruzada(&l, 6, 3, 5);
    inserirMatrizCruzada(&l, 7, 2, 5);
    inserirMatrizCruzada(&l, 8, 5, 5);
    inserirMatrizCruzada(&l, 9, 1, 3);
    inserirMatrizCruzada(&l, 10, 2, 3);
    inserirMatrizCruzada(&l, 11, 4, 1);


- primeira/última linha/coluna
- com/sem pivot
    */

    cout<<"antes: "<<endl;
    exibir(&l);
    cout<<endl<<"depois: "<<endl;
    substituir(&l, i, j);
    exibir(&l);


return 0;
}


NO* buscaEsqAcima(LISTASCR *l, int lin, int col, NO **esq, NO **acima){
    if(lin >= MAXLIN || col >= MAXCOL || lin < 1 || col < 1) return NULL;
    NO* p = l->LIN[lin];
    while(p){
        if(p->col >= col) break;
        *esq = p;
        p = p->proxC;
    }
    p = l->COL[col];
    while(p){
        if(p->lin > lin) return NULL;
        if(p->lin == lin) return p;
        *acima = p;
        p = p->proxL;
    }
    return NULL;
}

void inserir(LISTASCR *l, int ch, int lin, int col){
    if(lin >= MAXLIN || col >= MAXCOL || lin < 1 || col < 1) return;
    NO* esq = NULL;
    NO* acima = NULL;
    NO* novo = buscaDirAcima(l, lin, col, &esq, &acima);

    novo = (NO*) malloc(sizeof(NO));
    novo->info = ch;
    novo->lin = lin;
    novo->col = col;
    if(esq){
        novo->proxC = esq->proxC;
        esq->proxC = novo;
    }
    else{
        novo->proxC = l->LIN[lin];
        l->LIN[lin] = novo;
    }
    if(acima){
        novo->proxL = acima->proxL;
        acima->proxL = novo;
    }
    else{
        novo->proxL = l->COL[col];
        l->COL[col] = novo;
    }
}

void inicializar(LISTASCR* l){
    for(int i = 1; i <MAXLIN; i++){
        l->LIN[i] = NULL;
    }
    for(int i = 1; i <MAXCOL; i++){
        l->COL[i] = NULL;
    }
}

void exibir(LISTASCR* l){
    int i;
    for(i = 1; i < 11; i++){ //percorre a coluna
        NO* p = l->COL[i];
        while(p){ //percorre a linha
            printf("%d", p->info);
            cout<<":[";
            cout<<p->lin <<"," ;
            cout<<p->col<<"]"<<endl;

            p = p->proxL;
        }
    }

}