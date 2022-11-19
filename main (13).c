
//importação de bibliotecas
#include <stdio.h>

/*
Implementar uma função que, dado um arquivo texto A 
contendo números inteiros, crie um novo arquivo, B, 
com os mesmos valores que estão em A, porém sem 
repetição de elementos.

Nota: por ser uma questão que avalia a manipulação 
de arquivos, nenhuma outra estrutura (como vetores) 
pode ser utilizada.
*/

//definição de constantes
#define TRUE 1
#define FALSE 0


int Func (char nomeArqA[], char nomeArqB[]){
	FILE *arquivo, *novo;
	int n1, n2;
	
	arquivo=fopen(nomeArqA,"r");
	novo=fopen(nomeArqB,"w");
	
	if ((!arquivo) || (!novo)){
		fclose(arquivo);
		fclose(novo);
			return FALSE;
	} else {
		//lendo o primeiro número do arquivo
		fscanf (arquivo, "%d", &n1);
		
		//lendo os demais valores
		while (fscanf(arquivo,"%d",&n2)!=EOF){
			if(n1!=n2){
				fprintf(novo,"%d\n",n1);
				
				//atualizando o valor de 'num1'
				n1 = n2;	
			}
			
		} 
		
		fclose(arquivo);
		fclose(novo);
			return TRUE;
	}
}

//main
int main (void){
	char nomeArquivoA[50], nomeArquivoB[50];
	
	printf("\nArquivo a ser lido: ");
	scanf(" %[^\n]",nomeArquivoA);
	printf("Nome do novo arquivo: ");
	scanf(" %[^\n]",nomeArquivoB);
	
	if (Func(nomeArquivoA,nomeArquivoB)==FALSE){
		printf("\n\tErro de leitura!");
	} else {
		printf("\n\tArquivo criado com sucesso!");
	}
	
	
	return 0;
}
