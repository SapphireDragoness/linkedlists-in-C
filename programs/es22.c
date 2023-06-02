#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int DATA;

struct linkedlist {
	DATA d;
	struct linkedlist *next;
};

typedef struct linkedlist ELEMENT;

typedef ELEMENT *LINK;

LINK creaLista(int n) {
	if(n == 0) 
		return NULL;
	LINK lista = malloc(sizeof(ELEMENT));
	lista -> d = rand()%5;
	lista -> next = creaLista(n-1);
	return lista;
}

void visualizzaLista(LINK lista) {
	if(lista == NULL) {
		printf("NULL\n");
		return;
	}
	printf("%d -> ", lista -> d);
	visualizzaLista(lista -> next);
}

LINK f25(LINK l1,LINK l2, int pos) {
    LINK p;
    if (l1 != NULL && l2!=NULL) {
        if ((l1->d + l2->d) % pos == 0) {
            p = malloc(sizeof(ELEMENT));
            p->d = l1->d * l2->d;
            p -> next = f25(l1->next, l2->next,  pos+1);
            return p;
        }
        else return f25(l1->next, l2->next,  pos+1);
    }
    else return NULL;
}

int main() {
	LINK lista1 = NULL;
	LINK lista2 = NULL;
	LINK lista3 = NULL;
	srand(time(NULL));
	
	lista1 = creaLista(10);
	lista2 = creaLista(10);
	
	visualizzaLista(lista1);
	visualizzaLista(lista2);
	
	lista3 = f25(lista1, lista2, 1);
	visualizzaLista(lista3);
}