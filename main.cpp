#include <stdio.h>

//criando o tipo ALUNO
typedef struct {
	char nome[100];
	int idade;
	int nUSP;
} ALUNO;

//se queremos alterar o nusp 
void alterarnUSP(ALUNO *y){ // vari�vel para armazenar o nUSP
	int x;
	scanf("%d", &x);
	y -> nUSP = x; // alterei o nUSP do aluno y
}
//se foi anivers�rio do ALUNO, preciso add 1 em sua idade
void aniversario(ALUNO *y){
	y -> idade++; //aumentei 1 na idade do aluno y
}

int main (){
	ALUNO y; //crio uma vari�vel y do tipo aluno
	alterarnUSP(&y);
	y.idade = 18;
	aniversario(&y);
	printf("ALUNO: \n%s \n%d \n%d", y.nome, y.idade, y.nUSP);
}
