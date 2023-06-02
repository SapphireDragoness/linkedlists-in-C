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

int cancellaNodoValore(Node **head, char key) {
	 Node *temp=*head;
	 Node *prev=NULL;
	 if(temp!=NULL && temp->data==key) {
		 *head=temp->next;
		 free(temp);
		 return 1;
	 }
	 while(temp!=NULL && temp->data!=key) {
		 prev=temp;
		 temp=temp->next;
	 }
	 if(temp==NULL)
		 return 0;
	 prev->next=temp->next;
	 free(temp);
	 return 1;
}

int cancellaNodoPosizione(Node **head, int pos) {
	if(*head==NULL)
		return 0;
	Node *temp=*head;
	if(pos==0) {
		*head=temp->next;
		free(temp);
		return 1;
	}
	for(int i=0; temp!=NULL && i<pos-1; i++)
		temp=temp->next;
	if(temp==NULL || temp->next==NULL)
		return 0;
	Node *next=temp->next->next;
	free(temp->next);
	temp->next=next;
	return 1;
}

int cancellaNodoIndirizzo(Node **head, Node *nodo) {
	Node *temp=*head;
	Node *prev=NULL;
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

int cancellaNodiPari(Node **head) {
	int c=0, i=0;
	if(*head==NULL)
		return 0;
	Node *temp=*head;
	while(temp!=NULL) {
		if(i%2==0) {
			c=c+cancellaNodoIndirizzo(head, temp);
			i++;
		}
		temp=temp->next;
	}
	return c;
}

void cancellaLista(Node **head) {
	Node *current=*head;
	Node *next;
	while(current!=NULL) {
		next=current->next;
		free(current);
		current=next;
	}
	*head=NULL;
}

int main(int argc, char **argv) {
	if(argc!=2) {
		printf("Numero di argomenti errato");
		return 1;
	}
	else {
		Node *head=NULL, *nodo=NULL;
		int i, l, e1=0, e2=0, pos, c;
		char *s=argv[1], key;
		l=strlen(s);
		for(i=0;i<l;i++)
			creaLista(&head, s[i]);
		visualizzaLista(head);
		
		printf("Seleziona nodo da cancellare per VALORE:\n");
		scanf("%c", &key);
		e1=cancellaNodoValore(&head, key);
		if(e1==0)
			printf("Nodo non cancellato\n");
		else {
			printf("Nodo cancellato\n");
			visualizzaLista(head);
		}
		
		printf("Seleziona nodo da cancellare per POSIZIONE:\n");
		scanf("%d", &pos);
		e2=cancellaNodoPosizione(&head, pos);
		if(e2==0)
			printf("Nodo non cancellato\n");
		else {
			printf("Nodo cancellato\n");
			visualizzaLista(head);
		}
		
		printf("Cancello nodi in posizione pari");
		c=cancellaNodiPari(&head);
		printf("Cancellati %d nodi", c);
		visualizzaLista(head);
		
		printf("Cancello lista:\n");
		cancellaLista(&head);
		visualizzaLista(head);
	}
	return 0;
}