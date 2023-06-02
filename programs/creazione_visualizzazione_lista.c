#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

Node * lista_crea(int n){
	int i;
	struct node *head = NULL;
	struct node *tail = NULL;
	struct node *temp = NULL;
	
	srand(time(NULL));
	
	for(i=0;i<n;i++) {
		if(i == 0) {
			head=malloc(sizeof(Node));
			if(head!=NULL) {
				printf("\nNode testa creato all'indirizzo: %p", head);
				tail=head;
				head->data=rand()%50;
				head->next=NULL;
			}
			else {
				printf("\nImpossibile creare il node testa");
				return NULL;
			}
		}
		else {
			temp=malloc(sizeof(Node));
			if(temp!=NULL) {
				printf("\nNode creato all'indirizzo: %p", temp);
				tail->next=temp;
				tail=temp;
				tail->data=rand()%40;
				tail->next=NULL;
			}
			else {
				printf("\nImpossibile creare node temp");
				return NULL;
			}
		}
	}
	return head;
}

void visualizza(Node *head) {
	printf("\n");
	while(head!=NULL) {
		printf("%d -> ", head -> data);
		head = head -> next;
	}
	printf("NULL");
}

int lista_media(Node* head, int n) {
	int s=0;
	while(head!=NULL) {
		s=s+head->data;
		head=head->next;
	}
	m=s/n;
	return m;
}

int main(int argc, char *argv[]){
	int n, m;
	Node *headlist;
	if(argc!=2)
		printf("Numero parametri non corretto");
	else {
		n=atoi(argv[1]);
		Node *headlist=NULL;
		headlist=lista_crea(n);
		if(headlist!=NULL)
			printf("\nLista creata con testa: %p", headlist);
		else {
			printf("\nLista vuota");
			return 1;
		}
		visualizza(headlist);
		m=lista_media(headlist, n);
		printf("\nLa media dei nodi e': %d", m);
	}
	return 0;
}