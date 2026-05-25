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
void InOrder(Bitree T);

void CreatTree(Bitree* T, char str[], int* index) {
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
void InOrder(Bitree T) {
	TreeNode *stack[100];
	int top = -1;
	TreeNode* p = T;
	while (p!=NULL||top!=-1){
		while (p != NULL) {
			stack[++top] = p;
				                   //如果这一行print则为前序输出
			p = p->lchild;
		}
		if (top != -1) {
			p = stack[top--];
			printf("%c", p->data); //中序输出
			p = p->rchild;
		}
	}


}

int main() {
	TreeNode* tree = NULL;
	int i = 0;
	char str[] = "ABDH#K###E##CFI###G#J##";
	CreatTree(&tree, str, &i);
	InOrder(tree);
	return 0;
}