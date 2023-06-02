#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int data; 
	struct node *next;
}Node;

void inserisciCoda(Node **head, int x) {
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

void visualizzaLista(Node *head) {
	while(head!=NULL) {
		printf("%d -> ", head->data);
		head=head->next;
	}
	printf("NULL\n");
}

void sommaListe(Node *head1, Node *head2, Node **head3) {
	int temp;
	while(head1!=NULL && head2!=NULL) {
		temp=(head1->data)+(head2->data);
		inserisciCoda(head3, temp);
		head1=head1->next;
		head2=head2->next;
	}
}

int main(int argc, char **argv) {
	if(argc!=2)
		printf("Numero di argomenti errato");
	else {
		srand(time(NULL));
		int n=atoi(argv[1]);
		Node *head1=NULL, *head2=NULL;
		Node *head3=NULL;
		for(int i=0;i<n;i++) {
			int x1=rand()%100;
			int x2=rand()%100;
			inserisciCoda(&head1, x1);
			inserisciCoda(&head2, x2);
		}
		visualizzaLista(head1);
		visualizzaLista(head2);
		sommaListe(head1, head2, &head3);
		visualizzaLista(head3);
	}
	return 0;
}