//legge stringa da argomento, la mette in lista, la visualizza, conta nodi e vocali, stampa nodi in posizioni pari
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char data;
	struct node *next;
}Node;

Node *creaLista(char *s) {
	int i, l;
	Node *head=NULL;
	Node *tail=NULL;
	Node *temp=NULL;
	
	l=strlen(s);
	
	for(i=0;i<l;i++) {
		if(i==0) {
			head=malloc(sizeof(Node));
			if(head!=NULL) {
				tail=head;
				head->data=s[i];
				head->next=NULL;
			}
			else {
				printf("Impossibile creare nodo");
				return NULL;
			}
		}
		else {
			temp=malloc(sizeof(Node));
			if(temp!=NULL) {
				tail->next=temp;
				tail=temp;
				tail->data=s[i];
				tail->next=NULL;
			}
			else {
				printf("Impossibile creare nodo");
				return NULL;
			}
		}
	}
	return head;
}

void visualizzaLista(Node *head) {
	while(head!=NULL) {
		printf("%c -> ", head->data);
		head=head->next;
	}
	printf("NULL");
}

int lunghezzaLista(Node *head) {
	int i=0;
	while(head!=NULL) {
		i++;
		head=head->next;
	}
	return i;
}

int isVocaleMaiuscola(char c) {
	if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
		return 1;
	else
		return 0;
}

int isVocaleMinuscola(char c) {
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		return 1;
	else
		return 0;
}

int contaVocali(Node *head) {
	int c=0;
	
	while(head!=NULL) {
		if(isVocaleMinuscola(head->data) || isVocaleMaiuscola(head->data))
			c++;
		head=head->next;
	}
	return c;
}

void stampaNodiPari(Node *head, int l) {
	int i=0;
	printf("%c -> ", head->data);
	i++;
	while(head!=NULL) {
		head=head->next;
		if(i%2==0 && i<l)
			printf(" %c ->", head->data);
		i++;
	}
	printf(" NULL");
}

int main(int argc, char **argv) {
	int l, c;
	Node *head=NULL;
	if(argc!=2)
		printf("Numero di parametri non corretto\n");
	else {
		head=creaLista(argv[1]);
		visualizzaLista(head);
		l=lunghezzaLista(head);
		printf("\nLa lista contiene %d nodi", l);
		c=contaVocali(head);
		printf("\nLa parola contiene %d vocali", c);
		printf("\n");
		stampaNodiPari(head, l);
	}
	return 1;
}