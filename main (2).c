#include <stdio.h>

//Diferente de "w" -- - "a": Abre um arquivo texto para gravação; porém, os dados serão adicionados no fim do arquivo (append), se ele já existir, ou um novo arquivo será criado.

#define TRUE 1
#define FALSE 0

int geraArquivo (int n, char nomeArq[]){
  int i;
  FILE *arquivo; //1. declarar uma variável do tipo FILE*
		
	//2.abrir o arquivo (associa a variável FILE à string que representa o arquivo / define o tipo de acesso)
  arquivo = fopen (nomeArq,"a"); //w - write    r - read    a - append

  //Testando se houve falha na abertura
  if (arquivo==NULL){
    return FALSE;
  } else {
    for (i=1; i<=n; i++){
      fprintf(arquivo,"%d\n",i); //3. manipular o arquivo
    }

    //Fechar o arquivo
    fclose (arquivo);
    
    return TRUE;
  }
}

int main(void) {
  int n;
  char nomeArquivo[50];

  printf("\nValor de N: ");
  scanf("%d",&n);
  printf("Nome do arquivo: ");
  scanf(" %[^\n]",nomeArquivo);

  if (geraArquivo(n,nomeArquivo)==TRUE){
    printf("\n\tArquivo criado com sucesso!");
  } else {
    printf("\n\tFalha na criação do arquivo!");
  }
  
  
  return 0;
}