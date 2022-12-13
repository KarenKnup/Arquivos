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

int ArquivoInvertido(char nomeArq[], int L1, int L2){
  char temporario[50]="tempo";
  FILE *arquivo, *temp;
  int cont=1, n, l=L2;
  //cont - contador de linhas
  //n - números sendo lidos no arquivo
  //l - linha que vai ser usada no busca e alterada -> L2 não pode ser alterada

  arquivo=fopen(nomeArq,"r");
  temp=fopen(temporario,"w");

  if ((!arquivo) || (!temp)){
    return FALSE;
  } else {
    while (fscanf(arquivo,"%d",&n)!=EOF){//transferindo os elementos entre L1 e L2 para "novo"
      if(cont>=L1 && cont<=L2){
        fprintf(temp,"%d\n",busca(nomeArq,l));
        l--;
      } else {
        fprintf(temp,"%d\n",n);
      }
      cont++;
    }

     if(cont<L1 || cont<L2 || L1<=0 || L2<=0){//se as linhas não existem na lista
      return FALSE;
    }
    
    fclose(temp);
    fclose(arquivo);
  } 

  
  arquivo=fopen(nomeArq,"w+");//w+ sobrescreve
  temp=fopen(temporario,"r");

  while (fscanf(temp,"%d",&n)!=EOF){//passa o que está no temporário de volta para o arquivo
    fprintf(arquivo,"%d\n",n);
  }

  fclose(temp);
  fclose(arquivo);
  
  return TRUE;
}

int main(void) {
  char nomeArquivo[50];
  int L1, L2;

  printf("\nArquivo a ser lido: ");
  scanf(" %[^\n]",nomeArquivo);
  printf("L1: ");
  scanf("%d",&L1);
  printf("L2: ");
  scanf("%d",&L2);

  if (ArquivoInvertido(nomeArquivo,L1,L2)==TRUE){
    printf("\n\tSucesso~");
  } else {
    printf("\n\t\tERRO!");
  }
  
  return 0;
}
