#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

#define MAXSIZE 100
#define INF 0x3f3f3f3f
typedef struct  {
	char vertex[MAXSIZE];
	int arc[MAXSIZE][MAXSIZE];
	int vertexes;
	int visited[MAXSIZE];
}Matrixgraph;

void makegraph(Matrixgraph* M);
void prime(Matrixgraph* M, char start);

void makegraph(Matrixgraph* M) {
	M->vertex[0] = 'A';
	M->vertex[1] = 'B';
	M->vertex[2] = 'C';
	M->vertex[3] = 'D';
	M->vertex[4] = 'E';
	M->vertex[5] = 'F';
	M->vertex[6] = 'G';
	M->vertex[7] = 'H';
	M->vertex[8] = 'I';
	M->vertexes = 9;
	for (int i = 0; i < M->vertexes; i++) {
		for (int j = 0; j < M->vertexes; j++) {
			if (i == j) {
				M->arc[i][j] = 0;
			}
			else {
				M->arc[i][j] = INF;
			}

		}
	}
		//A
		M->arc[0][1] = 10;
		M->arc[0][5] = 11;
		//B
		M->arc[1][2] = 18;
		M->arc[1][8] = 12;
		M->arc[1][6] = 16;
		//C
		M->arc[2][3] = 22;
		M->arc[2][8] = 8;
		//D
		M->arc[3][4] = 20;
		M->arc[3][6] = 24;
		M->arc[3][7] = 16;
		M->arc[3][8] = 21;
		//E
		M->arc[4][5] = 26;
		M->arc[4][7] = 7;
		//F
		M->arc[5][6] = 17;
		//G
		M->arc[6][7] = 19;
		for (int i = 0; i < M->vertexes; i++) {
			for (int j = 0; j < M->vertexes; j++) {
				M->arc[j][i] = M->arc[i][j];
			}
		}
}
void prime(Matrixgraph* M,char start) {
	int weight[MAXSIZE];
	int vex_index[MAXSIZE];
	int i, j, k;
	j = 0;
	int min = INF;
	for(i = 0; i < M->vertexes; i++) {
		if (M->vertex[i] == start) {
			for (j = 0; j < M->vertexes; j++) {
				weight[j] = M->arc[i][j];
				vex_index[j] = i;
			}
			break;
		}
	}
	for (i = 1; i < M->vertexes; i++) {
		min = INF;
		j = 0;
		k = 0;
		while (j < M->vertexes) {
			if (weight[j] != 0 && weight[j] < min) {
				min = weight[j];
				k = j;
			}
			j++;
		}
		printf("%c-%c\t", M->vertex[vex_index[k]], M->vertex[k]);
		weight[k] = 0;
		for (j = 0; j < M->vertexes; j++) {
			if (weight[j] != 0 && M->arc[k][j] < weight[j]) {
				weight[j] = M->arc[k][j];
				vex_index[j] = k;
			}
		}
	}
}

	int main() {
		Matrixgraph M;
		makegraph(&M);
		printf("请输入起始顶点:");
		char start;
		scanf("%c", &start);
		prime(&M,start);
		return 0;
	}
