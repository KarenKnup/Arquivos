#include <stdio.h>

/* Dado um arquivo texto e dois inteiros posA e 
posB, desenvolver uma função que remova do 
arquivo o bloco de caracteres delimitados pelas 
posições posA e posB.

Notas:
1. Suponha que o valor de posA é menor ou 
igual ao de posB;
2. Considere que o primeiro caracter do arquivo 
encontra-se na posição 0;
3. Se não existir a posição posA no arquivo, o 
seu conteúdo será preservado;
4. Se não existir a posição posB no arquivo, 
serão removidos todos os caracteres da 
posição posA ao final do arquivo.
*/

#define TRUE 0
#define FALSE 1

int busca(char nomeArq[], int l){//procura uma linha em um arquivo (arquivo com um número por linha)
  FILE *arq;
  int n, cont=0;//contador de linhas -> cont

    arq=fopen(nomeArq,"r");

  if(!arq){
    return FALSE;
  } else {
    while (fscanf(arq,"%d",&n)!=EOF){
      if (cont==l){
        fclose(arq);
        return TRUE;
      }
      cont++;
    }
  }
}

int totalLinhas (char nomeArq[]){
  int l=0, n;
  FILE *arq;

  arq=fopen(nomeArq,"r");

  if(!arq){
    printf("\n\tEsse arquivo não existe!");
    return -1;
  } else {
    while(fscanf(arq,"%d",&n)!=EOF){
      l++;
    }
    return l;
  }
}

int Remove (char nomeArq[],int posA, int posB){
  FILE *arquivo, *temp;
  char temporario[50]="tempo";
  int n, l=0;

  arquivo=fopen(nomeArq,"r");
  temp=fopen(temporario,"w");

  if(!arquivo || !temp || busca(nomeArq,posA)==FALSE){
    return FALSE;
  } else {
      while(fscanf(arquivo,"%d",&n)!=EOF){
           if(l<posA || l>posB){
             fprintf(temp,"%d\n",n);
           } 
  
        l++;
      }
  
      fclose(arquivo);
      fclose(temp);
  
      arquivo=fopen(nomeArq,"w+");
      temp=fopen(temporario,"r");
  
      while(fscanf(temp,"%d",&n)!=EOF){
        fprintf(arquivo,"%d\n",n);
      }
  
      fclose(arquivo);
      fclose(temp);
      remove(temporario);
  
      return TRUE;
    }
} 

int main(void) {
  int posA, posB;
  char nomeArq[50];

  printf("\nQual arquivo: ");
  scanf(" %[^\n]",nomeArq);

  printf("Posição A: ");
  scanf("%d",&posA);
  
  printf("Posição B: ");
  scanf("%d",&posB);

   while(posA>posB){
     printf("A posição A deve ser menor que B! Posição B: ");
      scanf("%d",&posB);
   }

   if(busca(nomeArq,posA)==FALSE && busca(nomeArq,posB)==TRUE){
    posB=posA;//Nota 3
  } 

  if(busca(nomeArq,posB)==FALSE){
    posB=totalLinhas(nomeArq);
  }
  
    if(Remove(nomeArq,posA,posB)==TRUE){
      printf("\n\n\tRemoção feita com sucesso!");
    } else {
      printf("\n\n\tERRO!");
    }
  
  
  return 0;
}
