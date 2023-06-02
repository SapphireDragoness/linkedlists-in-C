//inserimento nodi in testa, centro e coda (numeri random)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

Node *creaLista(int n) {
	int i;
	Node *head=NULL;
	Node *temp=NULL;
	Node *tail=NULL;
	srand(time(NULL));
	for(i=0;i<n;i++) {
		if(i==0) {
			head=malloc(sizeof(Node));
			if(head!=NULL) {
				tail=head;
				head->data=rand()%100;
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
				tail->data=rand()%100;
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
		printf("%d -> ", head->data);
		head=head->next;
	}
	printf("NULL\n");
}

void inserimentoTesta(Node **head) {
	Node *newnode=NULL;
	newnode=malloc(sizeof(Node));
	if(newnode!=NULL) {
		newnode->data=rand()%100;
		newnode->next=*head;
		*head=newnode;
	}
	else
		printf("Impossibile creare nodo");
}

void inserimentoDopoNodo(Node *head, int p) {
	int i=0;
	Node *prev=NULL;
	Node *newnode=(Node*)malloc(sizeof(Node));
	if (newnode!=NULL) {
		newnode->data=rand()%100;
		while(head!=NULL && i!=p) {
			i++;
			prev=head;
			head=head->next;
		}
		prev->next=newnode;
		newnode->next=head;
	}
	else
		printf("Impossibile creare nodo");
}

void inserimentoCoda(Node **head) {
	Node *newnode=(Node*)malloc(sizeof(Node));
	Node *tail=*head;
	if(newnode!=NULL) {
		newnode->data=rand()%100;
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
		printf("Errore");
}

int main(int argc, char **argv) {
	if(argc!=2)
		printf("Numero di argomenti non corretto");
	else {
		Node *h=NULL;
		int n=atoi(argv[1]), p;
		h=creaLista(n);
		visualizzaLista(h);
		printf("\nInserimento in testa\n");
		inserimentoTesta(&h);
		printf("\n");
		visualizzaLista(h);
		printf("\nInserimento dopo nodo\n");
		printf("\nIn che punto inserisco il nuovo nodo?\n");
		scanf("%d", &p);
		inserimentoDopoNodo(h, p);
		visualizzaLista(h);
		printf("\nInserimento in coda\n");
		inserimentoCoda(&h);
		visualizzaLista(h);
	}
	return 0;
}