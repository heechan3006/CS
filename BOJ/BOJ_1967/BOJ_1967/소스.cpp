#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 10001
using namespace std;
bool visited[MAXN];
int N;
//자식 노드, 가중치
vector<pair<int, int>> v[MAXN];
int dist = 0;
int node_num = 0;
void dfs(int idx, int w) {
	if (visited[idx]) return;
	visited[idx] = true;
	if (dist < w) {
		dist = w;
		node_num = idx;
	}
	for (int i = 0; i < v[idx].size(); i++) {
		dfs(v[idx][i].first, w + v[idx][i].second);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		int tmp_node1, tmp_node2, tmp_w;
		cin >> tmp_node1 >> tmp_node2 >> tmp_w;
		v[tmp_node1].push_back({ tmp_node2,tmp_w });
		v[tmp_node2].push_back({ tmp_node1,tmp_w });
	}
	dfs(1,0);
	memset(visited, false, sizeof(visited));
	dist = 0;
	dfs(node_num, 0);
	cout << dist << "\n";
	return 0;
}