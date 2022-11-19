/*
  Faça uma função que, dado um arquivo A contendo números reais, 
	um por linha, crie um novo arquivo B contendo os mesmos elementos 
	de A, porém ordenados decrescentemente e sem repetição.
  */

#include <stdio.h>
#include <limits.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

  int criaArquivoOrdenado(char original[], char novo[]){
    FILE *arquivo, *arquivo2;
    int anterior, valor, maior, fim;

  //Abrindo os arquivos
  arquivo=fopen(original,"r");
  arquivo2=fopen(novo,"w");

  //Testando se houve erro na abertura
  //if ((orig == NULL) || (novo == NULL))
    if ((!arquivo) || (!arquivo2)){
      fclose(arquivo);
      fclose(arquivo2);
        return FALSE;
    } else {
      anterior=INT_MAX;
      fim=FALSE;

      while(fim==FALSE){
        maior=INT_MIN;
        while(fscanf(arquivo,"%d",&valor)!=EOF){
          //verificando se o valor lido é menor do que o último número inserido no novo arquivo (ou seja, o valor de 'anterior')
          if (valor<anterior){
     					//verificando se é o maior
              if(valor>maior){
                //atualizando o maior valor
                maior=valor;
              }
          }
        }

  			//verificando se foi encontrado um novo elemento a ser inserido no novo arquivo
        if(maior!=INT_MIN){
    	//escrevendo o valor no novo arquivo
          fprintf (novo, "%d\n", maior);
				
				//atualizando o 'anterior'
				anterior = maior;
				
				//reposicionando o cursor de leitura no início do arquivo
				rewind (orig);
        } else {
          //não há mais elemento a inserir no novo arquivo
				    fim = TRUE;
        }

      }

      //fechando os arquivos
		fclose (orig);
		fclose (novo);
		
		return TRUE;
    }
  }

int main(void) {
  //Declaração de variáveis
  char original[50], novo[50];
  int r;

  //Leitura dos nomes dos arquivos
  printf("\nArquivo a ser lido: ");
  scanf(" %[^\n]",original);
  printf("Nome do novo arquivo: ");
  scanf(" %[^\n]",novo);

  //Chamando a função
  r=criaArquivoOrdenado(original,novo);

  //Testando o retorno da função
    if(r==FALSE){
      printf("\n\tErro de abertura!");
    } else{
      printf("\n\tArquivo gerado com sucesso!");
    }

    return 0;
}