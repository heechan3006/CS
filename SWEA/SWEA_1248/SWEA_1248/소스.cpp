#include <iostream>
#include <memory.h>
using namespace std;

struct Node {
	int parent = 0;
	int left = 0;
	int right = 0;
};
bool check[10001];
int V, E,v1,v2;
int count_node(Node tree[], int current) {
	int ans = 1;
	if (tree[current].left != 0) ans += count_node(tree, tree[current].left);
	if (tree[current].right != 0) ans += count_node(tree, tree[current].right);
	return ans;
}
int main() {
	//freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++){
		Node tree[10001];
		memset(check, false, sizeof(check));
	
		scanf("%d %d %d %d", &V, &E, &v1, &v2);
		int tmp_v, tmp_e;
		for (int i = 0; i < E; i++) {
			scanf("%d %d", &tmp_v, &tmp_e);
			if (tree[tmp_v].left == 0) {
				tree[tmp_v].left = tmp_e;
			}
			else {
				tree[tmp_v].right = tmp_e;
			}
			tree[tmp_e].parent = tmp_v;
		}
		int cur = tree[v1].parent;
		while (true) {
			check[cur] = true;
			if (cur == 1) break;
			cur = tree[cur].parent;
		}
		cur = tree[v2].parent;
		while (true) {
			if (check[cur]) {
				printf("#%d %d %d\n", test_case,cur, count_node(tree, cur));
				break;
			}
			cur = tree[cur].parent;
		}
	}
}
