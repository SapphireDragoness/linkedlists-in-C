#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int data;
	struct nodo *next;
}Nodo;

int lista_leggi_file(Nodo **testa, FILE *fp);
void lista_crea(Nodo **testa, int num);
unsigned long long int fattoriale(int n);
void lista_visualizza(Nodo *testa);
void salva_risultati(char *file, unsigned long long int n);

int main(int argc, char **argv) {
	if(argc!=3) {
		printf("Numero argomenti errato");
		return 1; 
	}
	else {
		int c;
		unsigned long long f;
		Nodo *testa=NULL;
		FILE *fp1;
		fp1=fopen(argv[1], "r");
		c=lista_leggi_file(&testa, fp1);
		fclose(fp1);
		printf("Numero nodi: %d\n", c);
		lista_visualizza(testa);
		while(testa!=NULL) {
			f=fattoriale(testa->data);
			printf("Fattoriale di %d: %llu\n", testa->data, f);
			salva_risultati(argv[2], f);
			testa=testa->next;
		}
		return 0;
	}
}

int lista_leggi_file(Nodo **testa, FILE *fp) {
	int num, c=0;
	while(!feof(fp)) {
		fscanf(fp, "%d", &num);
		lista_crea(testa, num);
		c++;
	}
	return c;
}	

void lista_crea(Nodo **testa, int num) {
	Nodo *nuovo=(Nodo*)malloc(sizeof(Nodo));
	Nodo *coda=*testa;
	if(nuovo!=NULL) {
		nuovo->data=num;
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
		printf("Errore creazione nodo in memoria");
		return;
	}
}

void lista_visualizza(Nodo *testa) {
	if(testa!=NULL) {
		printf("%d -> ", testa->data);
		return lista_visualizza(testa->next);
	}
	else {
		printf("NULL\n");
		return;
	}
}

unsigned long long int fattoriale(int n) {
	if(n<=1)
		return 1;
	else 
		return (n*fattoriale(n-1));
}

void salva_risultati(char *file, unsigned long long int n) {
	FILE *fp;
	fp=fopen(file, "a");
	fprintf(fp, "%llu\n", n);
	fclose(fp);
}