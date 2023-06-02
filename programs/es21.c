#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

void creaLista(Node **head) {
	Node *tail = *head;
	Node *newnode = malloc(sizeof(Node));
	newnode -> data = rand()%5;
	newnode -> next = NULL;
	if(*head == NULL) {
		*head = newnode;
		return;
	}
	while(tail -> next != NULL)
		tail = tail -> next;
	tail -> next = newnode;
}

void visualizzaLista(Node *head) {
	if(head == NULL) {
		printf("NULL\n");
		return;
	}
	printf("%d -> ", head -> data);
	visualizzaLista(head -> next);
}

void cancellaPari(Node *head, int p, int k) {
	Node *temp = NULL;
	if(head -> next != NULL) {
		if(p%2 == 0 && head -> next -> data == k) {
			temp = head -> next;
			head -> next = head -> next -> next;
			free(temp);
			cancellaPari(head, p++, k);
		}
		else
			cancellaPari(head -> next, p++, k);
	}
}

void duplicaDispari(Node *head, int p, int k) {
	if(head != NULL) {
		if(p%2 != 0 && head -> data == k) {
			Node *new = malloc(sizeof(Node));
			new -> data = k;
			new -> next = head -> next;
			head -> next = new;
			duplicaDispari(head -> next -> next, p+1, k);
		}
		else
			duplicaDispari(head -> next, p+1, k);
	}
}

Node* listaDerivata(Node *head1, Node *head2, int p) {
	Node *head3;
	if(head1 != NULL && head2 != NULL) {
		if((head1 -> data + head2 -> data)%p == 0) {
			head3 = malloc(sizeof(Node));
			head3 -> data = head1 -> data * head2 -> data;
			head3 -> next = listaDerivata(head1 -> next, head2 -> next, p+1);
			return head3;
		}
		else
			return listaDerivata(head1 -> next, head2 -> next, p+1);
	}
	else 
		return NULL;
}


int main() {
	Node *head1 = NULL;
	Node *head2 = NULL;
	Node *head3 = NULL;
	srand(time(NULL));
	for(int i = 0; i < 10; i++) {
		creaLista(&head1);
		creaLista(&head2);
	}
	visualizzaLista(head1);
	visualizzaLista(head2);
	
	head3 = listaDerivata(head1, head2, 1),
	visualizzaLista(head3);
	
	cancellaPari(head1, 0, 2);
	visualizzaLista(head1);
	
	duplicaDispari(head2, 0, 2);
	visualizzaLista(head2);
}