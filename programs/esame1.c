#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 15

typedef struct node {
	int giorno_numero;
	char giorno_nome[DIM];
	int temperatura;
	struct node *next;
}Node;

void lista_inserisci_coda(Node **head, int giorno_numero, char *giorno_nome, int temperatura) {
	Node *newnode=(Node*)malloc(sizeof(Node));
	Node *tail=*head;
	if(newnode!=NULL) {
		newnode->giorno_numero=giorno_numero;
		strcpy(newnode->giorno_nome, giorno_nome);
		newnode->temperatura=temperatura;
		newnode->next=NULL;
		if(*head==NULL) {
			*head=newnode;
			return;
		}
		while(tail->next!=NULL) 
			tail=tail->next;
		tail->next=newnode;
	}
	else("Errore creazione nodo");
}

int lista_leggi_da_file(Node **head, FILE *fp) {
	int n=0;
	while(!feof(fp)) {
		int giorno_numero;
		char giorno_nome[DIM];
		int temperatura;
		fscanf(fp, "%d %s %d", &giorno_numero, giorno_nome, &temperatura);
		lista_inserisci_coda(head, giorno_numero, giorno_nome, temperatura);
		n++;
	}
	return n;
}

void lista_visualizza(Node *head) {
	if(head==NULL) {
		printf("NULL\n");
		return;
	}
	else {
		printf("%d\t| %s\t| %d\n", head->giorno_numero, head->giorno_nome, head->temperatura);
		return lista_visualizza(head->next);
	}
}

void lista_media_temperature(Node *head, float *media, float *somma, int n) {
	if(head==NULL) {
		*media=*somma/n;
		return;
	}
	else {
		*somma=*somma+head->temperatura;
		return lista_media_temperature(head->next, media, somma, n);
	}
}

int lista_nodi_sopra_media(Node *head, float media) {
	if(head==NULL)
		return 0;
	else {
		if(head->temperatura>media)
			return 1+lista_nodi_sopra_media(head->next, media);
		else
			return 0+lista_nodi_sopra_media(head->next, media);
	}
}

int lista_cerca_giorno(Node *head, char giorno[]) {
	if(head==NULL) {
		return 0;
	}
	else {
		if(strcmp(head->giorno_nome,giorno))
			return 0+lista_cerca_giorno(head->next, giorno);
		else {
			printf("%d\t| %s\t| %d|\n",head->giorno_numero, head->giorno_nome, head->temperatura);
			return 1+lista_cerca_giorno(head->next, giorno);
		}
	}
}

void lista_cancella_giorno(Node **head, int giorno) {
	Node *temp=*head;
	Node *prev=NULL;
	if(temp!=NULL && temp->giorno_numero==giorno) {
		*head=temp->next;
		free(temp);
		return;
	}
	while(temp!=NULL && temp->giorno_numero!=giorno) {
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
		return;
	prev->next=temp->next;
	free(temp);
}

int main(int argc, char **argv) {
	if(argc!=2) {
		printf("Numero di argomenti incorretto");
		return 1;
	}
	else {
		char *f1=argv[1];
		FILE *fp1=fopen(f1, "r");
		if(fp1!=NULL) {
			Node *head=NULL;
			int n;
			n=lista_leggi_da_file(&head, fp1);
			printf("Nodi creati: %d\n", n);
			lista_visualizza(head);
			float media=0, somma=0;
			lista_media_temperature(head, &media, &somma, n);
			printf("La media delle temperature e' %f\n", media);
			int sm=0;
			sm=lista_nodi_sopra_media(head, media);
			printf("Il numero dei nodi sopra la media e' %d\n", sm);
			char giorno[DIM];
			int ng=0;
			printf("Inserisci giorno da cercare: \n");
			scanf("%s", giorno);
			ng=lista_cerca_giorno(head, giorno);
			printf("Ricerca conclusa, trovati %d nodi\n", ng);
			int ngiorno=0;
			do {
				printf("Inserisci numero del giorno da cancellare (da 1 a %d): \n", n);
				scanf("%d", &ngiorno);
			} while(ngiorno<1 || ngiorno>n);
			lista_cancella_giorno(&head, ngiorno);
			printf("Nodo cancellato:\n");
			lista_visualizza(head);
		}
	}
	return 0;
}