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

LINK findpred(int x, LINK lis) {
    int trovato=0;
    if (lis == NULL) {
        printf("lista vuota\n");
        return(NULL);
        }
    else {
         if (lis->d == x) {
            printf("%d e' a inizio lista\n", x);
            return(NULL);
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

/*
 ESERCIZI SVOLTI
 */

// 24 LUGLIO - TURNO 1 - EXE 1
int f1(LINK lis) {
    int cnt, current, max;
    cnt = 0;
    max = 0;
    /* inizializzazione; */
    if (lis != NULL) {
        current = lis->d;
        cnt = 1;
        lis = lis->next;
    }
    /* passo iterativo*/
    while (lis != NULL) {
        if(lis->d == current) {
            cnt++;
        } else {
            if (cnt >= max) max = cnt;
            current = lis->d;
            cnt = 1;
        }
        lis = lis->next;
    }
    //necessario se gli ultimi elementi sono quelli di maggiore numerosità
    if (cnt >= max) max = cnt;
    return max;
}

//24 LUGLIO TURNO 1 - EXE 2
// stiamo supponendo che la prima posizione sia la posizione 1.
// Ci vogliamo fermare al nodo precedente il nodo di posizione k
//k > 0
void f2(LINK *lis, int k, int cnt) {
    LINK p;
    if (*lis != NULL) {
        if (k == 1) {
            p = *lis;
            (*lis) = (*lis)->next;
            free(p);
        } else if (cnt == k-1  && (*lis)->next != NULL) {
            p = (*lis)->next;
            (*lis)->next = (*lis)->next->next;
            free(p);
        } else f2(&((*lis)->next),k, cnt+1);
    }
}

void f2_alt(LINK *lis, int k) {
    LINK p;
    if (*lis != NULL) {
        if (k == 1) {
            p = *lis;
            (*lis) = (*lis)->next;
            free(p);
        } else f2_alt(&((*lis)->next),k-1);
    }
}

//24 LUGLIO TURNO 2 - EXE 1

LINK f3(LINK l1, LINK l2) {
    LINK head, tail,p;
    head = NULL;
    tail = NULL;
    while (l1 != NULL && l2 != NULL) {
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l2 != NULL) {
            p = newnode();
            p->d = l2->d;
            p->next = NULL;
            if(head == NULL) {
                head = p;
                tail =p;
            } else {
                tail->next = p;
                tail = tail -> next;
                }
            l2= l2->next;
    }
    while (l1 != NULL) {
            p = newnode();
            p->d = l1->d;
            p->next = NULL;
            if(head == NULL) {
                head = p;
                tail =p;
            } else {
                tail->next = p;
                tail = tail -> next;
                }
            l1= l1->next;
    }
    return head;
}

//24 LUGLIO TURNO 2 - EXE 2
void f4(LINK *lis, int k) {
    LINK p;
    if(*lis != NULL) {
        if ((*lis)->d == k) {
            p = (*lis);
            (*lis) = (*lis)->next;
            free(p);
        } else f4(&((*lis)->next),k);
    }
}



//27 LUGLIO TURNO 2 - EXE 1
void f5(LINK *lis, int m, int n) {
    int pos =1;
    LINK p,q;
    if (m == 1 ) { // cancelliamo in testa;
        while (*lis != NULL && pos < n) {
            p = *lis;
            *lis = (*lis) ->next;
            free(p);
            pos++;
        }
        
    } else {
        p= *lis;
        while ((pos < (m - 1)) && p != NULL) {
            pos++;
            p = (p)->next;
        }// a questo punto p punta all'elemento prima di quello da cancellare
        if(p != NULL) {
            while (pos < n  && p->next != NULL) {
                q = p->next;
                p-> next = q->next;
                free(q);
                pos++;
            }
        }
    }
}
        
//27 LUGLIO TURNO 2 - EXE 2
int f6_rt(LINK L1, LINK L2, int *cnt1, int *cnt2) {
    if (L1 != NULL && L2 != NULL) {
        *cnt1 += L1->d;
        *cnt2 += L2->d;
        return f6_rt(L1->next,L2->next, cnt1, cnt2);
    }
    else if (L1 != NULL && L2 == NULL) {
        *cnt1 += L1->d;
        return f6_rt(L1->next,L2, cnt1, cnt2);
    }
    else if (L1 == NULL && L2 != NULL) {
        *cnt2 += L2->d;
        return f6_rt(L1,L2->next, cnt1, cnt2);
    }
    else {
        if (*cnt1 >= *cnt2) return *cnt1;
        else return *cnt2;
    }
}


int f6(LINK L1, LINK L2, int cnt1, int cnt2) {
    if (L1 != NULL && L2 != NULL) {
        return f6(L1->next,L2->next, cnt1+ L1->d, cnt2+ L2->d);
    }
    else if (L1 != NULL && L2 == NULL) {
        return f6(L1->next,L2, cnt1+ L1->d, cnt2);
    }
    else if (L1 == NULL && L2 != NULL) {
        return f6(L1,L2->next, cnt1, cnt2+ L2->d);
    }
    else {
        if (cnt1 >= cnt2) return cnt1;
        else return cnt2;
    }
}


//prima sessione luglio 2020 - turno 1 esercizio 1
int f7(LINK *lis, int x) {
    int cnt = 0;
    LINK p,q;
    int flag =0;
    while (*lis != NULL && flag == 0) {
        if ((*lis)->d % x == 0) {
            p =*lis;
            *lis= (*lis)->next;
            free(p);
            cnt++;
        } else flag = 1;
    }
    p = *lis;
    if(p!= NULL) {
        while (p->next != NULL) {
            if (p->next->d % x == 0) {
                q =p->next;
                p->next= q->next;
                free(q);
                cnt++;
            } else p = p->next;
        }
    }
    return cnt;
}

//prima sessione luglio 2020 - turno 1 esercizio 2
int f8(LINK l1, LINK l2, int n) {
    int flag;
    if (l1 != NULL && l2!=NULL) {
        if (n>0) return f8(l1->next, l2->next, n-1);
        else if (l1->d == l2->d) return f8(l1->next, l2->next, 0);
        else return 0;
    }
    if ((l1 != NULL && l2 == NULL) || (l1 == NULL && l2!=NULL)) return 0;
    else if (l1 == NULL && l2 == NULL  && n>0) return 0;
    else return 1;
}

//prima sessione luglio 2020 - turno 1 esercizio 2
//è l'esempio 2 delle slides relative a più liste in input
LINK f9(LINK l1, LINK l2) {
    LINK p, head, tail;
    head=NULL; tail=NULL;
    while ((l1 != NULL) && (l2 != NULL)) {
           p=newnode();
        p->d = l1->d+l2->d;
        p->next = NULL;
        if (head == NULL){ head=p; tail=p;}         else { tail->next=p; tail=p;}
        l1 = l1->next;
        l2 = l2->next;
    }
     while (l1 != NULL) {
        p=newnode();
        p->d = l1->d;
        p->next = NULL;
        if (head == NULL){head=p; tail=p;}         else {tail->next=p; tail=p;}
        l1 = l1->next;
    }
    while (l2 != NULL) {
        p=newnode();
        p->d = l2->d;
        p->next = NULL;
        if (head == NULL){head=p; tail=p;}
        else {tail->next=p; tail=p;}
        l2 = l2->next;
    }
    return (head);
}

//inizialmente cnt e sum posti a 0
double f10(LINK lis, double sum, int cnt) {
    if (lis == NULL) {
        if (cnt == 0) return 0;
        else return (sum / cnt);
    }
    else return f10(lis->next, sum + lis->d, cnt+1);
}

//ESERCIZIO 1 SLIDE 18
int f11(LINK lis, int x) {
    int pos, sum;
    pos =1;
    sum =0;
    while (lis != NULL) {
        if (pos % x == 0) {
            sum = sum + lis->d * pos;
        }
        pos++;
        lis = lis -> next;
    }
    return sum;
}

//ESERCIZIO 2 SLIDE 18
int f12(LINK lis, int n) {
    int pos, prima, dopo;
    pos =1;
    prima =0;
    dopo =0;
    while (lis != NULL) {
        if (pos <= n)
            prima += lis->d;
         else
            dopo += lis->d;
        pos++;
        lis = lis -> next;
    }
    return prima - dopo;
}

//ESERCIZIO 1 SLIDE 19
int f13(LINK lis, int x) {
    int n;
    n=0;
    if(lis == NULL) return 0;
    else if (lis->next == NULL) return 0;
    else if (lis->next->next == NULL) return 0;
    while (lis->next->next != NULL) {
        if ((lis->d == x) && (lis->next->d == x) && (lis->next->next->d ==x )) {
            n++;
        }
        lis = lis->next;
    }
    return n;
}

//ESERCIZIO 2 SLIDE 19
void f14(LINK lis, int x, int n) {
    int pos;
    LINK p;
    pos = 1;
     while ((lis) != NULL) {
        if ((lis->d == x) && (pos % n == 0)) {
            p = newnode();
            p->d = x;
            p->next = (lis)->next;
            lis->next = p;
            lis = lis->next->next;
        } else
            lis = (lis)->next;
         pos++;
    }
}

//ESERCIZIO 1 SLIDE 20

//ESERCIZIO 2 SLIDE 20

//ESERCIZIO 1 SLIDE 21

//ESERCIZIO 2 SLIDE 21

//ESERCIZIO 1 SLIDE 22

//ESERCIZIO 2 SLIDE 22

//ESERCIZIO 1 SLIDE 23 RICORSIVO
//max e n inizializzati a 0
int f21(LINK l1,int n,int max) {
    if (l1 == NULL) return n;
    else if (l1->d < max) return f21(l1->next,n,max);
    else if (l1->d == max) return f21(l1->next,n+1,max);
    else  return f21(l1->next,1,l1->d); //if (l1->d > max)
}
//ESERCIZIO 2 SLIDE 23 RICORSIVO
int f22(LINK l1) {
    if (l1 == NULL) return 1;
    if (l1->next == NULL) return 1;
    if (l1->d < l1->next->d) return f22(l1->next);
    else return 0;
}
//ESERCIZIO 1 SLIDE 24 RICORSIVO
//cnt inizialmente a 0
int f23(LINK l1,LINK l2) {
    int flag;
    if (l1 != NULL && l2!=NULL) {
        if (l1->d == l2->d) return 1+f23(l1->next, l2->next);
        else return f23(l1->next, l2->next);
    }
    else return 0;
}

//ESERCIZIO 2 SLIDE 24 RICORSIVO
//pos chiamato inizialmente con valore 1
LINK f24(LINK l1,LINK l2, int pos) {
    LINK p;
    int diff;
    if (l1 != NULL && l2!=NULL) {
        diff = l1->d - l2->d;
        if (diff % pos == 0) {
            p = newnode();
            p->d = diff;
            p -> next = f24(l1->next, l2->next,  pos+1);
            return p;
        }
        else return f24(l1->next, l2->next,  pos+1);
    }
    else return NULL;
}

//ESERCIZIO 1 SLIDE 25 RICORSIVO
LINK f25(LINK l1,LINK l2, int pos) {
    LINK p;
    if (l1 != NULL && l2!=NULL) {
        if ((l1->d + l2->d) % pos == 0) {
            p = newnode();
            p->d = l1->d * l2->d;
            p -> next = f24(l1->next, l2->next,  pos+1);
            return p;
        }
        else return f24(l1->next, l2->next,  pos+1);
    }
    else return NULL;
}

int main() {
  LINK a;
LINK b;
LINK c = NULL;
LINK d = NULL;
LINK tail = NULL;
    LINK z1,z2;
    int pos =1;
    int tot;
    
    int tmp1 =0 ,tmp2 =0;
    
    int arr[19] ={1,4,5,3,3,3,2,2,2,5,5,2,5,3,3,3,3,3,3};
    int arr2[4] ={1,2,3,5};
    int arr3[4] ={2,2,3,5};
    
    int arr5[7] ={3,4,3,7,8,6,1};
    int arr6[10] ={1,4,2,7,2,12,2,16,7,2};

   // da usare in sostituzione a buildlist_rnf nel caso in cui si simuli su pythonauthor
    a = buildlis_alt(arr,0,18);
    b = buildlis_alt(arr2,0,3);
    d = buildlis_alt(arr3,0,3);
    z1 = buildlis_alt(arr5,0,6);
    z2 = buildlis_alt(arr6,0,9);
    
    printlis_rt(a);
    
    printf("Soluzione esercizio 1: %d \n", f1(a));
 //   f2(&a,1,1);
    f2_alt(&a,2);
     
    printlis_rt(a);
    c=f3(a,b);
    printlis_rt(c);
    
   // f4(&a,1);
    printf("Soluzione esercizio 4: CANCELLO 3  \n");
    printlis_rt(a);
    f4(&a,4);
    printlis_rt(a);
   // f5(&a,3,6);
   // printlis_rt(a);
    printf("Soluzione esercizio 6: %d \n", f6_rt(a,b,&tmp1,&tmp2));
    printf("Soluzione esercizio 6: %d \n", f6(a,b,0,0));

    //printf("Soluzione esercizio 7: %d \n", f7(&a,4));
   // printlis_rt(a);
    /*
    printf("Soluzione esercizio 8: %d \n", f8(b,d,1));
    
    printf("Soluzione esercizio 10:%f  \n", f10(b,0,0));
     printlis_rt(b);
    printf("Soluzione esercizio 11:%d  \n", f11(b,2));
    printf("Soluzione esercizio 12:%d  \n", f12(b,2));
    printf("Soluzione esercizio 13:%d  \n", f13(a,3));
    f14(a,3,5);
    printlis_rt(a);
    printf("Soluzione esercizio 21:%d  \n", f21(a,0,0));
    printf("Soluzione esercizio 22:%d  \n", f22(d));
    printf("Soluzione esercizio 23:%d  \n", f23(b,d));
    c=f24(z1,z2,1);
    printlis_rt(c);
*/
  return 0;
}


