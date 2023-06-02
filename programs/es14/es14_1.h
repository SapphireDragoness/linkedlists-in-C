#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

Node *creaListaRicorsiva(int n);
void visualizzaListaRicorsiva(Node *head);
int sommaLista(Node *head); 
int lunghezzaLista(Node *head);
void contrarioLista(Node *head);
