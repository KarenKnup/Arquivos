//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

int Func (char nomeArq[], char Arq2[], char c){
	FILE *arquivo, *arquivo2;
	char caracter;
	
	arquivo=fopen(nomeArq,"r");	
	arquivo2=fopen(Arq2,"w");
	
	if ((arquivo==NULL) || (arquivo2==NULL)){
		return -1;
	} else {
		while (fscanf(arquivo,"%c",&caracter)!=EOF){
			if (caracter!=c){
				fprintf(arquivo2,"%c",caracter);
			}
		}
		
		fclose(arquivo);
		fclose(arquivo2);
		
		return TRUE;
	}
}

//main
int main (void){
	char nomeArquivo[50], Arquivo2[50], c;
	int r;
	
	printf("\nArquivo a ser lido: ");
	scanf(" %[^\n]",nomeArquivo);
	printf("Caractere a ser removido do arquivo: ");
	scanf(" %c",&c);
	printf("Nome do novo arquivo: ");
	scanf(" %[^\n]",Arquivo2);
	
	r=Func(nomeArquivo,Arquivo2,c);
	
	switch (r){
		case -1: printf("\n\tErro na abertura do arquivo!");
					break;
		case TRUE: printf("\n\tRemoção do caractere %c realizada com sucesso!",c);
					break;
		case FALSE: printf("\n\tErro na remoção do caractere %c!",c);
					break;
	}
	
	return 0;
}
