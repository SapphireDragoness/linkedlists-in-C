//legge dati da file, crea una lista, cancella nodi in posizione dispari e scrive i rimanenti dai su un altro file
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

void creaLista(Node **head, int x) {
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

void cancellaNodo(Node **head, Node *nodo) {
	Node *temp=*head;
	Node *prev=NULL;
	if(temp!=NULL && temp==nodo) {
		*head=temp->next;
		free(temp);
		return;
	}
	while(temp!=NULL && temp!=nodo) {
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL) 
		return;
	prev->next=temp->next;
	free(temp);
}

void cancellaNodiDispari(Node **head) {
	int i=0;
	Node *temp=*head;
	if(*head==NULL)
		return;
	while(temp!=NULL) {
		if(i%2==1) {
			Node *del=temp;
			temp=temp->next;
			cancellaNodo(head, del);
		}
		else {
			temp=temp->next;
		}
		i++;
	}
}

int main(int argc, char **argv) {
	if(argc!=3) {
		printf("Numero di argomenti errato");
		return 1;
	}
	else {
		printf("Leggo file...");
		char *f1=argv[1], *f2=argv[2];
		FILE *fp1=fopen(f1, "r"), *fp2=fopen(f2, "w");
		Node *head=NULL;
		
		if(fp1!=NULL && fp2!=NULL) {
			while(!feof(fp1)) {
				int x;
				int y=fscanf(fp1, "%d", &x);
				if(y>0)
					creaLista(&head, x);
			}
		}
		visualizzaLista(head);
		printf("Cancello nodi in posizione dispari: \n");
		cancellaNodiDispari(&head);
		visualizzaLista(head);	
		printf("Scrivo dati su file...");		
		while(head!=NULL) {
			fprintf(fp2, "%d\n", head->data);
			head=head->next;
		}
		fclose(fp1);
		fclose(fp2);
	}
	return 0;
}