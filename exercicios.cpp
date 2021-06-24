void transferirPilhapFila(PILHA_DIN* p, FILA_DIN* f){
	NO* aux = p->topo; //vamos considerar que só sai da pilha o que está no topo e que só entra na fila pelo fim
	while(aux->prox){ //não é NULL
		aux = aux->prox; 
	}//vai chegar um que não tem prox, o último
	aux->prox = f->inicio;
	f->inicio = p->topo;
	p->topo = NULL;
}

void transferirFilapPilha(PILHA_DIN* p, FILA_DIN* f){ //respeitando as propriedades de ambas
	NO* aux = f->inicio;
	while(aux){
		f->inicio = f->inicio->prox;
		aux->prox = p->topo;
		p->topo = aux;
		aux = f->inicio;
	}
}

void copiarPilhapFila(PILHA_DIN* p,FILA_DIN* f){ //respeitando as propriedades das filas
	NO* aux = p->topo;
	while(aux){
		NO* novo = (NO*)malloc(sizeof(NO));
		novo->chave = aux->chave;
		novo->prox = NULL;
		f->fim->prox = novo;
		f->fim = novo;
		aux = aux->prox;
	}

}
/*
void copiarFilapPilha(PILHA_DIN* p, FILA_DIN* f){ //não mantendo a ordem
	NO* aux = f->inicio; //criei um ponteiro que percorrerá a fila
	if(f->inicio){
	NO* primeiro = (NO*)malloc(sizeof(NO)); // criei o primeiro nó da cópia da fila
	primeiro->chave = aux->chave; //copiei a chave
	primeiro->prox = p->topo; //grudei na pilha
	p->topo = primeiro; //tornei ele o topo da pilha
	NO* ant = primeiro; //criei um ponteiro que percorrerá os adicionados na pilha, para saber qual é p ant
	aux = aux->prox;
	while(aux){
		NO* novo = (NO*)malloc(sizeof(NO)); //criei um novo nó
		novo->chave = aux->chave; //copiei a chave
		novo->prox = ant->prox; // coloquei no lugar certo
		ant->prox = novo //coloquei no meio
		aux = aux->prox; //passei para o próximo da fila
		ant = ant->prox; //andei o ant
	}
	}
}*/

void copiarFilapPilha(PILHA_DIN* p, FILA_DIN* f){
	NO* auxf = f->inicio; //percorre a fila
	NO* primeiro = NULL; //salva a primeira posição
	NO* auxp = NULL; //percorre a fila criada
	while(auxf){		//enquanto houver um elemento a ser copiado na fila
		NO* novo = (NO*)malloc(sizeof(NO)); //crio um no novo
		if(auxp){ //se existir um ant, grudo nele
			auxp->prox = novo;
		}
		else{
			primeiro = novo; // se não existir, é o primeiro, salvo para referenciar o topo dps
		}
		novo->chave = auxf->chave; //copiei a chave
		novo->prox = NULL; //não tem próximo por enquanto
		auxp = novo;
		auxf = auxf->prox; 
	}
	auxp->prox = p->topo;
	p->topo = primeiro;
}

void copiarDequepPilha(DEQUE* d, PILHA_DIN* p){
	NO* aux = d->inicio1;
	NO* primeiro = (NO*)malloc(sizeof(NO));
	primeiro->chave = aux->chave; //copiei a chave
	primeiro->prox = p->topo; //grudei na pilha
	p->topo = primeiro; //tornei ele o topo da pilha
	NO* ant = primeiro; //criei um ponteiro que percorrerá os adicionados na pilha, para saber qual é p ant
	aux = aux->prox;
	while(aux){
		NO* novo = (NO*)malloc(sizeof(NO)); //criei um novo nó
		novo->chave = aux->chave; //copiei a chave
		novo->prox = ant->prox; // coloquei no lugar certo
		ant->prox = novo //coloquei no meio
		aux = aux->prox; //passei para o próximo da fila
		ant = ant->prox; //andei o ant para ser o novo, assim mantenho a ordem
	}
}

void copiarKpilhasFila(NPPILHAS* p, FILA_EST* f, int k){
	if(k < 0 || k > NP-1) return;
	int aux = -1;
	for(int i = 0; i <= k-1; i++){ //percorre as diferentes pilhas
		for(aux = base[k] + 1; aux <=topo[i]; aux++){ //percorre a pilha em si
			f->fim = ((f->fim)+1)%MAX; //onde será o fim
			f->A[f->fim] = p->A[p->topo[i]]; //coloco o valor da pilha k na fila
			if(f->inicio == -1){
				f->inicio = f->fim;
			}
		}
	}

}

bool linhasIdenticas(MATRIZ* m, int linha1, int linha2){ //dentro da matriz tem maxcol, maxlin e inicio, em linhas
	if(!m1->inicio) return true; //todos são NULL, então todas as linhas são iguais, então l1=l2
	NO* l1 = m->inicio;; //percorrerá a linha 1
	NO* l2 = m->inicio; //percorrerá a linha 2
	while (linha1 != l1->lin){
		l1 = l1->prox; //vou procurar onde começa a linha 1
	}
	while (linha2 != l2->lin){
		l2 = l2->prox; //onde começa a linha 2
	}

	if(!l1&&!l2) return true; //não há nada em nenhuma das listas, portanto são idênticas
	//uma vez encontrado o início de cada linha, vamos comparar
	if(!l1 || !l2) return false; //não há essa linha
	
	while(l1->lin == linha1 && l2->lin == linha2){ //enquanto as duas existirem e forem das referentes linhas
		if (l1->col == l2->col){ //se a coluna for a mesma
			if(l1->chave != l2->chave) return false;
			continue;
			l1 = l1->prox;
			l2 = l2->prox; 
	 	}
	 	else return false;

	}
	if(l1->lin == linha1) return false; //sobrou
	if(l2->lin == linha2) return false; //sobrou 
	return true;
	 //e se houver divergência nas colunas? não são idênticas
}

