/*
Supondo a existência de um arquivo texto contendo números inteiros, um por linha, sem repetições, desenvolver uma função que determine o maior e o segundo maior elementos do arquivo.
  */

#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

/* int CriaArquivo (char nomeArq[]){
  FILE *arquivo;
  int n=5;

  arquivo=fopen(nomeArq,"w");

  if(!arquivo){
    return FALSE;
  } else {
    for(int i=1; i<=n; i++){
      fprintf(arquivo, "%d\n",i);
    }
    
    fclose(arquivo);

    return TRUE;
  }
} */

int Maiores (char nomeArq[]){
  FILE *arquivo;
  int n, n2, maior=-1, maior2=-1;

  arquivo=fopen(nomeArq,"r");

  if(!arquivo){
    return FALSE;
  } else {
    while(fscanf(arquivo,"%d\n",&n)!=EOF){
      if(n>maior){
        maior=n;
        }
      }

    rewind(arquivo);

    while(fscanf(arquivo,"%d\n",&n)!=EOF){
      if(n>maior2 && n<maior){
        maior2=n;
        }
      }

    printf("\n\tPrimeiro maior: %d",maior);
    printf("\n\tSegundo maior: %d",maior2);

    fclose(arquivo);
    return TRUE;
  }
}

int main(void){
  char nomeArq[50];

  printf("\nNome do arquivo: ");
  scanf(" %[^\n]",nomeArq);
  
  /*if(CriaArquivo(nomeArq)==TRUE){
    printf("\n\tArquivo criado com sucesso!");
  } else {
    printf("\n\tERRO! Arquivo não foi criado!");
  }*/

  Maiores(nomeArq);
  
  return 0;
}