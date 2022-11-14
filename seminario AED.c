/******************************************************************************

Elabore um programa que, considerando um vetor de 10 posi��es de
inteiros, apresente as seguintes op��es de opera��es para o usu�rioi:
1- Preencher o vetor
2- Buscar por um valor:
a) tipo de busca 1 (a definir)
b) tipo de busca 2 (a definir)
3- Ordenar o vetor:
a) tipo de ordena��o 1 (a definir)
b) tipo de ordena��o 2 (a definir)
4- Sair

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define N 3

//fun��o para cadastrar os numeros do vetor
void cadastra_vet (int * vet)
{
  int i;
  for (i = 0; i < N; i++)
    {
      printf ("Entre com o numero do vetor: ");
      scanf ("%d", &vet[i]);
      fflush(stdin);
    }
}



//fun��o para imprimir o vetor
void imprime_vet (int *vet)
{
  int i;
  for (i = 0; i < N; i++)
    printf ("%d ", vet[i]);
}

//fun��o para buscar um elemento na lista
void busca (int * vet){
    int i;
    int x;

    printf ("Entre com o numero: ");
    scanf ("%d", &x);

    for (i = 0; i < N; i++)
    {
        if (vet[i] == x)
        {
            printf("Elemento na posicao %d", i);
            break;
        }            
	}

    if(i == N)
    {
        printf("\nElemento nao encontrado");
    }
}

//fun��o para busca binaria

int busca_binaria (int * vet, int x){
    return 0;
}



// fun��o para ordenar um vetor
void selectionSort(int*vet){
	int i,j,menor,troca;
	for (i=0;i<N-1;i++){
		menor=i;
		for (j=i+1;j<N;j++){
			if(vet[j]<vet[menor])
				menor=j;
			}
				if (menor != i){
				troca=vet[i];
				vet[i]=vet[menor];
				vet[menor]=troca;
			}
		}
	}



//fun��o ordenar o vetor

int ordenado_vet (int *vet)
{
  int i;
  for (i = 0; i < N; i++)
    if (vet[i] <= vet[i - 1])
      return 1;
    else
      return -1;
}



//menu de op��es

int menu()
{
    int op;

    printf ("\n\n ==== MENU DE OPCOES ====\n");
    printf ("0 - SAIR \n");
    printf ("1 - DIGITAR OS ELEMENTOS DO VETOR \n");
    printf ("2 - BUSCAR POR UM ELEMENTO DO VETOR \n");
    printf ("3 - ORDENAR O VETOR \n");
    printf ("\nO que deseja fazer? ");
    scanf ("%d", &op);
    fflush(stdin);

    return op;
}


int main()
{
    int x;
    int vet[N];
    int op;
    int op_busca;
  
  do
    {
      op = menu();
      switch (op)
	    {
        case 0:		//c�digo para sair
        break;

        case 1:		//c�digo para cadastrar
        {
            cadastra_vet(vet);
            printf("\nO vetor digitado foi: ");
            imprime_vet (vet);
            break;
        }

        case 2:		//buscar elemento de um vetor
        {
            do 
            {
                printf("digite 1 para busca simples e 2 para busca binaria: ");
                scanf("%d", &op_busca);

            }while (op_busca < 1 && op_busca > 2);
            
            if (op_busca == 1)
                busca(vet);

            if (op_busca == 2)
            {
                selectionSort(vet);
                busca_binaria (vet,x);
            }
            break;
        }
        
        
        case 3:		//ordenar um elemento do vetor
        {
            selectionSort(vet);
            imprime_vet (vet);
            break;
        }

            default:    //op��o inv�lida
            printf ("\n----- OPCAO INVALIDA -----");
            }
    }while (op != 0);

    return 0;
}
