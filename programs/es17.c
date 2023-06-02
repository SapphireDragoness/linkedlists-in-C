#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo {
	int data;
	struct nodo *next;
}Nodo;

Nodo* crea(int n){
	Nodo *head;
	if(n==0)
		return NULL;
	else {
		Nodo *head=(Nodo*)malloc(sizeof(Nodo));
		int num=rand()%10;
		head->data=num;
		head->next=crea(n-1);
		return head;
	}
}

void visualizza (Nodo *head){
	if(head==NULL) {
		printf("NULL\n");
		return;
	}
	else {
		printf("%d -> ", head->data);
		visualizza(head->next);
	}
}

Nodo* somma (Nodo *head1, Nodo* head2) {
	Nodo *head3=malloc(sizeof(Nodo));
	Nodo *tail=NULL;
	if(head2!=NULL && head1!=NULL && head3!=NULL) {
		tail=head3;
		head3->data=(head1->data)+(head2->data);
		head3->next=NULL;
		head1=head1->next;
		head2=head2->next;
	}
	else 
		return NULL;
	while((head1!=NULL) || (head2!=NULL)) {
		Nodo *temp=malloc(sizeof(Nodo));
		tail->next=temp;
		tail=temp;
		if(head1==0) {
			tail->data=(head2->data);
			tail->next=NULL;
			head2=head2->next;
		}
		else if(head2==0) {
			tail->data=(head1->data);
			tail->next=NULL;
			head1=head1->next;
		}
		else if(head1!=0 && head2!=0) {
			tail->data=(head1->data)+(head2->data);
			tail->next=NULL;
			head1=head1->next;
			head2=head2->next;
		}
	}
	return head3;
}

float media(Nodo *head, int n, float *s) {
	if(head==NULL) {
		float m=(*s)/n;
		return m;
	}
	*s=*s+head->data;
	return media(head->next, n+1, s);
}
	

int main() {
	srand(time(NULL));
	int n=10;
	float s=0;
	float m;
	Nodo *head1;
	Nodo *head2;
	Nodo *head3;
	head1=crea(n);
	visualizza(head1);
	head2=crea(5);
	visualizza(head2);
	head3=somma(head1, head2);
	visualizza(head3);
	m=media(head1, 0, &s);
	printf("%0.1f", m);
}