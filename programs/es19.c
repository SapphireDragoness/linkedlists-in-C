#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

void listaCrea(Node **head) {
	Node *tail=*head;
	Node *new=malloc(sizeof(Node));
	if(new!=NULL) {
		new->data=rand()%5;
		new->next=NULL;
	}
	if(*head==NULL) {
		*head=new;
		return;
	}
	while(tail->next!=NULL)
		tail=tail->next;
	tail->next=new;
	return;
}

void listaVisualizza(Node *head) {
	if(head==NULL) {
		printf("NULL\n");
		return;
	}
	printf("%d -> ", head->data);
	listaVisualizza(head->next);
}

void duplicaX(Node **head, int x, int n) {
	Node *temp=*head;
	Node *prev=NULL;
	int i=1;
	if((*head)==NULL)
		return;
	if((*head)->data==x && i%n==0) {
		Node *new=malloc(sizeof(Node));
		new->data=x;
		new->next=*head;
		*head=new;
	}
	while(temp->next!=NULL) {
		prev=temp;
		temp=temp->next;
		i++;
		if(temp->data==x && i%n==0) {
			Node *new=malloc(sizeof(Node));
			new->data=x;
			prev->next=new;
			new->next=temp;
			i++;
		}
	}
}

int main(int argc, char **argv) {
	Node *head=NULL;
	srand(time(NULL));
	for(int i=0; i<10; i++)
		listaCrea(&head);
	listaVisualizza(head);
	duplicaX(&head, 2, 2);
	listaVisualizza(head);
	return 0;
}