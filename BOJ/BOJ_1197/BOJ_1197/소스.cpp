#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 10000 + 1
using namespace std;

int N, M;
int group[MAXN];
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
void Union(int a, int b, int w) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	group[b] = a;
	ans += w;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		group[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int u, v, weight;
		cin >> u >> v >> weight;
		graph.push_back({ u,v,weight });
	}
	sort(graph.begin(), graph.end());
	for (int i = 0; i < graph.size(); i++) {
		Union(graph[i].u, graph[i].v, graph[i].weight);
	}
	cout << ans << "\n";
	return 0;
}