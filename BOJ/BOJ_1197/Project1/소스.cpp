#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 10000 + 1

using namespace std;

int group[MAXN];
int N, M;
int ans = 0;

struct node {
	int u;
	int v;
	int weight;
	bool operator < (node& A) const {
		return weight < A.weight;
	}
};
int find(int a) {
	if (a == group[a]) return a;
	return group[a] = find(group[a]);
}
void Union(node A) {
	int a = find(A.u);
	int b = find(A.v);
	if (a == b) return;
	group[b] = a;
	ans += A.weight;
}
vector<node> graph;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph.push_back({ u,v,w });
	}
	for (int i = 1; i <= N; i++) {
		group[i] = i;
	}
	sort(graph.begin(), graph.end());
	for (int i = 0; i < graph.size(); i++) {
		Union(graph[i]);
	}
	cout << ans << "\n";
	return 0;
}
