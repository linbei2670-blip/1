#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	Node* next;
}Node;
void freelist(Node* L);
void Listnode(Node* L);
Node* ListInitiate();
void Inserthead(Node* L, int e);
void Listfind(Node* L,int n);
Node* ListInitiate() {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		printf("内存分配失败！\n");
		return NULL;
	}

	head->data = 0;
	head->next = NULL;
	return head;
}
void Inserthead(Node* L, int e) {
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL) {
		printf("p的内存分配失败");
		return;
	}
	p->data = e;
	p->next = L->next;
	L->next = p;
}
void Listnode(Node* L) {
	Node* p = L->next;
	while (p != NULL) {
		printf("%d", p->data);
		if (p->next != NULL) {
			printf(" ");
		}
		else {
			printf("\n");
		}
		p = p->next;
	}


}
void freelist(Node* L) {
	if (L == NULL) return;
	Node* p = L;
	Node* q = NULL;;
	while (p != NULL) {
		if (p != L) {
			printf("当前清理的节点数据为%d\n", p->data);
		}
		q = p->next;
		free(p);
		p = q;
	}
}
void Listfind(Node* L,int n) {
	Node* fast = L;
	Node* slow = L;

	for (int i = 0; i < n; i++) {
		fast = fast->next;
		if (fast == NULL) {
			printf("长度错误\n");
			return;
		}
	}
	while (fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	if (slow != NULL) {
		printf("倒数第%d个元素为%d\n", n, slow->data);
	}
}
int main() {
	Node* list;
	list = ListInitiate();
	int e;
	Inserthead(list, 10);
	Inserthead(list, 20);
	Inserthead(list, 30);
	Inserthead(list, 40);
	Inserthead(list, 50);
	Listnode(list);

	int n;
	printf("请输入要查找的倒数第n个元素");
	scanf("%d", &n);
	Listfind(list,n);

	freelist(list);
	return 0;
}