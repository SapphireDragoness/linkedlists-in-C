//crea una lista con inserimento in coda e poi la divide in due liste, una con nodi pari e una con nodi dispari
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

typedef Node * Head;

void inserisciCoda(Head *head, int x) {
	Node *newnode=(Node*)malloc(sizeof(Node));
	Node *tail=*head;
	if(newnode!=NULL) {
		newnode->data=x;
		newnode->next=NULL;
		if(*head==NULL) {
			*head=newnode;
			return;
		}
		while(tail->next!=NULL)
			tail=tail->next;
		tail->next=newnode;
	}
	else
		printf("Impossibile creare lista");
}

void visualizzaLista(Head head) {
	while(head!=NULL) {
		printf("%d -> ", head->data);
		head=head->next;
	}
	printf("NULL\n");
}

int main(int argc, char **argv) {
	srand(time(NULL));
	int y;
	if(argc!=2)
		printf("Valore di argomenti non corretto");
	else {
		int n=atoi(argv[1]);
		Head h=NULL;
		Head hP=NULL, *hD=NULL;
		for(int i=0; i<n; i++) {
			int x=rand()%50;
			inserisciCoda(&h, x);
		}
		visualizzaLista(h);
	}
	return 0;
}
