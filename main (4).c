#include <stdio.h>

#define TRUE 0
#define FALSE 1

int copiarArquivo (char origem[], char destino[]){
  //Declaração de variáveis
  FILE *arqO, *arqD;
  char caracter;

  //abrir o arquivo (associa a variável FILE à string que representa o arquivo / define o tipo de acesso)
  arqO=fopen(origem,"r");
  arqD=fopen(destino,"w");

  	//testando se houve falha na abertura
    if ((arqO==NULL) || (arqD==NULL)){
      return FALSE;
    } else {
      //lendo os elementos do arquivo de origem
      while (fscanf(arqO,"%c",&caracter)!=EOF){  //EOF - End Of File
        			//escrevendo no arquivo de destino os valores lidos do arquivo de origem
        fprintf(arqD,"%c",caracter);
      }

      //Fechar arquivos
      fclose(arqO);
      fclose (arqD);
      
      return TRUE;
    }
}

int main(void) {
//Declaração de variáveis
  char nomeOrigem[50], nomeDestino[50];

  //Lendo nome dos arquivos
  printf("\nNome do arquivo a ser copiado: ");
  scanf(" %[^\n]",nomeOrigem);
  printf("\nNome do arquivo a ser gerado: ");
  scanf(" %[^\n]",nomeDestino);

  //Chamando a função
  if (copiarArquivo(nomeOrigem,nomeDestino)==FALSE){
    printf("\n\tFalha na cópia de arquivo!");
  } else {
    printf("\n\tArquivo copiado com sucesso!");
  } 
  
  return 0;
}