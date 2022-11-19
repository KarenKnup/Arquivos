/*
  Faça uma função que, dado um arquivo A contendo números reais, 
	um por linha, crie um novo arquivo B contendo os mesmos elementos 
	de A, porém ordenados decrescentemente e sem repetição.
  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50
#define VETOR 200

FILE *arquivo,*arquivo2;

int geraAleatorio(int a,int b){
  return (rand()%(b-a+1))+a;
}

void preencheArquivo(FILE *arquivo){
  int i;
  for(i=0;i<99;i++)
    fprintf(arquivo,"%.1f\n",geraAleatorio(0,1000)/10.0);
  fprintf(arquivo,"%.1f",geraAleatorio(0,1000)/10.0);
}

int criaArquivo(char nomeArquivo[]){
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

int buscaNum(int n,float p,float v[]){
  int i;
  for(i=0;i<n;i++){
    if(v[i]==p)
      return i;
  }
  return -1;
}

int filtraVetor(int n,float v2[],float v1[]){
  int i,k=0,pos;
  for(i=0;i<n;i++){
    pos=buscaNum(k,v1[i],v2);
    if(pos==-1){
      v2[k]=v1[i];
      k++;
    }
  }
  return k;
}

void ordenaVetorRec(int p,int n,float v[]){
  int i;
  float temp;
  if(p<n){
    for(i=p+1;i<n;i++){
      if(v[p]>v[i]){
        temp=v[p];
        v[p]=v[i];
        v[i]=temp;
      }
    }
    ordenaVetorRec(p+1,n,v);
  }
}

void ordenaVetor(int n,float v[]){
  ordenaVetorRec(0,n,v);
}

int processaArquivo(char nomeArquivo[]){
  float n,num[VETOR],num2[VETOR];
  int i,k=0;
  printf("Digite o nome do arquivo a ser lido: ");
  scanf(" %[^\n]",nomeArquivo);
  arquivo=fopen(nomeArquivo,"r");
  if(arquivo){
    printf("Arquivo lido com sucesso!\n");
    while(fscanf(arquivo,"%f",&n)!=EOF){
      num[k]=n;
      k++;
    }
    fclose(arquivo);
    printf("Digite o nome do novo arquivo a ser criado: ");
    scanf(" %[^\n]",nomeArquivo);
    arquivo2=fopen(nomeArquivo,"w");
    if(!arquivo2)
      return 0;
    else{
      printf("Novo arquivo criado com sucesso!\n");
      k=filtraVetor(k,num2,num);
      ordenaVetor(k,num2);
      k--;
      for(i=k;i>=1;i--)
        fprintf(arquivo2,"%.1f\n",num2[i]);
      fprintf(arquivo2,"%.1f",num2[i]);
      fclose(arquivo2);
    }
    return 1;
  }
  return 0;
}

int main(void) {
  srand(time(NULL));
  char nomeArquivo[TAM];
  /*
  if(criaArquivo(nomeArquivo))
    printf("Arquivo criado com sucesso!\n");
  else
    printf("Erro na criação do arquivo!\n");
  */
  if(!(processaArquivo(nomeArquivo)))
    printf("Erro na leitura do arquivo ou na gravação do arquivo novo!\n");
  return 0;
}