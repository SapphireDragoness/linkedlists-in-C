#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

Node *creaLista(int n) {
	if(n==0)
		return NULL;
	else {
		Node *head=(Node*)malloc(sizeof(Node));
		head->data=rand()%10;
		head->next=creaLista(n-1);
		return head;
	}
}

void visualizza(Node *head) {
	if(head==NULL) {
		printf("NULL\n");
		return;
	}
	else {
		printf("%d -> ", head->data);
		visualizza(head->next);
	}
}

void inserisciDopoX(Node **head, int x) {
	int n=0;
	Node *temp=*head;
	Node *prev=NULL;
	if(x<0)
		return;
	if(x==0) {
		Node *new=malloc(sizeof(Node));
		new->data=rand()%10;
		*head=new;
		new->next=temp;
		return;
	}
	while(temp!=NULL) {
		prev=temp;
		temp=temp->next;
		n++;
		if(x==n) {
			Node *new=malloc(sizeof(Node));
			new->data=rand()%10;
			prev->next=new;
			new->next=temp;
			n++;
		}
	}
}

void inserisciPrimaX(Node **head, int x) {
	int n=1;
	Node *temp=*head;
	Node *prev=NULL;
	if(x<=0)
		return;
	if(x==1) {
		Node *new=malloc(sizeof(Node));
		new->data=rand()%10;
		*head=new;
		new->next=temp;
		return;
	}
	while(temp!=NULL) {
		if(x==n) {
			Node *new=malloc(sizeof(Node));
			new->data=rand()%10;
			prev->next=new;
			new->next=temp;
			n++;
		}
		prev=temp;
		temp=temp->next;
		n++;
	}
}

int main() {
	Node *head=NULL;
	srand(time(NULL));
	head=creaLista(10);
	visualizza(head);
	inserisciDopoX(&head, 3);
	visualizza(head);
	inserisciPrimaX(&head, 5);
	visualizza(head);
}

