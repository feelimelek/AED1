/*
Agora, veremos um bicho completamente diferente de qualquer outro já visto:
as matrizes esparsas.
São matrizes numéricas extensas com poucos valores diferentes de 0 armazenados nela, havendo uma pouca concentração de dados.
Quanto mais esparsas, menos não zeros.
Se eu tenho um computador maravilhoso com muita memória e não preciso me preocupar com o uso dela, uso a matriz na forma de matriz 
mesmo.
Entretanto, sabemos que as coisas não são bem assim.
Problema: como armazenar as informações relevantes de uma matriz esparsa sem desperdiçar memória?
Soluções encontradas: representá-la de outra forma, usando
- representação em linhas
ou
- listas cruzadas 

Vejamos primeiro a representação em linhas.
*/

#include <stdio.g>
#include <stdlib.h>
#include <stdbool.h>

//Quais são as informações relevantes que precisamos ter? O valor armazenado na matriz, sua linha e sua coluna
typedef struct{
	int chave;
	int lin; //linha
	int col; //coluna
	struct s* prox;
} NO;

typedef struct{
	NO* inicio;
	int maxcol;
	int maxlin;
} MATRIZ;

int valor(NO* p, int l, int c){ //retorna o valor armazenado na coordenada (l,c), assumindo que a lista armazena na ordem linhas e colunas
	while(p){
		if(p->lin < l){
			p = p->prox;
			continue
		} //estou achando a linha, uma vez encontrada a linha, vou percorrer e procurar a coluna
		if(p->lin > l) return 0;
		if(p->col < c){
			p = p->prox;
			continue;
		}
		if(p->col > c) return 0; //a linha é a mesma, mas a coluna não
		return p->chave;
	}
	return 0;
}

/*
Problema: excelência operacional
Vantagem: economizo memória.
Se empatar em questão de memória, vale mais a pena usar a matriz em si.
*/

NO* busca(MATRIZ* m, int i, int j, NO** ant){
	NO* p = m->inicio;
	*ant = NULL;
	while(p){
		if(p->lin > i) return NULL; //não existe essa linha
		if(p->lin < i){
			*ant = p;
			p = p->prox;
			continue;
		} //até aqui terá encontrado a linha
		if(p->col > j) return NULL; //não há essa coluna com a linha referente
		if(p->col < j){
			*ant = p;
			p = p->prox;
			continue;
		}
		return p; //encontrei
	}
	return NULL; //não encontrou
}

void atribuir(MATRIZ* m, int l, int c, int valor){
	NO* ant = NULL;
	NO* atual = busca(m, l, c, &ant);//onde deverá ser incluído
	int v = -1;
	if(atual)
		v = atual->chave; //peguei o valor
	/*
		Quatro casos a tratar:
		Caso 1: valor == 0 e v==0 => não tem nada na matriz e não precisa add nada
		Caso 2: valor != 0 e v!=0 => o elemento no qual será atribuído, já existe (não é zero na matriz), então só trocamos a chave
		Caso 3: valor == 0 e v!=0 => tem um elemento na matriz nessa posição sem ser zero, mas ele precisa virar zero/ser retirado 
		Caso 4: valor != 0 e v == 0 => não tem um elemento na matriz aí e precisa ser adicionado
	*/

	if(valor == 0 && v == 0) return; //não há nada para ser adicionado, caso1
	if(valor != 0 && v != 0){ //preciso trocar os valores, caso2
		atual->chave = valor;
		return
	}
	if(valor == 0 && v != 0) { //vou eliminar esse elemento da lista, caso3
		if(ant){ //se tiver um elemento anterior
			ant->prox = atual->prox; //pulei p
		} else
			m->inicio = atual->prox; //retirei o primeiro elemento da lista
		return;
	}
	if(valor!= 0 && v == 0){ //vou ter que incluir na lista, caso4
		NO* novo = (NO*)malloc(sizeof(NO));
		novo->chave = valor;
		novo->lin = l;
		novo->col = c; //coloquei os valores nos devidos lugares, agora preciso ligar na lista
		if(ant){
			novo->prox = ant-> prox; //grudei no nó seguinte (direita)
			ant->prox = novo;//apontei o anterior a ele (esquerda)
		}
		else{
			novo->prox = m->inicio;
			m->inicio = novo;
		}
		return;
	}
}

int somarColuna(MATRIZ* m, int j){ //implementação fácil, mas custoso
	int resp = 0;
	NO* p = m->inicio;
	while(p){
		if(p->col == j){
			resp = resp + p->chave;
		}
		p = p ->prox;
	}
	return resp;
}

void zerarDiagonal(MATRIZ* m){
	NO* p = m->inicio;
	NO* ant = NULL:
	while(p){
		if(p->lin == p->col){
			//p->chave = 0; //zerei, agora preciso excluir da lista, não precisa zerar pq vai excluir de qqr jeito
			NO* aux = p->prox;
			if(ant)
				ant->prox = p->prox;
			else
				m->inicio1 = p->prox;//pulei
			free(p);
			p = aux;
			continue;

		}
		else{
			ant =  p; //salvo o anterior
			p = p->prox; //vou para o próximo
		}
	}

}

int main(){

	return 0;
}