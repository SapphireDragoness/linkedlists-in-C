#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int data;
	struct nodo *next;
}Nodo;

int lista_leggi_file(Nodo **testa, FILE *fp);
void lista_crea(Nodo **testa, int num);
unsigned long long int fattoriale(int n);
void lista_visualizza(Nodo *testa);
void salva_risultati(char *file, unsigned long long int n);