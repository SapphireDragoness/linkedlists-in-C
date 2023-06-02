#include <stdio.h>
#include <stdlib.h>


typedef int DATA;

struct linked_list {
DATA d;
struct linked_list *next;
};

typedef struct linked_list ELEMENT;
typedef ELEMENT * LINK;


LINK newnode(void) {
return malloc(sizeof(ELEMENT));
    /* includere <stdlib.h> */
}

void printlis(LINK lis) {
    while (lis != NULL) {
        printf("%d --> ", lis->d);
        lis= lis->next;
    }
    printf("NULL \n");
}


void insertbefore(int x, int n, LINK *lis){
    int trovato=0;
    LINK p, head;
    head=*lis;
    if (head == NULL) {
        printf("lista vuota\n");
    } else {
        if (head->d == x) {
            p=newnode();
            p->d=n;
            p->next=head;
            *lis=p;
        } else {
            while ((head->next != NULL) && (! trovato))
                if (head->next->d == x)
                    trovato=1;
                else
                    head=head->next;
            if (trovato) {
                p=newnode();
                p->d=n;
                p->next=head->next;
                head->next=p;
            }
            else printf("element non trovato\n");
        }
    }
}

void headinsert(LINK *lis, int x) {
    LINK p;
    p=newnode();
    p->d=x;
    p->next=*lis;
    *lis=p;
}

void removefirst(LINK *lis) {
    LINK p;
    if (*lis != NULL ) {
        p=*lis;
        *lis=(*lis)->next;
        free(p);
    }
}

void disposelis(LINK *lis) {
    LINK p;
    while (*lis != NULL) {
        p=*lis;
        *lis=(*lis)->next;
        free(p);
    }
}

void removelast(LINK *lis) {
    LINK p;
    p=*lis;
    if (p != NULL) {
        if (p->next == NULL) {
            *lis=NULL;
            free(p);
         } else {
            while (p->next->next != NULL)
                p=p->next;
            free(p->next);
            p->next=NULL;
        }
    }
}



LINK findpred(int x, LINK lis) {
    int trovato=0;
    if (lis == NULL) {
        printf("lista vuota\n");
        return(NULL);
        }
    else {
         if (lis->d == x) {
            printf("%d e' a inizio lista\n", x);                                 return(NULL);
        }
        else {
            while ((lis->next != NULL) && (! trovato))
                if (lis->next->d == x)
                    trovato=1;
                else
                    lis=lis->next;
            if (trovato)
                return(lis);
            else
                return(NULL);
        }
    }
}

void removex(LINK *lis, int x) {
    LINK p,q;
    if (*lis != NULL) {
        if ((*lis) ->d == x)  {
            p =*lis;
            *lis= (*lis)->next;
            free(p);
         } else {
            p = findpred (x, *lis);
            if (p != NULL){
                q=p->next;
                p->next= p->next ->next;
                free(q);
            }
        }
    }
}


int main() {
LINK *A;
LINK C;


int n=4;
int i;
    
A = (LINK *) malloc(sizeof(LINK));
*A = NULL;
C = NULL;
    
    
for(i=0;i<n;i++) headinsert(A, 2*i);
for(i=0;i<n;i++) headinsert(&C, 3*i+4);

printlis(*A);
insertbefore(6,5,A);
printlis(*A);
//removefirst(A);
//removelast(A);
//removex(A,4);

printlis(*A);
disposelis(A);
while(C!=NULL) {
   // removefirst(&C);
    removelast(&C);

}
    
    printlis(C);
    disposelis(&C);
    printlis(C);

    


}

