#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
typedef struct TreeNode {
	char data;
	TreeNode* lchild;
	TreeNode* rchild;
}TreeNode;

typedef TreeNode* Bitree;

void CreatTree(Bitree* T, char str[], int* index);
void PreOrder(Bitree T);
void InOrder(Bitree T);
void PostOrder(Bitree T);

void CreatTree(Bitree *T, char str[],int* index) {
	char ch = str[(*index)++];
	if (ch == '#') {
		*T = NULL;
	}
	else {
		*T = (Bitree)malloc(sizeof(TreeNode));
		assert(*T != NULL);
		(*T)->data = ch;
		CreatTree(&(*T)->lchild, str, index);
		CreatTree(&(*T)->rchild, str, index);
	}
}
void PreOrder(Bitree T) {
	if (T == NULL) {
		return;
	}
	else {
		printf("%c",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}

}

void InOrder(Bitree T) {
	if (T == NULL) {
		return;
	}
	else {
		InOrder(T->lchild);
		printf("%c", T->data);
		InOrder(T->rchild);
	}

}

void PostOrder(Bitree T) {
	if (T == NULL) {
		return;
	}
	else {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c", T->data);
	}

}

int main() {
	TreeNode* tree=NULL;
	int i = 0;
	char str[] = "ABDH#K###E##CFI###G#J##";
	CreatTree(&tree, str, &i);

	PreOrder(tree);
	printf("\n");
	InOrder(tree);
	printf("\n");
	PostOrder(tree);
	return 0;
}