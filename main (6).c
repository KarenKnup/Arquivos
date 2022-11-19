#include <stdio.h>

#define FALSE 0

//Desenvolver uma função que, dado um arquivo texto, verifique o número de caracteres no mesmo.

int contaChar (char nomeArq[]){
	FILE *arquivo;
	char c;
	int count=0;
	
	arquivo=fopen(nomeArq,"r");
	
	if (arquivo==NULL){
		return FALSE;
	} else {
		while (fscanf(arquivo,"%c",&c)!=EOF){
			if (c!=' '){
				count++;
			}
		}
		
		return count;
	}
	
	fclose(arquivo);
}


int main(void) {
	char nomeArquivo[50];
	
	printf("\nArquivo a ser lido: ");
	scanf(" %[^\n]",nomeArquivo);
	
	if (contaChar(nomeArquivo)==FALSE){
		printf("\n\tErro na leitura de arquivo!");
	} else {
		printf("\n\tArquivo lido com sucesso! Tem %d caracteres.",contaChar(nomeArquivo));
	}
  
  return 0;
}