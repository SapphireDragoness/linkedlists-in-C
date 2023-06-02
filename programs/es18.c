#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo {
	int data;
	struct nodo *next;
}Nodo;

void lista(Nodo **head) {
	Nodo *tail=*head;
	Nodo *new=malloc(sizeof(Nodo));
	if(new!=NULL) {
		new->data=rand()%3;
		new->next=NULL;
	}
	else
		return;
	if(*head==NULL) {
		*head=new;
		return;
	}
	while(tail->next!=NULL)
		tail=tail->next;
	tail->next=new;
	return;
}

void visualizza(Nodo *head) {
	if(head==NULL) {
		printf("NULL\n");
		return;
	}
	printf("%d -> ", head->data);
	visualizza(head->next);
}

int sommaPesata(Nodo *head, int x) {
	int s=0;
	int i=1;
	if(head==NULL)
		return 0;
	while(head!=NULL) {
		if(i%x==0) {
			s=s+(head->data*i);
		}
		head=head->next;
		i++;
	}
	return s;
}

int differenza(Nodo *head, int n, int m) {
	int i=1;
	int s1=0, s2=0;
	if(head==NULL)
		return 0;
	if(m<n)
		return 0;
	while(head!=NULL) {
		if(i<=n)
			s1=s1+(head->data);
		else if(i>n && i<=m)
			s2=s2+(head->data);
		head=head->next;
		i++;
	}
	return (s1-s2);
}

int treOccorrenze(Nodo *head, int x) {
	int i=0;
	int c=0;
	Nodo *prev=NULL;
	if(head==NULL)
		return 0;
	else {
		while(head->next!=NULL) {
			prev=head;
			head=head->next;
			if(prev->data==head->data) {
				++i;
				if(i==3) {
					++c;
					i=0;
				}
			}
			else
				i=0;
		}
	}
	return c;
}

int main() {
	Nodo *head=NULL;
	srand(time(NULL));
	int s, d, o;
	for(int i=0; i<20; i++)
		lista(&head);
	visualizza(head);
	s=sommaPesata(head, 2);
	printf("%d\n", s);
	d=differenza(head, 3, 5);
	printf("%d\n", d);
	o=treOccorrenze(head, 2);
	printf("%d\n", o);
}