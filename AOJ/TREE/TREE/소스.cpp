#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	string label; // ������ �ڷ�
	TreeNode* parent; // �θ��带 ����Ű�� ������
	vector<TreeNode*> children; // �ڼ� ������ ����Ű�� ������
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