#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <vector>
//using namespace std;
#define HASHMAX 10000
#define MAX_KEY 10
#define a 1

struct Node {
	char key[MAX_KEY];
	Node* next;
};
Node* tb[HASHMAX];
int hash(const char* str) {
	int hash = 401;
	while (*str != '\0') {
		hash = ((hash << 4) + (int)(*str)) % HASHMAX;
		str++;
	}
	return hash % HASHMAX;
}
bool find(const char* key) {
	int index = hash(key);
	Node* cur = tb[index];
	while (cur != NULL) {
		if (strcmp(cur->key, key) == 0) {
			return true;
		}
		cur = cur->next;
	}
	return false;
}
void add(const char* key) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	strcpy(new_node->key, key);
	new_node->next = NULL;
	int index = hash(key);
	if (tb[index]==NULL) {
		tb[index] = new_node;
		printf("key :: %s -> %d value :: %d ¿Ï·á\n", key, index, value);
	}
	else {
		Node* cur = tb[index];
		while (cur != NULL) {
			if (strcmp(cur->key, key) == 0) {
				return;
			}
		}
		cur = cur->next;
	}
	new_node->next = tb[index];
	tb[index] = new_node;
}
int main() {
	//int tc;
	//scanf("%d", &tc);
	while (1) {
		//int n;
		//scanf("%d", &n);
		//vector<pair<int, string> > v;
		/*
		for (int i = 0; i < n; i++) {
			char A[15];
			
		}*/
		char key[MAX_KEY];
		scanf("%d", &key);
		int value;
		printf("key :: ");
		scanf("%s",&key);
		add(key);
		
	}
	return 0;
}