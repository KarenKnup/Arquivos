#include <stdio.h>

/*
Tudo se perde quando o programa termina a sua execução.

Isto acontece pois estas estruturas (structs, vetores, etc0) são manipuladas na memória principal, cujo armazenamento não é permanente.

Por outro lado, temos os Arquivos, que são estruturas manipuladas em disco e, portanto, conseguem armazenar os dados de maneira permanente, mesmo que o programa termine a sua execução.

Estes arquivos podem ser acessados de duas maneiras:
1- Sequencial, lendo um registro após o outro;
2- Aleatório, posicionando-se diretamente em um determinado registro.

A seguir são apresentadas as principais funções de manipulação de arquivos, presentes na biblioteca stdio.h:
- fopen: Abre um arquivo
- fclose: Fecha um arquivo
- putc ou fputc: Escreve um caracter em um arquivo
- getc ou fgetc: Lê um caractere de um arquivo
- fseek: Posiciona o cursor em determinado registro de um arquivo
- fprintf: Efetua impressão formatada em um arquivo
- fscanf: Efetua leitura formatada em um arquivo
- feof: Verifica o final de um arquivo
- fwrite: Escreve “vários” bytes de uma só vez em um arquivo
- fread: Lê “vários” bytes de uma só vez de um arquivo

Porém, antes de iniciar a manipulação de um arquivo com
as funções apresentadas anteriormente, é necessário que
uma variável seja declarada, evidenciando que estará
associada a um arquivo.

FILE *arq;

Com esta declaração, temos uma variável chamada arq,
que é um ponteiro para o arquivo a ser manipulado.

Abertura de Arquivos:
- "r": Abre um arquivo texto para leitura.
O arquivo deve existir antes de ser aberto.
- "w": Abre um arquivo texto para gravação.
Se o arquivo não existir, ele será criado. Se já existir, o conteúdo
anterior será destruído.
- "a": Abre um arquivo texto para gravação; porém, os dados serão adicionados no fim do arquivo (append), se ele já existir, ou um novo arquivo será criado.
- "rb": Abre um arquivo binário para leitura (equivalente ao modo “r”, porém aplicado a arquivos binários).
- "wb": Abre um arquivo binário para gravação (equivalente ao modo “w”,
porém aplicado a arquivos binários).
- "ab": Abre um arquivo binário para gravação; porém, os dados serão
adicionados no fim do arquivo (equivalente ao modo “a”, porém aplicado
a arquivos binários).
*/

#define TRUE 1
#define FALSE 0

int gerarArquivo (int n, char nomeArq[]){
  //Declaração de variáveis
  int i;
  FILE *arquivo;  //1. Declarar uma variável do tipo FILE*
		
	//2. Abrir o arquivo (associa a variável FILE à string que representa o arquivo / define o tipo de acesso)
	arquivo = fopen (nomeArq, "w");  //w - write / r - read / a - append

  //Testando se houve falha na abertura do arquivo
  if (arquivo==NULL){
    return FALSE;
  } else {
    //Escrevendo os números de 1 a N no arquivo
    for (i=1; i<=n; i++){
      fprintf(arquivo, "%d\n",i); //3. Manipular o arquivo
    }

    //4. Fecha arquivo
    fclose(arquivo);
    
    return TRUE;
  }
  
}

int main(void) {
//Declaração de variáveis 
  int n;
  char nomeArq[20];

  //Lendo o valor de N
  printf("\nQual o valor de N: ");
  scanf("%d",&n);

  //Lendo o nome do arquivo
  printf("Nome do arquivo a ser criado: ");
  scanf(" %[^\n]",nomeArq);

  //Chamando a função
    if (gerarArquivo(n,nomeArq)==FALSE){
      printf("\n\tErro na criação do arquivo!");
    } else {
      printf("\n\tArquivo criado com sucesso!");
    }
  
  return 0;
}