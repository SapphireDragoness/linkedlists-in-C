#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char data;
	struct node *next;
}Node;

void creaLista(Node **head, char c) {
	Node *newnode=(Node*)malloc(sizeof(Node));
	Node *tail=*head;
	if(newnode!=NULL) {
		newnode->data=c;
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
		printf("%c -> ", head->data);
		head=head->next;
	}
	printf("NULL\n");
}

void cancellaNodo(Node **head, char c) {
	Node *temp=*head;
	Node *prev=NULL;
	if(temp!=NULL && temp->data==c) {
		*head=temp->next;
		free(temp);
		return;
	}
	while(temp!=NULL && temp->data!=c) {
		prev=temp;
		temp=temp->next;
		if(temp==NULL) {
		printf("Nodo non trovato\n");
		return;
		}
	}
	prev->next=temp->next;
	free(temp);
}

int main(int argc, char **argv) {
	if(argc!=3) {
		printf("Numero di argomenti non corretto (parola, nome file)");
		return 1;
	}
	else {
		Node *head=NULL;
		char *s=argv[1], c, *f1=argv[2];
		int l=strlen(s);
		for(int i=0; i<l; i++)
			creaLista(&head, s[i]);
		visualizzaLista(head);
		printf("Inserisci carattere da eliminare: ");
		scanf("%c", &c);
		cancellaNodo(&head, c);
		visualizzaLista(head);
		FILE *fp1=fopen(f1, "w");
		while(head!=NULL) {
			fprintf(fp1, "%c\n", head->data);
			head=head->next;
		}
		fclose(fp1);
	}
	return 0;
}