#include <stdio.h>

#define TRUE 0
#define FALSE 1

 int busca(char nomeArq[], int l){//Arquivos com 1 número/caractere por linha
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

int main(void) {
  char nomeArq[20];
  int l;

  //Lendo o nome do arquivo
  printf("Arquivo: ");
  scanf(" %[^\n]",nomeArq);
  printf("Linha: ");
  scanf("%d",&l);

  printf("%d",busca(nomeArq,l));
  
  return 0;
}
