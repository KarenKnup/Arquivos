#include <stdio.h>

#define FALSE 0

int contaChar (char nomeArq[], char c){
	FILE *arquivo;
	char car;
	int count=0;
	
	arquivo=fopen(nomeArq,"r");
	
	if (arquivo==NULL){
		return FALSE;
	} else {
		while (fscanf(arquivo,"%c",&car)!=EOF){
			if (car==c){
				count++;
			}
		}
		return count;
		
		fclose(arquivo);
	}
}

int main(void) {
	char nomeArquivo[50], c;
	
	printf("\nArquivo a ser lido: ");
	scanf(" %[^\n]",nomeArquivo);
	printf("Caractere a ser buscado: ");
	scanf(" %c",&c);
	
	if (contaChar(nomeArquivo,c)==FALSE){
		printf("\n\tErro de leitura do arquivo!");
	} else {
		printf("\n\tArquivo lido com sucesso! O caractere %c aparece %d vezes.",c,contaChar(nomeArquivo,c));
	}
  
  return 0;
}