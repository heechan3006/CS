#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 50;
class Node {
public:
	Node* parent;
	Node* child[MAXN];
	int n_size;
	bool deleted;
	int number;
	
	Node() :n_size(0), parent(NULL), deleted(false), number(0) {}
	
	bool isLeaf() {
		if (n_size <= 0 && !deleted) return true;
		return false;
	}
};
Node tree[MAXN];
int N;

void delete_node(Node* node) {
	node->deleted = true;
	node->parent->n_size--;
	int n_size = node->n_size;
	for (int i = 0; i < n_size; i++) {
		delete_node(node->child[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int root = 0;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == -1) {
			root = i;
		}
		else {
			tree[i].parent = &tree[tmp];
			tree[tmp].child[tree[tmp].n_size++] = &tree[i];
		}
		tree[i].number = i;
	}
	int del_node;
	cin >> del_node;
	if (del_node == root) {
		cout << "0\n";
		return 0;
	}
	delete_node(&tree[del_node]);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (tree[i].isLeaf()) cnt++;
	}
	cout << cnt << "\n";
	return 0;
}