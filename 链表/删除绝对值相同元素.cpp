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
void InsertTail(Node* L, int e);
int getlength(Node* L);
void listdelete(Node* L);
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
void InsertTail(Node* L, int e) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL) {
		printf("p的内存分配失败");
		return;
	}
	Node* p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	newnode->data = e;
	p->next = newnode;
	newnode->next = NULL;
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

int getlength(Node* L) {
	Node* p = L;
	int Len = 0;
	while (p->next != 0) {
		p = p->next;
		Len++;
	}
	return Len;
}

void listdelete(Node* L) {
	int* p;
	Node* q=L;
	int length = getlength(L);
	p = (int*)malloc(sizeof(int) * (length + 1));
	for (int i = 0; i < length+1; i++) {
		*(p + i) = 0;
	}
	while (q->next!=NULL) {
		int index = abs(q->next->data);
		if (*(p + index) == 0) {
			*(p + index) = 1;
			q = q->next;
		}
		else {
			Node* temp = q->next;
			q->next = temp->next;
			free(temp);

		}
	}
	free(p);
}
int main() {
	Node* list;
	list = ListInitiate();
	InsertTail(list,1);
	InsertTail(list,3);
	InsertTail(list,6);
	InsertTail(list,-1);
	InsertTail(list,7);
	InsertTail(list,2);
	InsertTail(list,-7);
	printf("删除前：");
	Listnode(list);
	
	listdelete(list);
	printf("删除后：");
	Listnode(list);
	
	freelist(list);
	return 0;
}