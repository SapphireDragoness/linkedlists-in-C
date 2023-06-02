#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 42

typedef struct node {
	char data[DIM];
	struct node *next;
}Node;

void lista_crea(Node **head, char *nome) {
	Node *newnode=(Node*)malloc(sizeof(Node));
	Node *tail=*head;
	if(newnode!=NULL) {
		strcpy(newnode->data, nome);
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

void lista_leggi_file(Node **head, FILE *fp) {
	char nome[DIM];
	while(!feof(fp)) {
		fscanf(fp, "%s", nome);
		lista_crea(head, nome);
	}
}

void lista_visualizza(Node *head) {
	if(head==NULL) {
		printf("NULL\n");
		return;
	}
	else {
		printf("| %s \t|\n", head->data);
		return lista_visualizza(head->next);
	}
}

int lista_lunghezza(Node *head) {
	if(head==NULL)
		return 0;
	else 
		return 1+lista_lunghezza(head->next);
}

void lista_cancella(Node **head, char c) {
	Node *temp=*head;
	Node *prev=NULL;
	if(temp!=NULL && temp->data[0]==c) {
		*head=temp->next;
		free(temp);
		return;
	}
	while(temp!=NULL && temp->data[0]!=c) {
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
		return;
	prev->next=temp->next;
	free(temp);
}

void lista_scrivi(Node *head, FILE *fp) {
	while(head!=NULL) {
		fprintf(fp, "%s\n", head->data);
		head=head->next;
	}
}

int main(int argc, char **argv) {
	if(argc!=3) {
		printf("Numero di argomenti incorretto");
		return 1;
	}
	else {
		Node *head=NULL;
		char *f1=argv[1];
		FILE *fp1=fopen(f1, "r");
		if(fp1!=NULL) {
			lista_leggi_file(&head, fp1);
			lista_visualizza(head);
			int len=0;
			len=lista_lunghezza(head);
			printf("\nLa lista ha %d nodi", len);
			char *s=argv[2];
			char c=s[0];
			int i;
			printf("\n\nCancello nodi...\n");
			for(i=0; i<len; i++)
				lista_cancella(&head, c);
			lista_visualizza(head);
			fclose(fp1);
			char *f2=argv[1];
			FILE *fp2=fopen(f2, "w");
			lista_scrivi(head, fp2);
			printf("Scrittura su file completata");
			fclose(fp2);
		}
	}
}