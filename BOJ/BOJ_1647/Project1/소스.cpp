#include <iostream>
#include <algorithm>
#include <queue>

#define MAXN 100000 + 1

using namespace std;

int N, M;
struct node {
	int weight;
	int u;
	int v;
	bool operator < (const node& a) const {
		return weight < a.weight;
	}
};

int group[MAXN];
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
	N--;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	priority_queue<node> pq;
	for (int i = 0; i < M; i++) {
		int u, v, weight;
		cin >> u >> v >> weight;
		pq.push({ -weight,u,v });
	}
	for (int i = 1; i <= N; i++) {
		group[i] = i;
	}
	while (!pq.empty()) {
		int cost = -pq.top().weight;
		int u = pq.top().u;
		int v = pq.top().v;
		pq.pop();
		Union(u, v,cost);
		if (N == 2) break;
	}
	
	cout << ans << "\n";
	return 0;
}
