#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 11 // giorno più lungo (mercoledi)
struct node
{
int giorno_numero;
char giorno_nome[DIM];
int temperatura;
struct node *next;
};
typedef struct node Node; // definisce un alias Node
void lista_inserisci_coda(Node **head, int giorno_numero, char *giorno_nome, int
temperatura);
void lista_visualizza(Node *head);
int lista_leggi_da_file(FILE *fp, Node **head);
void lista_media_temperature(Node *head, int *somma, float *media, int n);
int lista_nodi_sopra_media(Node *head, float media);
void liste_cerca_giorno(Node *head, char *giorno_cercato, int *trovato);
int lista_cancella_nodo(Node **head, Node *nodo);
int lista_cancella_giorno(Node **head, int giorno_cercato);
/*
* Main del programma
*/
int main(int argc, char *argv[])
{
 printf("\n");
 if (argc!=2)
 {

 printf("Errore: numero di argomenti non corretto (inserire come argomento il nome file)\n");
 return 1; // errore
 }
 else
 {
 char *f1 = argv[1]; // file con i dati
 FILE *fp1 = fopen(f1, "r");
 if (fp1!=NULL)
 {
 char giorno_cercato[DIM];
 int n = 0; // nodi creati
 Node *head=NULL;
 n = lista_leggi_da_file(fp1, &head);
 printf("Lista creata (%d nodi): \n", n);
 lista_visualizza(head);
 float media = 0;
 int somma = 0;
 lista_media_temperature(head, &somma, &media, n);
 printf("\n");
 printf("\n");
 printf("Temperatura media: %.2f", media);
 printf("\n");
 printf("\n");
 int sopra_media = lista_nodi_sopra_media(head, media);
 printf("Numero di nodi strettamente superiori alla media: %d", sopra_media);
 printf("\n");
 printf("\n");
 printf("Inserire il nome del giorno di cui si desidera conoscere le temperature: ");
 gets(giorno_cercato);
 /* anziché gets()
 fgets(giorno_cercato, DIM-1, stdin);
 giorno_cercato[strlen(giorno_cercato)-1] = '\0';
 */
 int trovato = 0;
 printf("Ricerca...\n");
 liste_cerca_giorno(head, giorno_cercato, &trovato);
 printf("\n");
 int gg = 0;
 do
 {
 printf("Scegliere il numero di giorno da cancellare (tra 1 e %d): ", n);
 scanf("%d", &gg);
 }
 while (gg < 1 || gg > 15);
 printf("\n");
 int c = lista_cancella_giorno(&head, gg);
 printf("%d nodo cancellato\n\n", c);
 printf("Lista aggiornata: \n");
 lista_visualizza(head);
 return 0; // nessun errore
 }
 }
}
/*
* Legge i dati dal file e li salva nella lista
* @param *fp puntatore al file da leggere
* @param Node **head riferimento alla testa della lista
* @return i numero di nodi creati
*/
int lista_leggi_da_file(FILE *fp, Node **head)
{
 int i = 0;
 while (!feof(fp))
 {
int giorno_numero;
char giorno_nome[DIM];
int temperatura;
int nB = fscanf(fp, "%d %s %d", &giorno_numero, giorno_nome, &temperatura);
if (nB>0)
{
 lista_inserisci_coda(head, giorno_numero, giorno_nome, temperatura);
 i++;
}
 }
 return i;
}
/*
* Aggiunge un nodo in coda alla lista
* @param Node **head riferimento alla testa della lista
* @param giorno_numero, giorno_nome, temperatura valori per i nodi
*/
void lista_inserisci_coda(Node **head, int giorno_numero, char *giorno_nome, int temperatura)
{
 // 1) alloca il nuovo nodo
Node *new_node = (Node*) malloc(sizeof(Node));
 // 2) puntatore per trovare l'ultimo nodo
 Node *last = *head;
 if (new_node != NULL) // se riesce a creare il nuovo nodo
 {
 // 3) inserisce i dati nel nodo
 new_node->giorno_numero = giorno_numero;
 strcpy(new_node->giorno_nome, giorno_nome);
 new_node->temperatura = temperatura;
 // 4) imposta a NULL il campo next del nuovo nodo (visto che sarà l'ultimo)
 new_node->next = NULL;
 // 5) se la lista è vuota l'ultimo nodo è la testa
 if (*head == NULL)
 {
 *head = new_node;
 return;
 }
 // 6) se la lista non è vuota trova l'ultimo nodo
 while(last->next != NULL)
 {
 last=last->next;
 }
 // 7) all'ultimo nodo aggancia il nuovo nodo
 last->next = new_node;
 }
 else
 {
 printf("Errore nella creazione del nodo in memoria, lista non modificata \n");
 }
}
/*
* Visualizza una lista
* @param Node *head testa della lista
*/
void lista_visualizza(Node *head)
{
if (head==NULL)
{
 printf("NULL");
 return;
}
else
{
 printf("%d\t| %s\t| %d \n", head->giorno_numero, head->giorno_nome, head->temperatura);
 return lista_visualizza(head->next);
}
}
/*
* Calcola la media delle temperature in modo ricorsivo
* @param Node *head è la testa della lista (per valore)
* @param int *somma è il riferimento alla somma
* @param float *media è il riferimento alla media
* @param int n è il numero di nodi della lista (per valore)
*/
void lista_media_temperature(Node *head, int *somma, float *media, int n)
{
 if (head==NULL)
 {
*media = (float) *somma / n;
return;
 }
 else
 {
*somma = *somma + head->temperatura;
return lista_media_temperature(head->next, somma, media, n);
 }
}
/*
* Conta i nodi sopra la media in modo ricorsivo
* @param Node *head è la testa della lista (per valore)
* @param float media è la media già calcolata (per valore)
* @return numero di nodi sopra la media
*/
int lista_nodi_sopra_media(Node *head, float media)
{
 if (head==NULL)
 {
return 0;
}
 else
 {
if (head->temperatura > media)
{
 return 1 + lista_nodi_sopra_media(head->next, media);
}
else
{
 return 0 + lista_nodi_sopra_media(head->next, media);
}
 }
}
/*
* Cerca una stringa nella lista
* @param Node *head è la testa della lista (per valore)
* @param char *giorno_cercato è la stringa del giorno
* @param int *trovato numero di volte che è stato trovato il giorno
*/
void liste_cerca_giorno(Node *head, char *giorno_cercato, int *trovato)
{
 if (head==NULL)
 {
printf("Ricerca conclusa; numero di occorrenze '%s' trovate: %d\n", giorno_cercato,
*trovato);
return;
 }
 else
 {
if (strcmp(head->giorno_nome,giorno_cercato)==0)
{
 *trovato = *trovato + 1;
 printf("%d\t| %s\t| %d \n", head->giorno_numero, head->giorno_nome, head->temperatura);
}
return liste_cerca_giorno(head->next, giorno_cercato, trovato);
 }
}
/*
* Dato il numero di un giorno, cancella la prima occorrenza del nodo che contiene di tale
valore
* @param Node ** riferimentotesta della lista
* @param giorno_cercato numero del giorno cercato
* @return numero di nodi cancellati (0 o 1)
*/
int lista_cancella_giorno(Node **head, int giorno_cercato)
{
 Node *temp = *head;
 int c = 0; // contatore dei nodi cancellati
 if (*head == NULL) // lista vuota
 return 0;
 while(temp!=NULL)
 {
 // printf("Nodo: %d \n", temp->data); // debug
 if (temp->giorno_numero==giorno_cercato)
 {
 Node * del = temp; // del è il riferimento al nodo da cancellare
 temp = temp->next; // sposta il puntatore al Node successivo
 c = c + lista_cancella_nodo(head, del);
 }
 else
 {
 temp = temp->next; // sposta il puntatore al Node successivo
 }
 }
 return c;
}
/*
* Dato il riferimento a uno nodo, cancella la prima occorrenza del nodo che contiene di tale
valore
* @param Node ** riferimentotesta della lista
* @param Node * nodo da cancellare
* @return 1 se ha trovato e cancellato il nodo, 0 altrimenti
*/
int lista_cancella_nodo(Node **head, Node *nodo)
{
 Node *temp = *head;
 Node *prev = NULL; // precedente
 // se la testa contiene il nodo cercato (confronto tra indirizzi)
 if (temp != NULL && temp == nodo)
 {
 *head = temp->next; // cambia la testa
 free(temp); // cancella la vecchia testa
 return 1;
 }
 // cerca il nodo da cancellare nei nodi
 // tenendo traccia del nodo precedente rispetto a quello cercato
 while (temp != NULL && temp != nodo) // confronto tra indirizzi
 {
 prev = temp;
 temp = temp->next;
 }
 // se il nodo non è stato trovato
 if (temp == NULL)
 return 0;
 // scollega il nodo da cancellare:
 // il nodo precedente punta a quello successivo rispetto a quello da cancellare
 prev->next = temp->next;
 free(temp); // svuota la memoria del nodo da cancellare
 return 1;
}