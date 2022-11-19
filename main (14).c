#include <stdio.h>

//Desenvolver uma função que, dado um arquivo texto contendo números, determine se estes encontram-se ordenados crescentemente.

void preencheArquivo(FILE *arquivo){
  int i;
  for(i=1;i<=99;i++)
    fprintf(arquivo,"%d\n",i);
  fprintf(arquivo,"%d",i);
}

int verificaCrescente(FILE *arquivo){
  int n1,n2;
  while(fscanf(arquivo,"%d",&n1)!=EOF){
    if(fscanf(arquivo,"%d",&n2)!=EOF)
      if(n2<n1)
        return 0;
  }
  return 1;
}

int criaArquivo(char nomeArquivo[]){
  FILE *arquivo;
  printf("Digite o nome do arquivo a ser criado: ");
  scanf(" %[^\n]",nomeArquivo);
  arquivo=fopen(nomeArquivo,"w");
  if(arquivo){
    preencheArquivo(arquivo);
    fclose(arquivo);
    return 1;
  }
  return 0;
}

int leArquivo(char nomeArquivo[]){
  FILE *arquivo;
  printf("Digite o nome do arquivo a ser lido: ");
  scanf(" %[^\n]",nomeArquivo);
  arquivo=fopen(nomeArquivo,"r");
  if(arquivo){
    if(verificaCrescente(arquivo))
      printf("Os números estão em ordem crescente!\n");
    else
      printf("Os números não estão em ordem crescente!\n");
    fclose(arquivo);
    return 1;
  }
  return 0;
}

int main(void) {
	char nomeArquivo[50];

  //Criando o arquivo
  if(criaArquivo(nomeArquivo))
    printf("Arquivo criado com sucesso!\n");
  else
    printf("Erro na criação do arquivo!\n");

  //Verificando a ordem dos elementos
  if(!(leArquivo(nomeArquivo)))
    printf("Erro na leitura do arquivo!\n");
  
  
  return 0;
}