#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo {
	int data;
	struct nodo *next;
}Nodo;

void lista(Nodo **head) {
	Nodo *new=(Nodo*)malloc(sizeof(Nodo));
	Nodo *tail=*head;
	if(new!=NULL) {
		new->data=rand()%10;
		new->next=NULL;
		if(*head==NULL) {
			*head=new;
			return;
		}
		while(tail->next!=NULL)
			tail=tail->next;
		tail->next=new;
	}
}

void visualizza(Nodo *head) {
	while(head!=NULL) {
		printf("%d -> ", head->data);
		head=head->next;
	}
	printf("NULL\n");
}

int cancellaNodo(Nodo **head, Nodo *nodo) {
	Nodo *temp=*head;
	Nodo *prev=NULL;
	if(temp!=NULL && temp==nodo) {
		*head=temp->next;
		free(temp);
		return 1;
	}
	while(temp!=NULL && temp!=nodo) {
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
		return 0;
	prev->next=temp->next;
	free(temp);
	return 1;
 }

int cancellaX(Nodo **head, int x) {
	int c=0;
	Nodo *temp=*head;
	while(temp!=NULL) {
		if(temp->data%x==0) {
			Nodo *del=temp;
			temp=temp->next;
			c=c+cancellaNodo(head, del);
		}
		else
			temp=temp->next;
	}
	return c;
}

int ugualiN(Nodo *head1, Nodo *head2, int n, int i) {
	if(i<=n)
		return ugualiN(head1->next, head2->next, n, i+1);
	if(head1==NULL && head2==NULL) 
		return 0;
	if(head1==NULL && head2!=NULL)
		return 0;
	if(head1!=NULL && head2==NULL)
		return 0;
	if(head1!=NULL && head2!=NULL) {
		if(head1->data==head2->data) {
			ugualiN(head1->next, head2->next, n, i);
			return 1;
		}
		else
			return 0;
	}	
}

int main () {
	Nodo *head1=NULL;
	Nodo *head2=NULL;
	int c, ris;
	srand(time(NULL));
	for(int i=0; i<10; ++i)
		lista(&head1);
	visualizza(head1);
	for(int i=0; i<10; ++i)
		lista(&head2);
	visualizza(head2);
	ris=ugualiN(head1, head2, 5, 0);
	printf("%d\n", ris);
	c=cancellaX(&head1, 2);
	printf("%d\n", c);
	visualizza(head1);
}
