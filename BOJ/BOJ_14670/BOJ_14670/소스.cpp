#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
const int MAX_TABLE = 100;

struct Node {
	int key;
	int value;
	Node* next;
};
Node* tb[MAX_TABLE];
int my_hash(int key) {
	return key % MAX_TABLE;
}
void add_hash(const int key, int value) {
	Node* new_node = new Node;
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	int index = my_hash(key);
	if (tb[index] == NULL) {
		tb[index] = new_node;
	}
	else {
		new_node->next = tb[index];
		tb[index] = new_node;
	}
}
int find_hash(const int key) {
	int index = my_hash(key);
	Node* cur = tb[index];
	while (cur != NULL) {
		if (cur->key == key) {
			return cur->value;
		}
		cur = cur->next;
	}
	return -1;
}
int main() {
	int N, M;
	scanf("%d", &N);
	while (N--) {
		int key, value;
		scanf("%d%d", &key, &value);
		add_hash(key, value);
	}
	scanf("%d", &M);
	while (M--) {
		int R;
		scanf("%d", &R);
		bool flag = false;
		int ans[MAX_TABLE];
		int idx = 0;
		while (R--) {
			int key;
			scanf("%d", &key);
			int value = find_hash(key);
			if (value == -1) {
				flag = true;
			}
			else {
				ans[idx++] = value;
			}
		}
		if (flag) printf("YOU DIED");
		else {
			for (int i = 0; i < idx; i++) {
				printf("%d ", ans[i]);
			}
		}

		printf("\n");
	}
	return 0;
}

