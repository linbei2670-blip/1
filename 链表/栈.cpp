#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define maxsize 10
typedef struct stack {
	int data[maxsize];
	int top;
}stack;
void stackinitiate(stack* s);
int push(stack* s, int e);
int pop(stack* s, int* n);

void stackinitiate(stack* s) {
	s->top = -1;
}

int push(stack* s, int e) {
	if (s->top >= maxsize - 1) {
		printf("栈内元素已满");
		return 1;
	}
	else {
		s->top++;
		s->data[s->top] = e;
		return 0;
	}

}

int pop(stack* s, int* n) {
	while (s->top != -1) {
		if (s->top == -1) {
			printf("栈已空");
			return 1;
		}
		else {
			*n = s->data[s->top];
			s->top--;
			printf("出栈元素为%d\n", *n);
		}
	}
	return 0;
}

int main() {
	stack s;
	stackinitiate(&s);
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	int n;
	pop(&s, &n);
	return 0;
}