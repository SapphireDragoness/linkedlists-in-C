#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 64

typedef struct nodo {
	char data[DIM];
	struct nodo *next;
}Nodo;

int lista_leggi_file(FILE *fp, Nodo **testa);
void lista_coda_iter(Nodo **testa, char *nome);
void lista_visualizza(Nodo *testa);
int lista_vocali(Nodo *testa, char c1, char c2);
void salva_risultati(FILE *fp, int cA, int cE, int cI, int cO, int cU);

int main(int argc, char **argv) {
	if(argc!=3) {
		printf("Numero di argomenti errato (eseguibile + file da leggere + file da scrivere)");
		return EXIT_FAILURE;
	}
	else {
		int num_nodi=0, cA, cE, cI, cO, cU;
		char c1, c2;
		Nodo *testa=NULL;
		FILE *fp1;
		fp1=fopen(argv[1], "r");
		num_nodi=lista_leggi_file(fp1, &testa);
		fclose(fp1);
		printf("\nNumero nodi creati: %d\n", num_nodi);
		lista_visualizza(testa);
		cA=lista_vocali(testa, 'A', 'a');
		cE=lista_vocali(testa, 'E', 'e');
		cI=lista_vocali(testa, 'I', 'i');
		cO=lista_vocali(testa, 'O', 'o');
		cU=lista_vocali(testa, 'U', 'u');
		printf("A: %d\nE: %d\nI: %d\nO: %d\nU: %d\n", cA, cE, cI, cO, cU);
		FILE *fp2;
		fp2=fopen(argv[2], "w");
		salva_risultati(fp2, cA, cE, cI, cO, cU);
		fclose(fp2);
	}
}

int lista_leggi_file(FILE *fp, Nodo **testa) {
	int i=0;
	char nome[DIM];
	while(!feof(fp)) {
		fscanf(fp, "%s", nome);
		lista_coda_iter(testa, nome);
		i++;
	}
	return i;
}

void lista_coda_iter(Nodo **testa, char *nome) {
	Nodo *nuovo=(Nodo*)malloc(sizeof(Nodo));
	Nodo *coda=*testa;
	if(nuovo!=NULL) {
		strcpy(nuovo->data, nome);
		nuovo->next=NULL;
		if(*testa==NULL) {
			*testa=nuovo;
			return;
		}
		while(coda->next!=NULL)
			coda=coda->next;
		coda->next=nuovo;
	}
	else {
		printf("Errore creazione nodo");
	return; 
	}
}

void lista_visualizza(Nodo *testa) {
	if(testa!=NULL) {
		printf("%s -> ", testa->data);
		return lista_visualizza(testa->next);
	}
	else {
		printf("NULL\n");
		return;
	}
}

int lista_vocali(Nodo *testa, char c1, char c2) {
	int c=0;
	if(testa==NULL) 
		return 0;
	else {
		for(int i=0; i<DIM; i++) {
			if((testa->data)[i]==c1 || (testa->data)[i]==c2)
				c++;
		}
		return c+lista_vocali(testa->next, c1, c2);
	}
}

void salva_risultati(FILE *fp, int cA, int cE, int cI, int cO, int cU) {
	fprintf(fp, "A: %d\nE: %d\nI: %d\nO: %d\nU: %d\n", cA, cE, cI, cO, cU);
}
