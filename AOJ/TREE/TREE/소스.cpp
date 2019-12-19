#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	string label; // 저장할 자료
	TreeNode* parent; // 부모노드를 가리키는 포인터
	vector<TreeNode*> children; // 자손 노드들을 가리키는 포인터
};

void printLabels(TreeNode* root) {
	cout << root->label << "\n";
	for (int i = 0; i < root->children.size(); i++) {
		printLabels(root->children[i]);
	}
}

int height(TreeNode* root) {
	int h = 0;
	for (int i = 0; i < root->children.size(); i++) {
		h = max(h, 1 + height(root->children[i]));
	}
	return h;
}