#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define maxsize 7

typedef struct queue {
	int front;
	int rear;
	char* data;
}queue;

int inqueue(queue* q,char i);
int dequeue(queue* q);
queue* queueinitiate();
int Isempty(queue* q);

queue* queueinitiate() {
	queue* q = (queue*)malloc(sizeof(queue));
	q->data = (char*)malloc(sizeof(char) * maxsize);
	assert(q->data != NULL);
	q->front = 0;
	q->rear = 0;
	return q;
}
int inqueue(queue* q,char i) {
	if ((q->rear+1)%maxsize==q->front) {
		printf("队列已满\n");
		return 0;
	}
		q->data[q->rear]=i;
		q->rear=(q->rear+1)%maxsize;
		return 1;
}
int dequeue(queue* q) {
		if (Isempty(q) ){
			printf("队列已空\n");
			return 0;
		}
		int e = q->data[q->front];
		q->front = (q->front + 1) % maxsize;
		printf("出队元素为%c\n",  e);
		return 1;
}
int Isempty(queue* q) {
	if (q->rear == q->front) {
		printf("队列已空\n");
		return 1;
	}
	return 0;
}

int main() {
	queue* list = queueinitiate();
	Isempty(list);
	inqueue(list, 'l');
	inqueue(list, 'i');
	inqueue(list, 'u');
	inqueue(list, 'y');
	inqueue(list, 'a');
	inqueue(list, 'n');
	int i = list->front;
	while (i != list->rear) {
		printf("%c\n", list->data[i]);
		i = (i + 1) % maxsize; 
	}
	int e;
	dequeue(list);
	dequeue(list);
	dequeue(list);
	dequeue(list);
	dequeue(list);
	dequeue(list);
	free(list->data); 
	free(list);
	list = NULL;
	return 0;
}