#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	vector<TreeNode*> children;
	int num;
};
int root_num;
int N;
int del_node;
TreeNode* T[50];
void delete_node(TreeNode* t) {
	t->
	for (int i = 0; i < t->children.size(); i++) {
		
	}
}
int go(TreeNode* t) {

	if (t->children.empty()) return 1;
	int cnt = 0;
	for (int i = 0; i < t->children.size(); i++) {
		cnt += go(t->children[i]);
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	
	for (int i = 0; i < 50; i++) {
		T[i] = new TreeNode();
	}
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == -1) {
			root_num = i;
			T[i]->num = i;
		}
		else {
			T[tmp]->children.push_back(T[i]);
			T[i]->num = i;
		}
	}
	cin >> del_node;
	delete T[del_node];
	cout << go(T[root_num]) << "\n";
	return 0;
}