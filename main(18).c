/*
Considere a existência de um arquivo contendo números inteiros, um por linha. Desenvolver uma função que, dados
este arquivo e duas linhas L1 e L2, inverta no arquivo todos os números compreendidos entre estas linhas.
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

int busca(char nomeArq[], int l){//procura uma linha em um arquivo (arquivo com um número por linha)
  FILE *arq;
  int n, cont=1;

    arq=fopen(nomeArq,"r");

  if(!arq){
    return FALSE;
  } else {
    while (fscanf(arq,"%d",&n)!=EOF){
      if (cont==l){
        fclose(arq);
        return n;
      }
      cont++;
    }
  }
}

int ArquivoInvertido(char nomeArq[], char Arq2[], int L1, int L2){
  FILE *arquivo, *novo;
  int cont=1, n, l=L2;

  arquivo=fopen(nomeArq,"r");
  novo=fopen(Arq2,"w");

  if ((!arquivo) || (!novo)){
    return FALSE;
  } else {
    while (fscanf(arquivo,"%d",&n)!=EOF){//transferindo os elementos entre L1 e L2 para "novo"
      if(cont>=L1 && cont<=L2){
        fprintf(novo,"%d\n",busca(nomeArq,l));
        l--;
      }
      cont++;
    }

     if(cont<L1 || cont<L2 || L1<=0 || L2<=0){//se as linhas não existem na lista
      return FALSE;
    }
    
    fclose(novo);
    fclose(arquivo);
  } 
  
  return TRUE;
}

int main(void) {
  char nomeArquivo[50], Arq2[50];
  int L1, L2;

  printf("\nArquivo a ser lido: ");
  scanf(" %[^\n]",nomeArquivo);
  printf("Novo arquivo: ");
  scanf(" %[^\n]",Arq2);
  printf("L1: ");
  scanf("%d",&L1);
  printf("L2: ");
  scanf("%d",&L2);

  if (ArquivoInvertido(nomeArquivo,Arq2,L1,L2)==TRUE){
    printf("\n\tSucesso~");
  } else {
    printf("\n\t\tERRO!");
  }
  
  return 0;
}
