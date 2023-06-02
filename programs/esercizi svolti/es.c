#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

struct linked_list {
DATA d;
struct linked_list *next;
};

typedef struct linked_list ELEMENT;

typedef ELEMENT * LINK;

void printlis_rt(LINK lis) {
  if (lis != NULL) {
  printf(" %d ->", lis->d);
  printlis_rt(lis->next);
  }
  else printf (" NULL\n");
}

LINK newnode(void) {
return malloc(sizeof(ELEMENT));
/* includere <stdlib.h> */
}

//cancellare ricorsivamente nodi con valore k
void f4(LINK *lis, int k) {
    LINK p;
    if(*lis != NULL) {
        if ((*lis)->d == k) {
            p = (*lis);
            (*lis) = (*lis)->next;
            free(p);
			f4(&(*lis),k);
        } else f4(&((*lis)->next),k);
    }
}

//inserire ricorsivamente nodi dopo nodi di valore k
void f5(LINK lis, int k) {
    LINK p;
    if(lis != NULL) {
        if (lis->d == k) {
            p = newnode();
			p -> d = k;
			p -> next = lis -> next;
			lis -> next = p;
			f5(lis -> next -> next, k);	
        } else f5(lis -> next, k);
    }
}

LINK buildlis_alt(int a[], int x, int n) {
    LINK p;
    if (x> n) return NULL;
    else {
        p=newnode();
        p->d = a[x];
        p->next = buildlis_alt(a, x+1,n);
        return p;
    }
}

int main() {
	LINK lis;
	int arr[19] ={5,4,5,3,3,3,2,2,2,5,5,2,5,3,3,3,3,3,3};
	lis = buildlis_alt(arr,0,18);
	//f4(&lis, 5);
	f5(lis, 4);
	printlis_rt(lis);
}