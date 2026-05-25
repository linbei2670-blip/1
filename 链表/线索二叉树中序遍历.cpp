#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
typedef struct TreeNode {
	char data;
	TreeNode* lchild;
	TreeNode* rchild;
	int ltag;
	int rtag;
}TreeNode;

typedef TreeNode* Threadtree;

Threadtree pre = NULL;

void CreatTree(Threadtree* T, char str[], int* index);
void HeadThreading(Threadtree T, Threadtree* head);
void Threading(Threadtree T);
void InOrder(Threadtree T);

void CreatTree(Threadtree* T, char str[], int* index) {
	char ch = str[(*index)++];
	if (ch == '#') {
		*T = NULL;
	}
	else {
		*T = (Threadtree)malloc(sizeof(TreeNode));
		assert(*T != NULL);
		(*T)->data = ch;
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		CreatTree(&(*T)->lchild, str, index);
		CreatTree(&(*T)->rchild, str, index);
	}
}

void HeadThreading(Threadtree T, Threadtree* head) {
	*head = (Threadtree)malloc(sizeof(TreeNode));
	assert(*head != NULL);
	if (T == NULL) {
		(*head)->lchild = *head;
		return;
	}
	(*head)->ltag = 0;
	(*head)->rtag = 1;
	(*head)->lchild = T;
	(*head)->rchild = (*head);
	pre = *head;

	Threading(T);

	(*head)->rchild = pre;
	pre->rchild = (*head);
}
void Threading(Threadtree T) {
	if (T != NULL) {
		Threading(T->lchild);
		if (T->lchild == NULL) {
			T->ltag = 1;
			T->lchild = pre;
		}
		if (pre->rchild == NULL) {
			pre->rtag = 1;
			pre->rchild = T;
		}
		pre = T;
		Threading(T->rchild);
	}
}
void InOrder(Threadtree T) {
	Threadtree curr = T->lchild;
	while (curr != T) {
		while (curr->ltag==0) {
			curr = curr->lchild;
		}
		printf("%c", curr->data);
		while (curr->rtag==1&&curr->rchild!=T) {
			curr = curr->rchild;
			printf("%c", curr->data);
		}
		curr = curr->rchild;
	}
	printf("\n");
}

int main() {
	int i = 0;
	char str[] = "ABDH#K###E##CFI###G#J##";
	Threadtree tree = NULL;
	Threadtree head = NULL;
	CreatTree(&tree, str, &i);

	HeadThreading(tree,&head);

	InOrder(head);

	return 0;
}
