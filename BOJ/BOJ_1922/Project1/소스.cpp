#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1000 + 1
using namespace std;

int group[MAXN];
int N, M;
struct node {
	int u;
	int v;
	int weight;

	bool operator < (const node& a) const {
		return weight < a.weight;
	}
};
vector<node> graph;
int ans = 0;
int find(int x) {
	if (x == group[x]) return x;
	return group[x] = find(group[x]);
}
void Union(node a) {
	a.u = find(a.u);
	a.v = find(a.v);
	if (a.u == a.v) return;
	group[a.v] = a.u;
	ans += a.weight;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		group[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph.push_back({ u,v,w });
	}
	sort(graph.begin(), graph.end());
	for (int i = 0; i < graph.size(); i++) {
		Union(graph[i]);
	}
	cout << ans << "\n";
	return 0;
}