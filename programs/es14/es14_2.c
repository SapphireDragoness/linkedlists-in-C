#include "es14_1.h"

Node *creaListaRicorsiva(int n) {
	if(n==0)
		return NULL;
	else {
		Node *newnode=(Node*)malloc(sizeof(Node));
		if(newnode==NULL)
			return NULL;
		int num=rand()%100;
		newnode->data=num;
		newnode->next=creaListaRicorsiva(n-1);
		return newnode;
	}
}

void visualizzaListaRicorsiva(Node *head) {
	if(head==NULL) {
		printf("NULL\n");
		return;
	}
	else {
		printf("%d -> ", head->data);
		return visualizzaListaRicorsiva(head->next);
	}
}

int sommaLista(Node *head) {
	if(head==NULL)
		return 0;
	else
		return head->data+sommaLista(head->next);
}

int lunghezzaLista(Node *head) {
	if(head==NULL) 
		return 0;
	else 
		return 1+lunghezzaLista(head->next);
}

void contrarioLista(Node *head) {
	if(head==NULL) {
		return;
	}
	contrarioLista(head->next);
	printf("%d -> ", head->data);
}