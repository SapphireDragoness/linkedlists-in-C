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
		return;
}

void visualizzaLista(Node *head) {
	while(head!=NULL) {
		printf("%d -> ", head->data);
		head=head->next;
	}
	printf("NULL\n");
}

float mediaLista(Node *head, int k) {
	float somma=0, media=0;
	int n=0;
	while(head!=NULL && n<k) {
		somma=somma+(head->data);
		n++;
		head=head->next;
	}
	media=somma/k;
	return media;
}

void cancellaNodiPari(Node **head, int j, int pos) {
	Node *prev=NULL;
	Node *temp=*head;
	if(temp!=NULL && temp->data==j) {
		*head=temp->next;
		free(temp);
		return;
	}
	pos++;
	while(temp->next!=NULL && temp->data!=j) {
		prev=temp;
		temp=temp->next;
		++pos;
	}
	if(temp==NULL)
		return;
	if(pos%2==0) {
		prev->next=temp->next;
		free(temp);
	}
}

int main() {
	srand(time(NULL));
	Node *head=NULL;
	int k, j, pos=0;
	float media;
	for(int i=0; i<10; i++) 
		creaLista(&head);
	visualizzaLista(head);
	printf("Numero nodi su cui fare la media (max 10):\n");
	scanf("%d", &k);
	media=mediaLista(head, k);
	printf("Media: %0.2f", media);
	printf("\nValore nodo da cancellare se pari:\n");
	scanf("%d", &j);
	cancellaNodiPari(&head, j, pos);
	visualizzaLista(head);
	return 0;
}