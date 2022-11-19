/*
Desenvolver uma função que, dado um arquivo texto	contendo números inteiros - um por linha, remova do arquivo todas as ocorrências de determinado valor 'num'.
  */

#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

int copiarArquivo (char origem[], char destino[]){
	//declaração de variáveis
	FILE *arqO, *arqD;			//1. declarar uma variável do tipo FILE*
	char caracter;
		
	//2.abrir o arquivo (associa a variável FILE à string que representa o arquivo / define o tipo de acesso)
	arqO = fopen (origem, "r");
	arqD = fopen (destino, "w");
	
	//testando se houve falha na abertura
	if ((arqO == NULL) || (arqD == NULL))	{
		fclose (arqO);
		fclose (arqD);
		
		return FALSE;
    }	else {
		//lendo os elementos do arquivo de origem
		while (fscanf (arqO, "%c", &caracter) != EOF)    //EOF - End Of File
      {
			//escrevendo no arquivo de destino os valores lidos do arquivo de origem
			fprintf (arqD, "%c", caracter);
		}
		
		//4. fechar os arquivos
		fclose (arqO);
		fclose (arqD);
		
		return TRUE;
	}
}

int removerElementoArquivo (char nomeArq[], int numero)
/*
	retornará:
		-1	erro na abertura do arquivo
		0	o elemento não existe no arquivo
		outro valor:	representará quantas remoções foram feitas	
*/
{
	//declaração de variáveis
	FILE *arq, *tmp;
	int valor, cont = 0;
	
	//abrindo os arquivos
	arq = fopen (nomeArq, "r");
	tmp = fopen ("temp.txt", "w");
	
	//verificando se houve erro na abertura dos arquivos
	//if ((arq == NULL) || (tmp == NULL))	
	if ((!arq) || (!tmp))	{
		fclose (arq);
		fclose (tmp);
		
		return -1;
	}	else	{
		//lendo os elementos do arquivo original
		while (fscanf (arq, "%d", &valor) != EOF)	{
			//verificando se o valor lido não é aquele que deseja-se remover
			if (valor != numero){
				fprintf (tmp, "%d\n", valor);
			}	else {
				cont++;
			}
		}
		
		//fechando os arquivos
		fclose (arq);
		fclose (tmp);

		//copiando o arquivo temporário para o original		
		copiarArquivo ("temp.txt", nomeArq);
		
		//retornando a quantidade de remoções realizadas
		return cont;
	}
}

int main(void) {
//declaração de variáveis
	char nomeArq[20];
	int num, resp;
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser lido: ");
	scanf(" %[^\n]",nomeArq);
	
	//lendo o número a ser removido do arquivo
	printf ("\nEntre com o valor a ser removido: ");
	scanf ("%d", &num);
	
	//chamando a função
	resp = removerElementoArquivo (nomeArq, num);
	
	//testando o retorno da função
	switch (resp)	{
		case -1: printf ("\n\nErro na abertura do arquivo!");
		         break;
		         
		case 0:  printf ("\n\nO valor %d nao existe no arquivo!", num);
		         break;
		
		default: printf ("\n\nO valor %d foi removido %d vezes do arquivo!", num, resp);
	}
  
  return 0;
}