void mergesort(int arr[], int r, int l) {
	int m;
	if(l < r) {
		m = l + (r - l) / 2;
		mergesort(arr, m, l);
		mergesort(arr, r, m + 1);
		merge(arr, r, l, m);
	}
}

void merge(int arr[], int r, int l, int m) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for(int i = 0; i < n1; i++) 
		L[i] = arr[l + i];
	for(int j = 0; j < n2; j++)
		R[i] = arr[m + 1 + j];
	int k = l, i = 0, j = 0;
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

***********************************************************************

void hanoi(int n, char *a, char *b, char *c) {
	if(n == 1)
		printf("Muovo disco %d da torre %s a torre %s\n", n, a, c);
	else {
		move(n - 1, a, c, b);
		printf("Muovo disco %d da torre %s a torre %s\n", n, a, c);
		move(n - 1, b, a, c);
	}
}

***********************************************************************

void quicksort(int *arr, int l, int r) {
	if(l < r) {
		int pivot = partition(arr, l, r);
		quicksort(arr, l, pivot - 1);
		quicksort(arr, pivot + 1, r);
	}
}

int partition(int *arr, int l, int r) {
	int pivot = arr[r];
	int i = l - 1;
	for(int j = l; j < r; j++) {
		if(arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return i + 1;
}

void swap(int a, int b) {
	int t = a;
	a = b;
	b = t;
}

***********************************************************************

#define MAXLEN 1000
#define EMPTY -1
#define FULL MAXLEN-1

typedef int DATA;	

typedef struct STACK {
	DATA s[MAXLEN];
	int top;
}stack;

void clear(stack *stk) {
	stack -> top = EMPTY;
}

int isEmpty(stack *stk) {
	return ((stk -> top) == EMPTY);	
}

int isFull(stack *stk) {
	return ((stk -> top) == FULL);	
}

int push(DATA i, stack *stk) {
	if(!isFull(stk)) {
		(stk -> top)++;
		stk -> s[stk -> top] = i;
		return TRUE;
	}
	return FALSE;	
}

int pop(DATA *out, stack *stk) {
	if(!isEmpty(stk)) {
		*out = stk -> s[stk -> top--];
		return TRUE;
	}
	return FALSE;
}

int top(DATA *out, stack *stk) {
	if(!isEmpty(stk)) {
		*out = stk -> s[stk -> top];
		return TRUE;
	}
	return FALSE;
}

typedef struct QUEUE{
	LINK front;
	LINK rear;
	int cnt;
}queue;

void clear(queue *q) {
	q -> cnt = EMPTY;
	disposelis(&(q -> front));
	q -> front = NULL;
	q -> rear = NULL;
}

int front(DATA *out, queue *q) {
	if(!isEmpty(q)) {
		*out = q -> front -> d;
		return TRUE;
	}
	return FALSE;
}

int isEmpty(queue *q) {
	return ((q -> cnt) == EMPTY);
}

int isFull(queue *q) {
	return ((q -> cnt) == FULL);
}

int enqueue(DATA i, queue *q) {
	LINK p;
	if(!isFull(q)) {
		p = newnode();
		p -> d = i;
		p -> next = NULL;
		if(q -> rear == NULL) {
			q -> front = p;
			q -> rear = p;
		}
		else {
			q -> rear -> next = p;
			q -> rear = p;
		}
		(q -> cnt)++;
		return TRUE;
	}
	return FALSE;
}

int dequeue(DATA *out, queue *q) {
	LINK p;
	if(!isEmpty(q)) {
		*out = q -> front -> d;
		p = q -> front;
		q -> front = q -> front -> next;
		free(p);
		if(q -> front == NULL)
			q -> rear = NULL;
		(q -> cnt)--;
		return TRUE;
	}
	return FALSE;
}




























