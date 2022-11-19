#include <stdio.h>

//Desenvolver uma função que, dado um arquivo texto contendo números, determine se estes encontram-se ordenados crescentemente.

//definição de constantes
#define TRUE 1
#define FALSE 0

int VerificaOrdem (char nomeArq[]){
  FILE *arquivo;
  int n1, n2;

  arquivo=fopen(nomeArq,"r");

  //verificando se ocorreu erro na abertura
  if (!arquivo){
    return -1;
  } else {
    //lendo o primeiro número do arquivo
		fscanf (arquivo, "%d", &n1);
		
		//lendo os demais valores
		while (fscanf (arquivo, "%d", &n2) != EOF){
      //verificando se foi encontrado um valor menor do que o anterior
			if (n2 < n1){
				//fechando o arquivo
				fclose (arquivo);
				
				//o arquivo não está ordenado
				return FALSE;
			} else{
				//atualizando o valor de 'num1'
				n1 = n2;	
			}
    }
    
    //fechando o arquivo
    fclose(arquivo);

    //arquivo está ordenado
    return TRUE;
  }
}

int main(void) {
	char nomeArquivo[50];
  int resp;
	
	printf("\nNome do arquivo a ser lido: ");
	scanf(" %[^\n]",nomeArquivo);

  resp=VerificaOrdem(nomeArquivo);

  switch (resp){
    case -1: printf("\n\tErro na abertura do arquivo!");
             break;
    case TRUE: printf("\n\tO arquivo %s está ordenado!",nomeArquivo);
                break;
    case FALSE: printf("\n\tO arquivo %s NÃO está ordenado!",nomeArquivo);
                break;
  }
	
  
  return 0;
}