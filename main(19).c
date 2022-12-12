#include <stdio.h>
#include <stdlib.h>

/*
Dados dois arquivos textos arquivoA e arquivoB,
contendo números inteiros, um por linha, implementar
uma função que determine se todos os elementos do
primeiro arquivo estão no segundo (retornando 0 ou 1,
dependendo do resultado).
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

int Verifica (char arquA[], char arquB[]){
  FILE *arqA, *arqB;
  int n;

  arqA=fopen(arquA,"r");
  arqB=fopen(arquB,"r");

  if(!arqA || !arqB){
    return FALSE;
  } else {
    while (fscanf(arqA,"%d\n",&n)!=EOF){//procura em A todos os "n" de B
      if (busca(arquB,n)==FALSE){
        fclose(arqA);
        fclose(arqB);
        return FALSE;
      }    
    }

    fclose(arqA);
    fclose(arqB);
    return TRUE;
  }
}

int main(void) {
  char arqA[50], arqB[50];

  printf("\nArquivo A: ");
  scanf(" %[^\n]",arqA);
  printf("\nArquivo B: ");
  scanf(" %[^\n]",arqB);
  
  if(Verifica(arqA,arqB)==TRUE){
    printf("\n\n\tTodos os elementos de A estão em B!");
  } else {
    printf("\n\n\tHá elementos de A que NÃO estão em B!");
  }
 
  
  return 0;
}