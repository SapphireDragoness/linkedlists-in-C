#include "sperimentazioni1_header.h"

int main(int argc, char **argv) {
	if(argc != 2) {
		printf("Numero argomenti errato");
		return -1;
	}
	Node *head = NULL;
	int numNodi;
	FILE *fp1, *fp2;
	fp1 = fopen(argv[1], "r");
	if(fp1 == NULL) {
		printf("Errore creazione file\n");
		return -1;
	}
	numNodi = lista_leggi_file(fp1, &head);
	if(numNodi <= 0) {
		printf("Problema durante la creazione della lista");
		return -1;
	}
	fclose(fp1);
	printf("Numero nodi presenti: %d\n", numNodi);
	lista_visualizza(head);
	Node *temp = head;
	fp2 = fopen("risultati.txt", "a");
	if(fp2 == NULL) {
		printf("Errore creazione file\n");
		return -1;
	}
	for(int i = 0; i < numNodi; i++) {
		int f = fattoriale(temp -> data);
		printf("Fattoriale di %d: %d\n", temp ->data, f);
		salva_risultati(fp2, f);
		temp = temp -> next;
	}
	fclose(fp2);
	printf("Risultati scritti su file 'risultati.txt'\n");
	return 0;
}