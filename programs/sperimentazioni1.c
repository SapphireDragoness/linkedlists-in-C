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

int main(int argc, char **argv) {
	if(argc != 2) {
		printf("Numero argomenti errato");
		return -1;
	}
	Node *head = NULL;
	int numNodi;
	FILE *fp1, *fp2;
	fp1 = fopen(argv[1], "r");
	numNodi = lista_leggi_file(fp1, &head);
	if(numNodi <= 0) {
		printf("Problema durante la creazione della lista");
		return -1;
	}
	fclose(fp1);
	printf("Numero nodi presenti: %d\n", numNodi);
	lista_visualizza(head);
	Node *temp = head;
	fp2 = fopen("risultati.txt", "a");
	for(int i = 0; i < numNodi; i++) {
		int f = fattoriale(temp -> data);
		printf("Fattoriale di %d: %d\n", temp ->data, f);
		salva_risultati(fp2, f);
		temp = temp -> next;
	}
	return 0;
}

int lista_leggi_file(FILE *file, Node **head) {
	int dato, numNodi = 0;
	while(fscanf(file, "%d", &dato) != EOF) {
		Node *tail = *head;
		Node *newnode = malloc(sizeof(Node));
		numNodi++;
		if(newnode == NULL) {
			printf("Creazione nodo fallita.");
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