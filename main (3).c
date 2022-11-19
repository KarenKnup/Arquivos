#include <stdio.h>

#define TRUE 0
#define FALSE 1

int lerArquivo (char nomeArq[]){
  FILE *arquivo;
  int numero;

  //abrir o arquivo (associa a variável FILE à string que representa o arquivo / define o tipo de acesso)
  arquivo=fopen(nomeArq,"r"); //w - write    r - read    a - append

  	//testando se houve falha na abertura
    if (arquivo==NULL){
      return FALSE;
    } else {
      //lendo os elementos do arquivo
      while (fscanf(arquivo,"d",&numero)!=EOF){ //EOF - End Of File
        //exibindo na tela os valores lidos do arquivo
			  printf ("%d\n", numero);
      }

      //Fechar arquivo
      fclose(arquivo);
      
      return TRUE;
    }
  }

int main(void) {
  char nomeArquivo[50];

  printf("\nNome do arquivo a ser lido: ");
  scanf(" %[^\n]",nomeArquivo);

  if (lerArquivo(nomeArquivo)==FALSE){
    printf("\n\tErro na abertura do arquivo!");
  } else {
    printf("\n\tArquivo aberto com sucesso!");
  }
  
  return 0;
}