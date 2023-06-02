#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

void creaLista(Node **head) {
	Node *newnode=(Node*)malloc(sizeof(Node));
	Node *tail=*head;
	if(newnode!=NULL) {
		newnode->data=rand()%10;
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
		printf("Impossibile creare nodo");
}

void stampaLista(Node *head) {
	while(head!=NULL) {
		printf("%d -> ", head->data);
		head=head->next;
	}
	printf("NULL");
}

float mediaK(Node *head, int k) {
	int i=0;
	float m=0, s=0;
	while(head!=NULL && i<k) {
		s=s+(head->data);
		head=head->next;
		i++;
	}
	m=s/k;
	return m;
}

void cancellaNodiVPari(Node **head, int v) {
	Node *temp=*head;
	Node *prev=NULL;
	while(temp!=NULL) {
		if(head->data==v && i%2==0)
			free(
	}
}

int main() {
	srand(time(NULL));
	int k;
	float m;
	Node *head=NULL;
	printf("Inserisci numero positivo (minore di 10):\n");
	scanf("%d", &k);
	for(int i=0; i<10; i++)
		creaLista(&head);
	stampaLista(head);
	m=mediaK(head, k);
	printf("\nMedia: %f", m);
	printf("Inserisci numero positivo (minore di 10):\n");
	scanf("%d", &v);
}