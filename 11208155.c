
/* Programa 1a */
int remover1 (int k, int n, int * v){ //a
	if(n == 0)
		return -1; //não há nada no vetor para ser removido	
	if(k > n-1)  //se a posição a ser removida for maior do que a maior, então não dá para remover
		return -1;
	if(k < 0) // se for menor que 0, não existe
		return -1;	
	if (k== n-1){
	n--;
	return n; //se for para remover o último da esquerda
	}
	int i;
	for(i = k; i < n-1; i++){ //o for começa no elemento que será removido, o resto puxará os números existentes a direita dele até n-1
		v[i] = v[i+1];
	} 
	n--;
	return n;
}

/* Programa 1b */
int inserir1(int x, int k, int n, int * v){ 
	if(k > n-1) //k deve ser 0 <= k < n pela especificação
		return -1;
	if(k < 0) //não existe essa posição
		return -1;
	if(n == MAX) //está cheia
		return -1; 
		
	n++; //aumento uma casa do vetor para puxar os valores
	int i;
	for(i = n-1; i >= k; i--){
		if(i!= k){
		v[i] = v[i-1];
		}
		else{
			v[i] = x;
		} 
	}
	return n; 
	
}

/* Programa 2 */
int remover2 (int k, int n, int ini, int fim, int * v){
					//posição, tamanho, pos_inicio, pos_fim,vetor	
	if((k >= fim) || (k < ini) || k < 0 )
		return -1;
	if(n==0) //está vazio
		return -1;
	if((ini < 0) || ini > n-1 )//impossível
		return -1;
	if((fim < 0) || (fim > n-1)) //impossível
		return -1;
	if((k >= fim) || k < ini)//não está na parte relevante
		return -1;

	int tpr = fim - ini; //tamanho da parte relevante
	if((fim-1) - k >= k - ini){ //se o lado da direita for maior, então queremos que o lado da esquerda se mova para o custo ser menor e já resolve o problema do empate
		int i;
		for(i = k; i > ini; i--){
			v[i] = v[i-1]; // movi para a esquerda
   	}
	ini++;
	tpr--;
	} 
	else if(fim - k < k - ini){//se o lado da direita for menor, então queremos que o lado da direita se mova para o custo ser menor
		int i;
		for(i = k; i < fim-1; i++){
			v[i] = v[i+1]; //movi para a direita
		}
		fim--;
		tpr--;
		} 
	return tpr;
}

/* Programa 3 */
void inserir3(int x, int k, int n, int * v){
	if(k > n-1) //k deve ser 0 <= k < n pela especificação
		return;
	if(k < 0) //não existe essa posição
		return;
	if(n == MAX) //está cheia
		return; 

	n++; //aumento uma casa do vetor para puxar os valores
	int i;
	for(i = n-1; i >= k+1; i--){
		if(i!= k+1)
			v[i] = v[i-1];	
		
		else{
			v[i] = x;
		} 
	}	
}

int tamanhoSegmentoHorizontal(int n, int * v){
	if(n <= 0) //está vazia ou não é possível
	    return -1;
	int tam = 0; //tamanho do segmento
	int suf = 1; //sufixo
	//int aux = 0; //vai armazenar o valor que está repetindo
	int i;
	for(i = 0; i < n - 1; i++){
		if(v[i] == v[i+1]){
			suf++;
			if(suf > tam){ //se o sufixo for maior do que o maior tamanho encontrado, então alteramos o tamanho para o sufixo
				tam = suf;
			}
		}
		else{
			suf = 1;
		}

	}
	if(tam == 1) //não há repetidos
	    return 0;
	return tam;
}

/* Programa 5 */
int ehSubsequencia (int tamX, int * x, int n, int * v){
	
	if (tamX > n)
		return 0;

	if(n == 0 && x ==0)
		return 1;
	//olhar casos que daria erro
	int suf = 0; //valor que vai contar a subsequência
	int pos = 0; //posição do último que foi considerado como parte da subsequência
	int i;
	for(i = 0; i < tamX; i++){ //vamos percorrer x, percorrendo v para ver se encontramos
		int j;
		for(j = 0; j < n; j++){ //percorro v para cada posição de x
			if(v[j] == x[i]){
				if(j > pos){ //se a posição do elemento encontrado é depois da última considerada
					suf++; //consideramos esse elemento como parte da subsequencia
					pos = j; //e a nova última posição vira essa
				}
				if(suf == tamX){ //encontramos tudo
					return 1;
				}
				break;
			} else
				continue;
		}


	}
	return 0;

}

/* Programa 6 */
void  remover6(int y, int n, int ini, int fim, int * v){
	//casos que dão errado
	if(n==0) //está vazio
		return;
	if((ini < 0) || ini > n-1 )//impossível
		return;
	if((fim < 0) || (fim > n-1)) //impossível
		return;
	int i;
	for(i = ini; i < fim-1; i++){
		if(v[i] == y){
            if(i == n-1)
		    n--;
		    else{ 
			    int j;
				for(j = i; j < n-1; j++){
				    v[j] = v[j+1];
			    }
			    n--;
		    }
			i = ini - 1; //recomeça o loop, pois um elemento pode ter sido removido e a posição v[1] agora tem um novo elemento que pode ser y
		}
	}
}


/* Programa 7 */
int onde (int x, int n, int * v){ 
	static int pos = 0; //para percorrer o vetor criamos essa variável auxiliar, como é static ela só lê a declaração uma única vez
	if(n == 0) //não há posições no vetor
		return -1;
	if(pos >= n)
		return -1; //não encontrei nada
	else{
		if(v[pos] == x) //encontrei
			return pos;
		else {
			pos++; //vamos para a próxima posição
			return onde(x, n, v);
		}
	}

}

/* Programa 8 */
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
/* Programa 9 */
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
	int i;
	for(i = 0; i < n; i++){ //com esse for eu descubro a subsequência máxima
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
				int j;
				for(j = 0; j < pos; j++){
				    novotemp[j] = 0;
				}
				pos = 0;
			}  
		}
	}
 
	int* pont = novotemp;
	return pont;
}
