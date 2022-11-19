#include <stdio.h>
#include <limits.h>

/*
  Desenvolver uma função que, dados dois arquivos textos arqA e arqB, crie um novo arquivo arqC, considerando que:
--  arqA e arqB contém números reais, um por linha, ordenados
crescentemente e sem repetição no arquivo;
--  arqC deve conter todos os números dos dois arquivos originais;
-- Assim como arqA e arqB, arqC também não possuirá repetições de elementos e estes deverão estar ordenados de forma crescente.
*/

#define TRUE 0
#define FALSE 1

int criaArquivoOrdenado (char arqA[], char arqB[], char arqC[]){
  FILE *arquivoA, *arquivoB, *arquivoC;
  int anterior, valor, menor, fim;
  
  arquivoA=fopen(arqA,"r");
  arquivoB=fopen(arqB,"r");
  arquivoC=fopen(arqC,"w");

  if ((!arquivoA) || (!arquivoB) || (!arquivoC)){
    fclose(arquivoA);
    fclose(arquivoB);
    fclose(arquivoC);
      return FALSE;
  } else {
    anterior=INT_MIN;
    fim=FALSE;

    while(fim==FALSE){
      menor=INT_MAX;
      while((fscanf(arquivoA,"%d",&valor)!=EOF) &&(fscanf(arquivoB,"%d",&valor)!=EOF)){
        //verificando se o valor lido é maior do que o último número inserido no novo arquivo (ou seja, o valor de 'anterior')
        if (valor>anterior){
          //verificando se é o menor
          if (valor<menor){
            menor=valor;
          }
        }
      }
    }

    //verificando se foi encontrado um novo elemento a ser inserido no novo arquivo
    if (menor!=INT_MAX){
   	//escrevendo o valor no novo arquivo
      fprintf(arquivoC,"%d\n",menor);
      
      //atualizando o 'anterior'
				anterior = menor;

      //reposicionando o cursor de leitura no início do arquivo
				rewind (arquivoA);
        rewind (arquivoB);
    } else {
      //não há mais elemento a inserir no novo arquivo
				    fim = TRUE;
    }

    fclose(arquivoA);
    fclose(arquivoB);
    fclose(arquivoC);
      return TRUE;
  }
}

int main(void) {
  char nomeArquivoA[50], nomeArquivoB[50], nomeArquivoC[50];
  int r;

  printf("\nArquivo A a ser lido: ");
  scanf(" %[^\n]",nomeArquivoA);
  printf("Arquivo B a ser lido: ");
  scanf(" %[^\n]",nomeArquivoB);
  printf("Nome do novo Arquivo C: ");
  scanf(" %[^\n]",nomeArquivoC);

  //Chamando a função
  r=criaArquivoOrdenado(nomeArquivoA,nomeArquivoB,nomeArquivoC);

  //Testando o retorno da função
    if(r==FALSE){
      printf("\n\tErro de abertura!");
    } else{
      printf("\n\tArquivo gerado com sucesso!");
    }
  
  return 0;
}