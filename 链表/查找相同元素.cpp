#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char data;
	Node* next;
}Node;

Node* listinitiate();
void  tailinsert(Node* L,char c);
void  listconnect(Node* L,Node*N);
int getlength(Node*L);
void commonsearch(Node* L, Node* N,int gap);
void freelist(Node* L);

Node* listinitiate() {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head != 0) {
		head->data = '0';
		head->next = NULL;
		return head;
	}
	return NULL;
}

void tailinsert(Node* L,char c) {
	Node* p = L;
	while (p->next!= NULL) {
		p = p->next;
	}
	Node* word = (Node*)malloc(sizeof(Node));
	if (word != NULL) {
		word->data = c;
		word->next = NULL;
		p->next = word;
	}
}

void listconnect(Node* L,Node*N) {
	Node* p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = N;
}
int getlength(Node* L) {
	Node* p = L;
	int length = 0;
	while (p->next != 0) {
		p = p->next;
		length++;
	}
	return length;
}
void commonsearch(Node*L,Node*N,int gap) {
	Node* fast=L->next;
	Node* slow=N->next;
	for (int i = 0; i < gap; i++) {
		fast = fast->next;
	}
	while (fast != NULL && slow != NULL) {
		if (fast->data == slow->data) {
			printf("共有元素为%c\n", fast->data);
		}
		fast = fast->next;
		slow = slow->next;
	}
}

void freelist(Node* L) {
	if (L == NULL) return;
	Node* p = L;
	Node* q = NULL;;
	while (p != NULL) {
		if (p != L) {
			printf("当前清理的节点数据为%c\n", p->data);
		}
		q = p->next;
		free(p);
		p = q;
	}
}

int main() {
	Node* list1 = listinitiate();
	Node* list2 = listinitiate();
	
	tailinsert(list1, 'l');
	tailinsert(list1, 'o');
	tailinsert(list1, 'a');
	tailinsert(list1, 'd');
	
	tailinsert(list2, 'b');
	tailinsert(list2, 'e');

	Node* common = listinitiate();
	tailinsert(common, 'i');
	tailinsert(common, 'n');
	tailinsert(common, 'g');

	listconnect(list1, common->next);
	listconnect(list2, common->next);

	int len1 = getlength(list1);
	int len2 = getlength(list2);
	int gap = len1 - len2;

	commonsearch(list1, list2,gap);

	Node* pre = list1;
	while (pre->next != NULL && pre->next != common->next) {
		pre = pre->next;
	}
	pre->next = NULL;
	freelist(list1);
	freelist(list2);

	return 0;
}