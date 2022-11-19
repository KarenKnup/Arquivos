#include <stdio.h>

#define FALSE 0

int contaChar (char nomeArq[]){
	FILE *arquivo;
	int count=0;
	char c;
	
	arquivo=fopen(nomeArq,"r");
	
	if (arquivo==NULL){
		return FALSE;
	} else {
		while (fscanf(arquivo,"%c",&c)!=EOF){
			if ((c>='A' && c<='Z') || (c>='a' && c<='z')){
				count++;
			}
		}
		
		fclose(arquivo);
		
		return count;
	}
}

int main(void) {
	char nomeArquivo[50];
	
	printf("\nNome do arquivo a ser lido: ");
	scanf(" %[^\n]",nomeArquivo);
	
	if (contaChar(nomeArquivo)==FALSE){
		printf("\n\tErro na leitura do arquivo!");
	} else {
		printf("\n\tArquivo lido com sucesso! Tem %d letras.",contaChar(nomeArquivo));
	}
	
  
  return 0;
}