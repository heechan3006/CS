#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100000 + 1
using namespace std;

int N, M;
struct node {
	int u;
	int v;
	int weight;
};
vector<node> graph;
int group[MAXN];
int ans = 0;
bool compare(node a, node b) {
	if (a.weight < b.weight) return true;
	return false;
}
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
	N--;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, weight;
		cin >> u >> v >> weight;
		graph.push_back({ u,v,weight });
	}
	for (int i = 1; i <= N; i++) {
		group[i] = i;
	}
	sort(graph.begin(), graph.end(), compare);
	for (int i = 0; i < graph.size(); i++) {
		if (N == 2) break;
		Union(graph[i].u, graph[i].v,graph[i].weight);
	}
	cout << ans << "\n";
	return 0;
}
