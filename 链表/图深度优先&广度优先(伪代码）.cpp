#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
	char vertex[MAXSIZE];
	int arc[MAXSIZE][MAXSIZE];
	int numvertexes;
	int numarcs;
}MatrixGraph;

void CreatGraph(MatrixGraph* G);
void DepthFirstSearch(MatrixGraph* G, int n,int* visited);
void BroadFirstSearch(MatrixGraph* G, int n, int* visited);

void CreatGraph(MatrixGraph* G) {
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';
	G->numvertexes = 9;
	G->numarcs = 15;
	for (int i = 0; i < G->numvertexes;i++) {
		for (int j = 0; j < G->numvertexes; j++) {
			G->arc[i][j] = 0;
		}
	}
}

void DepthFirstSearch(MatrixGraph* G, int n, int* visited) {
	visited[n] = 1;
	printf("%c\t", G->vertex[n]);
	for (int j = 0; j < G->numvertexes; j++) {
		if (visited[j] == 0 && G->arc[n][j] == 1) {
			DepthFirstSearch(G, j, visited);
		}
	}
}
void BroadFirstSearch(MatrixGraph* G, int n, int* visited) {
	int queue[MAXSIZE];
	int front = 0;
	int rear = 0;
	int i;
	visited[n] = 1;
	printf("%c\t", G->vertex[n]);
	queue[rear] = n;
	rear++;
	while (rear != front) {
		i = queue[front++];
		for (int j = 0; j < G->numvertexes; j++) {
			if (visited[j] == 0 && G->arc[i][j] == 1) {
				visited[j] = 1;
				printf("%c\t",G->vertex[j]);
				queue[rear] = j;
				rear++;
			}
		}
	}

}
int main() {
	int visited[MAXSIZE];
	MatrixGraph G;
	CreatGraph(&G);
	for (int i = 0; i < G.numvertexes; i++) {
		visited[i] = 0;
	}
	//
	//
	//
	//¸³Öµ²Ù×÷
	//
	//
	//
	for (int i = 0; i < G.numvertexes; i++) {
		for (int j = 0; j < G.numvertexes; j++) {
			if (G.arc[j][i] == 1) {
				G.arc[i][j] = G.arc[j][i];
			}
			else {
				G.arc[j][i] = G.arc[i][j];
			}
		}
	}
	DepthFirstSearch(&G, 0, visited);
	BroadFirstSearch(&G, 0, visited);

	return 0;
}