void zerarElementoAcima(MATRIZ* m, int i, int j){ //o elemento acima de i e j, será i-1, j
	NO* ant = NULL:
	NO* p = m->inicio; //será o ponteiro que espetaremos no elemento a ser zerado
	if(i > m->maxlin || i < 2 || j < 1 || j > maxcol) return; //não existe essa lista na matriz
	while((p->lin != i-1) || (p->col != j)){ //deve ser igual
		ant = p;
		p = p->prox; //continuo procurando e salvando o anterior
	} 
	if(p){//se achei o elemento, vou removê-lo
		ant->prox = p->prox;
		free(p);
	}
	else return; //o elemento acima já está zerado
}

void exibirLinhaiCompleta(MATRIZ* m, int i){
	if(i < 1 || i > m->maxlin) return;
	NO* p = m->inicio; //usarei para encontrar a linha
	while(p->lin != i){
		p = p->prox;
	} //achei o primeiro elemento da linha
	int zeros = 0;
	int ultimo = 0;
	int cont = 0;
	while(p->lin == i){ //percorrer os elementos da linha da matriz
		zeros = p->col - ultimo-1; //conto quantos zeros preciso imprimir até aí
		ultimo = p->col; //onde paramos
		for(zeros = zeros; zeros > 0; zeros--){
			printf("%d", 0);
		} //se não tiver zeros nem vai entrar
		printf("%d", p->chave); //imprimo a chave do elemento
		p = p->prox;
	}
	//e se sobrarem elementos que não estão na linha? 
	zeros = m->maxcol - p->col;
	for(int j = 0; j < zeros; j++){
		print("%d", 0);
	}
}

bool compararMatrizes(MATRIZ* m1, MATRIZ* m2){
	NO* p1 = m1->inicio;
	NO* p2 = m2->inicio;
	if (!p1 && !p2) return true;
	if (!p1 || !p2) return false;
	while(p1){
		if(!p2) return false;
		if(p1->lin == p2->lin && p1->col == p2->col && p1->chave == p2->chave){
			p1 = p1->prox;
			p2 = p2->prox;
			continue;
		}
		else
			return false;
	} 
	if(p2) return false; //sobrou elemento na matriz2
	return true;
}

bool linhasIguais(LISTACRZ* l, int l1, int l2){ //linha 1 e linha 2
	//vamos percorrer horizontalmente
	if(l1 == l2) return true;
	if(l1<1 || l1> MAXLIN || l2 <1 || l2>MAXCOL) return false;
	NO* p1 = lin[l1];
	NO* p2 = lin[l2];
	if(!p1 && !p2)
		return true;
	if(!p1 || !p2)
		return false;
	while(p1){
		if(!p2) return false;
		if(p2 && p1->lin == p2->lin && p1->col == p2->col && p1->chave == p2->chave){
			p1 = p1-> proxC;
			p2 = p2-> proxC;
			continue;
		}
		else 
			return false;
	}
	if(p2) return false;
	return true;
}

int valorEmij(LISTACRZ* l, int i, int j){
	if(i<1||i>MAXLIN||j<1||j>MAXCOL) return -1;//não está incluído na matriz
	//escolho se quero percorrer pela linha ou pela coluna, vamos percorrer a linha
	NO* p = l->col[j]; //quero a coluna j
	while(p->i != i){ //se a linha não for a mesma, continua procurando
		p = p->proxL;//vai um pra baixo
	}//encontrei onde é igual
	if(p)
		return p->chave;
	else
		return 0; //se não encontrei o elemento, quer dizer que é 0
}

NO* buscaij(LISTACRZ* l, int i, int j){
	if(i<1||i>MAXLIN||j<1||j>MAXCOL) return NULL;//não está incluído na matriz
	//escolho se quero percorrer pela linha ou pela coluna, vamos percorrer a linha
	NO* p = l->col[j]; //quero a coluna j
	while(p->i != i){ //se a linha não for a mesma, continua procurando
		p = p->proxL;//vai um pra baixo
	}//encontrei onde é igual
	if(p)
		return p;
	else
		return NULL;; //se não encontrei o elemento, quer dizer que é 0
}

void zerarDiagonalPrincipal(LISTACRZ* l){
	NO* esq = NULL;//ant esquerda
	NO* acima = NULL;//ant acima
	for(int x = 1; x <=MAXLIN; x++){ //percorre coluna
		NO* p = l->lin[x];
		while(p){
			if(p->i == p->j){ //se pertencer a diagonal principal
				p = busca(l, p->i, p->j, &esq, &acima);
				if(esq){
					esq->proxC = p->proxC;
				} else
					l->lin[x] = p->proxC;
				if(acima){
					acima->proxL = p->proxL;
				} else
					l->col[p->j] = p->proxL;
				 //esq e acima continuam iguais
				free(p);
			}
			p = p->proxC;

		}

	}
}