#include "es14_1.h"

int main(int argc, char **argv) {
	int n=atoi(argv[1]);
	if(argc!=2) {
		printf("Numero di argomenti incorretto (inserisci numero nodi)");
		return 1;
	}
	else if(n==0) {
		printf("Il numero dei nodi deve essere un numero");
		return 1;
	}
	else {
		srand(time(NULL));
		int len1=0, len2=0;
		printf("Creo ricorsivamente due liste composte da numeri casuali...\n");
		Node *head1=NULL, *head2=NULL;
		head1=creaListaRicorsiva(n);
		head2=creaListaRicorsiva(n);
		len1=lunghezzaLista(head1);
		printf("Lista 1 (lunghezza %d):\n", len1);
		visualizzaListaRicorsiva(head1);
		len2=lunghezzaLista(head2);
		printf("Lista 2 (lunghezza %d):\n", len2);
		visualizzaListaRicorsiva(head2);
		int somma1=sommaLista(head1);
		printf("Somma nodi lista 1: %d\n", somma1);
		int somma2=sommaLista(head2);
		printf("Somma nodi lista 2: %d\n", somma2);
		printf("\nLista 1 inversa:\n");
		contrarioLista(head1);
		printf("NULL\n");
		printf("\nLista 2 inversa:\n");
		contrarioLista(head2);
		printf("NULL\n");
	}
}