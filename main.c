#include <stdio.h>
/*

arquivo - sistema de armazenamento - começa no dia seguinte de onde parou, início de banco de dados

  */
int main(void) {
  int n;
  
  //Declaração
  FILE *arq;
  FILE *arq2; //aponta p o endereço de memória q o arquivo está

  //Abertura do arquivo = associa file a uma string (caminho p o arquivo) = modo de abertura do arquivo
  arq=fopen("nomeArq","w"); //w-write(conteúdo é perdido, diferente do append ao abrir) /r-read/ a-append
    
  arq2=fopen("numeros.txt","r");

  //Manipular o arquivo
    for (n=1;n<=100; n++){
  fprintf(arq,"%d",n);
      }

  fscanf(arq2,"%d",&n);

  //Fechar o arquivo
  fclose(arq);
  
  return 0;
}