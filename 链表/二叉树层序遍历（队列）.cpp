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
void levelorder(TreeNode* T);
void levelorder(TreeNode* T) {
	if (T == NULL) {
		return;
	}
	TreeNode* queue[100];
	int rear = 0;
	int front = 0;
	int depth = 0;
	TreeNode* last = T;
	TreeNode* nextlast = NULL;
		queue[rear++] = T;
		TreeNode* p = NULL;
		while (rear > front) {
			p = queue[front++];
			printf("%c", p->data);
			if (p->lchild != NULL) {
				queue[rear++] = p->lchild;
				nextlast = p->lchild;
			}
			if (p->rchild != NULL) {
				queue[rear++] = p->rchild;
				nextlast = p->rchild;
			}
			if (p == last) {
				depth++;
				last = nextlast;
			}
		}
		printf("\nÊ÷µÄ²ãÊýÎª%d\n", depth);
}

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

int main() {
	int i = 0;
	char str[] = "ABDH#K###E##CFI###G#J##";
	TreeNode* tree = NULL;
	CreatTree(&tree, str, &i);
	levelorder(tree);
	return 0;
}
