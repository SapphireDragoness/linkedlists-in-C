#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char data;
	struct node *next;
}Node;

void inserisciCoda(Node **head, char c) {
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

int isVocaleMaiuscola(char c) {
	if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
		return 1;
	else
		return 0;
}

int isVocaleMinuscola(char c) {
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		return 1;
	else
		return 0;
}

int main(int argc, char **argv) {
	if(argc!=3)
		printf("Numero di argomenti non corretto");
	else {
		int i, l;
		char *chr=argv[2];
		char *s=argv[1];
		Node *head1=NULL, *head2=NULL;
		l=strlen(argv[1]);
		for(i=0;i<l;i++)
			inserisciCoda(&head1, s[i]);
		visualizzaLista(head1);	
		for(i=0;i<l;i++) {
			if(isVocaleMinuscola(s[i]) || isVocaleMaiuscola(s[i]) && s[i]!='a')
				inserisciCoda(&head2, s[i]);
		}
		visualizzaLista(head2);
	}
	return 0;
}
