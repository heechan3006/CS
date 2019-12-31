#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Node {
public:
	Node* left;
	Node* right;
	int height;
	Node() :left(NULL), right(NULL),height(-1) {}
};


void insert(Node* tmp, int input) {
	
	while (tmp != NULL) {
		
		if (tmp->height > input) {
			if (tmp->left != NULL) {
				tmp = tmp->left;
			}
			else {
				tmp->left = new Node;
				tmp->left->height = input;
				break;
			}
		}
		else {
			if (tmp->right != NULL) {
				tmp = tmp->right;
			}
			else {
				tmp->right = new Node;
				tmp->right->height = input;
				break;
			}
		}
	}	
}

void printsearch(Node* node) {
	
	if (node->left != NULL)	printsearch(node->left);
	if (node->right != NULL) printsearch(node->right);
	printf("%d\n", node->height);
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int input;
	int i = 0;
	int root_height;
	//freopen("input.txt", "r", stdin);
	
	scanf("%d",&root_height);
	Node* root = new Node;
	root->height = root_height;
	
	while (scanf("%d",&input)!=EOF) {
		
		insert(root, input);
	}
	printsearch(root);
	return 0;
}
