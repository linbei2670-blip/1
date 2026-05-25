#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct Node {
	int data;
	Node* next;
}Node;

typedef struct queue {
	Node* front;
	Node* rear;
}queue;

queue* queueinitiate();
void inqueue(queue* q, int e);
void dequeue(queue* q, int *e);

queue* queueinitiate() {
	queue* p = (queue*)malloc(sizeof(queue));
	Node* node = (Node*)malloc(sizeof(Node));
	assert(node != NULL);
	node->next = NULL;
	node->data = 0;
	assert(p != NULL);
	p->front = node;
	p->rear = node;
	return p;
}
void inqueue(queue* q, int e) {
	Node* newnode;
	newnode = (Node*)malloc(sizeof(Node));
	assert(newnode != NULL);
	newnode->data = e;
	newnode->next = NULL;
	q->rear->next = newnode;
	q->rear = newnode;
	printf("入队元素为%d\n", newnode->data);
}
void dequeue(queue* q,int *e){
	if (q->front == q->rear) {
		printf("队列已空");
		return;
	}
	Node* p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if (p == q->rear) {
		q->rear = q->front;
	}
	printf("出队元素为%d\n", *e);
	free(p);
}
int main() {
	queue* q = queueinitiate();

	inqueue(q, 2);
	inqueue(q, 6);
	inqueue(q, 7);
	inqueue(q, 0);
	int e;
	printf("----出队----\n");
	dequeue(q, &e);
	dequeue(q, &e);
	dequeue(q, &e);
	dequeue(q, &e);
	return 0;
}
