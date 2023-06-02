#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 64

typedef struct node {
	char data[DIM];
	struct node *next;
}Node;

int lista_leggi_file(FILE *file, Node **head);
void lista_visualizza(Node *head);
int lista_vocali(Node *head, char vocMaiusc, char vocMinusc);
void salva_risultati(FILE *file, int a, int e, int i, int o, int u);

int main(int argc, char **argv) {
	if(argc != 2) {
		printf("Numero di argomenti non corretto\n");
		return -1;
	}
	
	int numNodi;
	Node *head = NULL;
	FILE *fp1; 
	fp1 = fopen(argv[1], "r");
	if(fp1 == NULL) {
		perror("Errore apertura file");
		return -1;
	}
	numNodi = lista_leggi_file(fp1, &head);
	if(numNodi < 0) {
		printf("Errore durante la creazione della lista");
		return -1;
	}
	printf("Numero nodi presenti: %d\n", numNodi);
	lista_visualizza(head);
	fclose(fp1);
	
	FILE *fp2;
	fp2 = fopen("risultatiSperimentazioni2.txt", "a");
	int a = lista_vocali(head, 'A', 'a');
	printf("A: %d\n", a);
	int e = lista_vocali(head, 'E', 'e');
	printf("E: %d\n", e);
	int i = lista_vocali(head, 'I', 'i');
	printf("I: %d\n", i);
	int o = lista_vocali(head, 'O', 'o');
	printf("O: %d\n", o);
	int u = lista_vocali(head, 'U', 'u');
	printf("U: %d\n", u);
	salva_risultati(fp2, a, e, i, o, u);
	fclose(fp2);
	
	return 0;
}

int lista_leggi_file(FILE *file, Node **head) {
	char str[DIM];
	int numNodi = 0;
	while(fscanf(file, "%s", str) != EOF) {
		Node *tail = *head;
		Node *newnode = malloc(sizeof(Node));
		if(newnode == NULL) {
			printf("Errore creazione nodo\n");
			return -1;
		}
		numNodi++;
		strcpy(newnode -> data, str);
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
	printf("%s -> ", head -> data);
	lista_visualizza(head -> next);
}

int lista_vocali(Node *head, char vocMaiusc, char vocMinusc) {
	int c = 0;
	if(head == NULL)
		return c;
	for(int i = 0; i < (int)strlen(head -> data); i++) {
		if(head -> data[i] == vocMaiusc || head -> data[i] == vocMinusc)
			c++;
	}
	return c + lista_vocali(head -> next, vocMaiusc, vocMinusc);
}

void salva_risultati(FILE *file, int a, int e, int i, int o, int u) {
	fprintf(file, "A: %d\n", a); 
	fprintf(file, "E: %d\n", e); 
	fprintf(file, "I: %d\n", i); 
	fprintf(file, "O: %d\n", o); 
	fprintf(file, "U: %d\n", u); 
	return;
}













