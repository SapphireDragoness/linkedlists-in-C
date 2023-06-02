#include <stdio.h>
#include <stdlib.h>

typedef struct STUDENTE
{
	char cognome[20];
	char nome[20];
	int anno_nascita;
}studente;

studente elenco[3];

void carica(studente A[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Cognome della persona %d\n",i);
		scanf("%s",&A[i].cognome);
		printf("Nome della persona %d\n",i);
		scanf("%s",&A[i].nome);
		printf("Anno di nascita della persona %d\n",i);
		scanf("%d",&A[i].anno_nascita);
	}
}

void stampa(studente A[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Cognome: %s \n",A[i].cognome);
		printf("Nome: %s \n",A[i].nome);
		printf("Anno di nascita: %d \n",A[i].anno_nascita);
	}
}

int main()
{
	int n=3;
	carica(elenco,n);
	stampa(elenco,n);
	return 0;
}
