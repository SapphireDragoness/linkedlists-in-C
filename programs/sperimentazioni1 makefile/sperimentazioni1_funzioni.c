#include "sperimentazioni1_header.h"

int lista_leggi_file(FILE *file, Node **head) {
	int dato, numNodi = 0;
	while(fscanf(file, "%d", &dato) != EOF) {
		Node *tail = *head;
		Node *newnode = malloc(sizeof(Node));
		numNodi++;
		if(newnode == NULL) {
			printf("Creazione nodo fallita\n");
			return -1;
		}
		newnode -> data = dato;
		newnode -> next = NULL;
		if(*head == NULL)
			*head = newnode;
		else {
			while(tail -> next != NULL)	
				tail = tail -> next;
			tail -> next = newnode;
		}
	}
	return numNodi;
}

void lista_visualizza(Node *head) {
	if(head == NULL) {
		printf("NULL\n");
		return;
	}
	printf("%d -> ", head -> data);
	lista_visualizza(head -> next);
}

int fattoriale(int n) {
	if(n <= 1)
		return 1;
	return n * fattoriale(n - 1);
}

void salva_risultati(FILE *file, int f) {
	fprintf(file, "%d\n", f);
	return;
}