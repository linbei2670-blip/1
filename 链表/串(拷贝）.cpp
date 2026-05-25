#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define maxsize 100

typedef struct {
	char ch[maxsize];
	int length;
}string;
string* Initiate();
void StrAssign(string* str, char* c);
void printstring(string* str);

string* Initiate() {
	string* p = (string*)malloc(sizeof(string));
	assert(p != NULL);
	p->ch[0] = '\0';
	p->length = 0;
	return p;
}

void StrAssign(string* str, char* c) {
	int i = 0;
	while (*c != '\0' && i < maxsize-1) {
		str->ch[i] = *(c++);
		i++;
	}
	str->ch[i] = '\0';
	str->length = i;
}

void printstring(string* str) {
	if (str->ch == NULL) {
		printf("¿Õ");
		return;
	}
	int i = 0;
	while (str->ch[i] != '\0') {
		printf("%c", str->ch[i]);
		i++;
	}
	return;
}
int main() {
	string *str = Initiate();
	char c[] = { "ÀÏ×Ó½ĞÁõêÌÒÙ" };

	StrAssign(str, c);

	printstring(str);
	free(str);

	return 0;
}