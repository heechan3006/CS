#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define MAXN 1000 + 1

using namespace std;

int N, M;
struct node {
	int v;
	int weight;
	bool operator < (const node& a) const {
		return weight < a.weight;
	}
};
priority_queue<node> pq;
vector<node> graph[MAXN];
bool visited[MAXN];
int ans = 0;
void prim(int start) {
	visited[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {
		if (!visited[graph[start][i].v]) {
			pq.push({ graph[start][i].v, -graph[start][i].weight });
		}
	}
	while (!pq.empty()) {
		int w = -pq.top().weight;
		int cur = pq.top().v;
		pq.pop();
		if (!visited[cur]) {
			ans += w;
			prim(cur);
			return;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}
	prim(1);
	cout << ans << "\n";
	return 0;
}