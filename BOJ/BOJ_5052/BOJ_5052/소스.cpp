#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;
#define HASHMAX 10000
#define MAX_KEY 10
#define a 1

struct Node {
	char key[MAX_KEY];
	Node* next;
};
Node* tb[HASHMAX];
int my_hash(const char* str) {
	int hash = 401;
	while (*str != '\0') {
		hash = ((hash << 4) + (int)(*str)) % HASHMAX;
		str++;
	}
	return hash % HASHMAX;
}
bool find(const char* key) {
	int index = my_hash(key);
	Node* cur = tb[index];
	while (cur != NULL) {
		if (strcmp(cur->key, key) == 0) {
			return true;
		}
		cur = cur->next;
	}
	return false;
}
void init() {
	for (int i = 0; i < HASHMAX; i++) {
		Node* cur = tb[i];
		Node* tmp;
		while (cur != NULL) {
			tmp = cur;
			cur = cur->next;
			free(tmp);
		}
		tb[i] = NULL;
	}
}
void add(const char* key) {
	
	
	
	int index = my_hash(key);
	Node* new_node = new Node;
	new_node->next = NULL;

	strcpy(new_node->key, key);
	if (tb[index] == NULL) {
		tb[index] = new_node;
		return;
	}
	else {
		Node* cur = tb[index];
		while (cur != NULL) {
			if (strcmp(cur->key, key) == 0) {
				return;
			}
			cur = cur->next;
		}
		
		new_node->next = tb[index];
		tb[index] = new_node;
	}
	
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		memset(tb, 0, sizeof(tb));
		scanf("%d", &n);
		vector<pair<int, string> > v;
		
		for (int i = 0; i < n; i++) {
			char A[15];
			scanf("%s", &A);
			int len = 0;
			while (A[len++]);
			v.push_back({ len,A });
		}
		sort(v.begin(), v.end());
		bool flag = false;
		for (int i = 0; i < n && !flag; i++) {
			char A[15];
			for (int j = 0; v[i].second[j]; j++) {
				A[j] = v[i].second[j];
				A[j + 1] = 0;
				if (find(A)) {
					flag = true;
					break;
				}
			}
			if (flag) break;
			add(A);
		}
		printf("%s\n", flag == true ? "NO" : "YES");

	}
	return 0;
}