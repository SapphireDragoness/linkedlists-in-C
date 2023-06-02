#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data; 
	struct node *next;
}Node;

int lista_leggi_file(FILE *file, Node **head);
void lista_visualizza(Node *head);
int fattoriale(int n);
void salva_risultati(FILE *file, int f);

