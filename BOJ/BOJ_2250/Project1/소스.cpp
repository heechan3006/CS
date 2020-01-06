#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 10001
#define INF 987654321
struct Node {
	int left;
	int right;
	int value;
};

Node tree[MAXN];
int inorder[MAXN];
int low[MAXN];
int high[MAXN];
int N;
int root;
int x = 1;
void dfs(int now, int height) {
	if (tree[now].left != -1) {
		dfs(tree[now].left, height + 1);
	}
	low[height] = min(low[height], x);
	high[height] = max(high[height], x++);
	if (tree[now].right != -1) {
		dfs(tree[now].right, height + 1);
	}

}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) low[i] = INF;
	for (int i = 0; i < N; i++) {

		int vertex, left, right;
		scanf("%d%d%d", &vertex, &left, &right);
		if (left != -1) {
			inorder[left]++;
		}
		tree[vertex].left = left;
		if (right != -1) {
			inorder[right]++;
		}
		tree[vertex].right = right;
	}
	for (int i = 1; i <= N; i++) {
		if (inorder[i] == 0) {
			root = i;
			break;
		}
	}
	dfs(root,1);
	int ans = 0;
	int ans_level = 0;
	for (int i = 1; i <= N; i++) {
		if (high[i] - low[i] + 1 > ans) {
			ans = high[i] - low[i] + 1;
			ans_level = i;
		}
	}
	printf("%d %d", ans_level, ans);
	return 0;
	
	
}