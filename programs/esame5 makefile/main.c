#include "esame5.h"

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