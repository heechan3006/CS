#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#define MAX_TABLE 100000

struct Node {
	int key;
	Node* next;
};
Node* tb[MAX_TABLE];
int my_hash(const int key) {

	return abs(key) % MAX_TABLE;
}
void add_hash(const int key) {
	Node* new_node = new Node;
	new_node->key = key;
	new_node->next = NULL;
	int index = my_hash(key);
	if (tb[index] == NULL) {
		tb[index] = new_node;
	}
	else {
		Node* cur = tb[index];
		while (cur != NULL) {
			// 중복o
			if (cur->key == key) {
				return;
			}
			cur = cur->next;
		}
		// 중복x -> 앞에 추가
		new_node->next = tb[index];
		tb[index] = new_node;
	}
}
bool find_hash(const int key) {
	int index = my_hash(key);
	Node* cur = tb[index];
	while (cur != NULL) {
		if (cur->key == key) {
			return true;
		}
		cur = cur->next;
	}
	return false;
}
int N, M;
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		add_hash(tmp);
	}
	scanf("%d", &M);
	while (M--) {
		int tmp;
		scanf("%d", &tmp);
		printf("%d\n", find_hash(tmp));
	}

}