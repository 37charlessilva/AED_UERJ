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
#include <conio.h>
#define N 3

//fun��o para cadastrar os numeros do vetor
void cadastra_vet (int *vet)
{
  int i;
  for (i = 0; i < N; i++)
    {
      printf ("entre com o numero do vetor;");
      scanf ("%d", &vet[i]);
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
void busca (int*vet, int x){
    printf ("entre com o numero");
    scanf ("%d", &x);
    int i;
    for (i = 0; i < N; i++)
    {
	if (vet[i]==x)
    	{printf("\n elemento na posicao %d",i);
    	break;}
    else if (i==(N-1))
    	printf("\n elemento nao encontrado");
	}
}

//fun��o para busca binaria

int busca_binaria (int*vet, int x){
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

int menu ()
{
  int op;

  printf ("\n\n ==== MENU DE OPCOES ====\n");
  printf ("0 - SAIR \n");
  printf ("1 - DIGITAR OS ELEMENTOS DO VETOR \n");
  printf ("2 - BUSCAR POR UM ELEMENTO DO VETOR \n");
  printf ("3 - ORDENAR O VETOR \n");
  printf ("\nO que deseja fazer? ");
  scanf ("%d", &op);

  return op;
}


int
main ()
{
  int x;
  int vet[N];
  int op;
  char op_busca;
  
  
  
  do
    {
      op = menu ();
      switch (op)
		{
	case 0:		//c�digo para sair
	  break;

	
	
	case 1:		//c�digo para cadastrar

	  {
	    cadastra_vet (vet);
	    printf("\nO vetor digitado foi: ");
	    imprime_vet (vet);
	    break;
	  }

		case 2:		//buscar elemento de um vetor
	  {
	    do {
	        printf("digite 'a' para busca simples e 'b' para busca binaria");
	    	op_busca=getche();
	        
	    }while (op_busca!='a'||op_busca!='b');
		
		if (op_busca=='a')
			busca (vet,x);
		if (op_busca=='b'){
			selectionSort(vet);
			busca_binaria (vet,x);}
	    break;
	  }
	  
	
	  case 3:		//ordenar um elemento do vetor
	  {
	    selectionSort(vet);
		imprime_vet (vet);
	    break;
	  }

		default:    //op��o inv�lida
	  	printf ("----- OPCAO INVALIDA -----");
		}
    }
  while (op != 0);

  return 0;

}
