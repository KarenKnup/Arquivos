#include <stdio.h>
#include <stdlib.h>

/*
Implementar uma função que, dados dois arquivos textos arquivoA e arquivo, contendo números inteiros, um por linha, sem repetições, determine o número de elementos comuns entre os dois arquivos.
*/

#define TRUE 0
#define FALSE 1

int busca(char nomeArq[], int num){//Arquivos com 1 número/caractere por linha
  FILE *arq;
  int n;

    arq=fopen(nomeArq,"r");

  if(!arq){
    return FALSE;
  } else {
    while (fscanf(arq,"%d",&n)!=EOF){
      if (n == num){
        fclose(arq);
        return TRUE;
      }
    }
        fclose(arq);
        return FALSE;
  }
}

int VerificaRepet (char nomeArq[]){//Verifica se tem repetições nesse arquivo
	FILE *arquivo;
  int n1, n2;

   arquivo=fopen(nomeArq,"r");

  if(!arquivo){
    return FALSE;
  } else {
    //lendo o primeiro número do arquivo
		fscanf (arquivo, "%d", &n1);
    
    //lendo os demais valores
		while (fscanf(arquivo,"%d",&n2)!=EOF){
			if(n1==n2){
			  return FALSE;
			}
			//atualizando o valor de 'num1'
				n1 = n2;	
		} 
		
		fclose(arquivo);
  }

  return TRUE;
}

int Verifica (char arq[], char arqA[]){//Quantos elementos em comum entre esses arquivos sem repetição
  FILE *arquivo, *arquivoA;
  int n, cont=0;

  arquivo=fopen(arq,"r");
  arquivoA=fopen(arqA,"r");

  if(!arquivo || !arquivoA){
    return FALSE;
  } else {
    //Verificando se tem repetições em algum arquivo
    if(VerificaRepet(arq)==FALSE || VerificaRepet(arqA)==FALSE){
      return FALSE;
    } else {        
      //Contando os elementos em comum entre os 2 arquivos -- compara cada n1 de arq com todos n2 de arqA
		
		  while (fscanf(arquivo,"%d",&n)!=EOF){
  			if(busca(arqA,n)==TRUE){
          cont++;
        }		
  		} 
  
      fclose(arquivo);
      fclose(arquivoA);

      return cont;
    }
  }
}

int main(void) {
  char arq[50], arqA[50];

  printf("\nArquivo: ");
  scanf(" %[^\n]",arq);
  printf("\nArquivo A: ");
  scanf(" %[^\n]",arqA);

  if(Verifica(arq,arqA)==FALSE){
    printf("\n\n\tERRO!");
  } else {
    printf("\n\n\tOs arquivos têm %d elementos em comum.",Verifica(arq,arqA));
  }
  
  return 0;
}