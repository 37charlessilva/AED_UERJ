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
#define N 4
int particiona(int*vet, int inicio, int final);
//funcao para cadastrar os numeros do vetor
void cadastra_vet (int *vet)
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf ("Entre com o numero do vetor: ");
		scanf ("%d", &vet[i]);
	}
}

//funcao para cadastrar os numeros do vetor
int cadastra_elem()
{
	int x;
	printf("Entre com elemento desejado ");
	scanf("%d", &x);
	return x;
}



//funcao para imprimir o vetor
void imprime_vet(int *vet)
{
	int i;
	for (i = 0; i < N; i++)
	printf ("%d ", vet[i]);
}

//funcao para buscar um elemento na lista.
int busca(int * vet, int x){
	int i;
	for (i = 0; i < N; i++)
	{
		if (x == vet[i])
			return i;
	}
	return -1;
}

//funcao para busca binaria
int buscaBinaria(int * vet, int elem){
	int i, inicio, meio, final;
	inicio = 0;
	final = N-1;
	while(inicio<=final)
	{
		meio = (inicio+final)/2;
		if (elem<vet[meio])
			final = meio-1;
		else 
			if (elem>vet[meio])
				inicio = meio +1;
			else 
				return meio;
	}
	
return -1;	
	
}



// funcao para ordenar um vetor
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



//procedimento resultado da busca

void resultado_busca(int res, int x){

	if (res < 0)
		printf ("\nO elemento procurado nao esta na lista");
	else 
		printf ("\nO elemento %d esta na posicao %d", x, res);
}

//procedimento quickSort
void quickSort(int*vet, int inicio, int fim){
	int pivo;
	if (fim>inicio){
		pivo = particiona(vet, inicio, fim);
		quickSort(vet, inicio, pivo-1);
		quickSort(vet, pivo+1, fim);
	}
}

int particiona(int*vet, int inicio, int final){
	int esq, dir, pivo, aux;
	esq=inicio;
	dir=final;
	pivo=vet[inicio];
	while (esq<dir){
		while (vet[esq]<=pivo)
			esq++;
		while (vet[dir]>pivo)
			dir--;
		if (esq<dir){
			aux=vet[esq];
			vet[esq]=vet[dir];
			vet[dir]=aux;
		}
	}
	vet[inicio]=vet[dir];
	vet[dir]=pivo;
	return dir;
}


//menu de op��es

int menu ()
{
	int op;

	printf ("\n\n ==== MENU DE OPCOES ====\n");
	printf ("0 - SAIR \n");
	printf ("1 - DIGITAR OS ELEMENTOS DO VETOR \n");
	printf ("2 - IMPRIMIR O VETOR \n");
	printf ("3 - BUSCAR POR UM ELEMENTO DO VETOR PELA BUSCA SIMPLES\n");
	printf ("4 - BUSCAR POR UM ELEMENTO DO VETOR PELA BUSCA BINARIA\n");
	printf ("5 - ORDENAR O VETOR POR SELECTIONSORT\n");
	printf ("6 - ORDENAR O VETOR POR QUICKSORT\n");
	printf ("\nO que deseja fazer? ");
	scanf ("%d", &op);

	return op;
}


int
main ()
{
	int res;
	int op;
	int vet[N] = {3, 4, -5, 2};
	int x;
	int inicio=0;
	int fim =N-1;
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
		break;
		}

	case 2:		//Imprimir o vetor
		{
		imprime_vet(vet);
		break;
		}
		
	case 3:		//busca de um elemento no vetor por busca simples
		{
		x = cadastra_elem();
		busca(vet, x);
		res = busca(vet, x);
		resultado_busca(res, x);
		break;
		}
		
	case 4:		//busca de um elemento no vetor por busca binaria
		{
		int x;
		printf("Entre com elemento desejado ");
		scanf("%d", &x);
		selectionSort(vet);
		res = buscaBinaria(vet,x);
		printf("\nO vetor foi ordenado para a busca binaria.\nVetor: ");
		imprime_vet(vet);
		resultado_busca(res, x);
		break;
		} 
		
	case 5:		//ordenar o vetor por selectionSort
		{
		selectionSort(vet);
		imprime_vet(vet);
		break;
		}  
		
	case 6:		//ordenar o vetor por quickSort
		{
		quickSort(vet, inicio, fim);
		break;
		}   
		
	default:    //op��o inv�lida
		printf ("----- OPCAO INVALIDA -----");
		}
	}
	while (op != 0);

	return 0;
}

