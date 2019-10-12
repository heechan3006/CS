#include <iostream>
#include <algorithm>
#define MAXN 10001
#define INF 987654321
using namespace std;

struct info {
	int left;
	int right;
};
info tree[MAXN];
int low[MAXN];
int high[MAXN];
int node[MAXN];
int N;
int root;
int idx;

void dfs(int num, int cnt) {
	if (tree[num].left > 0) {
		dfs(tree[num].left, cnt + 1);
	}
	low[cnt] = min(low[cnt], idx);
	high[cnt] = max(high[cnt], idx++);
	if (tree[num].right > 0) {
		dfs(tree[num].right, cnt + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < MAXN; i++) {
		low[i] = INF;
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		int cur, left, right;
		cin >> cur >> left >> right;
		node[cur]++;
		if (left != -1) {
			node[left]++;
		}
		tree[cur].left = left;
		if (right != -1) {
			node[right]++;
		}
		tree[cur].right = right;
	}
	for (int i = 1; i <= N; i++) {
		if (node[i] == 1) {
			root = i;
			break;
		}
	}
	idx = 1;
	dfs(root, 1);
	int result = high[1] - low[1] + 1;
	int level = 1;
	
	for (int i = 2; i <= N; i++) {
		int tmp = high[i] - low[i] + 1;
		if (tmp > result) {
			result = tmp;
			level = i;
		}
	}
	cout << level << " " << result << "\n";
	return 0;
}