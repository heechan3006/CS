#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;

struct Node {
	char left;
	char right;
};
int N;

map<char,Node> node;
string s = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void dfs_1(char now) {
	if (now == '.') return;
	cout << now;
	dfs_1(node[now].left);
	dfs_1(node[now].right);
}
void dfs_2(char now) {
	if (now == '.') return;
	dfs_2(node[now].left);
	cout << now;
	dfs_2(node[now].right);
}
void dfs_3(char now) {
	if (now == '.') return;
	dfs_3(node[now].left);
	dfs_3(node[now].right);
	cout << now;
}
int main() {
	scanf("%d\n", &N);
	char tmp_parent, tmp_left, tmp_right;
	
	for (int i = 1; i <= N; i++) {
		cin >> tmp_parent >> tmp_left >>tmp_right;
		node[tmp_parent].left = tmp_left;
		node[tmp_parent].right = tmp_right;
		
		
	}
	dfs_1('A');
	printf("\n");
	dfs_2('A');
	printf("\n");
	dfs_3('A');
	return 0;
}