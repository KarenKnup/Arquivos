#include <stdio.h>

//lendo os dados de um arquivo, tratando-os como caracteres (por não saber a estrutura exata de seu conteúdo)

#define TRUE 0
#define FALSE 1

int lerArquivo (char nomeArq[]){
  //Declaração das variáveis
  FILE *arquivo;
  char caracter;

  //abrir o arquivo (associa a variável FILE à string que representa o arquivo / define o tipo de acesso)
  arquivo=fopen(nomeArq,"r"); //w - write    r - read    a - append

  	//testando se houve falha na abertura
    if (arquivo==NULL){
      return FALSE;
    } else {
   	//lendo os elementos do arquivo
      while (fscanf(arquivo,"%c",&caracter)!=EOF){ //EOF - End of File
        //exibindo na tela os valores lidos do arquiv
        printf("%c",caracter);
      }
      
      //Fechar arquivo
      fclose (arquivo);
      
      return TRUE;
    }
}

int main(void) {
  char nomeArquivo[50];

  printf("\nArquivo a ser lido: ");
  scanf(" %[^\n]",nomeArquivo);

  if (lerArquivo(nomeArquivo)==FALSE){
    printf("\n\tErro na leitura do arquivo!");
  } else {
    printf("\n\tArquivo lido com sucesso!");
  }
  
  return 0;
}