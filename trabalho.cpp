//----------------------------------------------------------------------------
// NOMES DOS RESPONSÁVEIS: Fernanda Elimelek E Giovanna de Oliveira Pinheiro
//----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

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
NO* buscaEsqAcima(LISTASCR *l, int lin, int col, NO **esq, NO **acima);
void inserir(LISTASCR *l, int ch, int lin, int col);


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
            //achar acima e esq p/ mover ponteiros e excluir e2
            NO*esqE2=NULL; NO*acimaE2= NULL;
            NO* aux = buscaEsqAcima(l,e2->lin, e2->col,&esqE2,&acimaE2);

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

        //achar acima e esq p/ mover ponteiros e excluir e1
        NO*esqE1=NULL; NO*acimaE1= NULL;
        NO* aux = buscaEsqAcima(l,e1->lin, e1->col,&esqE1,&acimaE1);

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


NO* buscaEsqAcima(LISTASCR *l, int i, int j, NO **esq, NO **acima){
    if(i < 1 || i >= 11 || j < 1 || j >= 11) return NULL;
    NO* p = l->COL[j]; //percorrendo a coluna
    while(p){
        if(p->lin >= i) break; //encontrei ou já passou
        *acima = p;
        p = p->proxL;
    }
    p = l->LIN[i]; //percorrendo a linha 
    while(p){
        if(p->col > j) return NULL; //passou, não encontrei
        if(p->col == j) return p; //encontrei
        *esq = p;
        p = p->proxC;
    }
    return NULL;
}

void inserir(LISTASCR *l, int ch, int i, int j){
    if(i < 1 || i >= 11 || j < 1 || j >= 11) return; // intervalo de posições da matriz
    NO* acima = NULL;
    NO* esq = NULL;
    NO* novo = buscaEsqAcima(l, i, j, &esq, &acima);
    novo = (NO*) malloc(sizeof(NO));
    novo->lin = i;
    novo->col = j;
    novo->info = ch;
    if(acima){
        novo->proxL = acima->proxL;
        acima->proxL = novo;
    }
    else{
        novo->proxL = l->COL[j];
        l->COL[j] = novo;
    }
    if(esq){
        novo->proxC = esq->proxC;
        esq->proxC = novo;
    }
    else{
        novo->proxC = l->LIN[i];
        l->LIN[i] = novo;
    }
    
}


