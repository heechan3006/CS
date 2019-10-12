#include <iostream>
#include <vector>
#include <queue>

#define MAXN 32000 + 1
using namespace std;

int N, M;
vector<int> graph[MAXN];
int cnt[MAXN];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		cnt[v]++;
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0) {
			q.push(i);
		}
	}
	for (int i = 0; i < N; i++) {
		int v = q.front();
		q.pop();
		cout << v << " ";
		for (int j = 0; j < graph[v].size(); j++) {
			int next = graph[v][j];
			cnt[next]--;
			if (cnt[next] == 0) {
				q.push(next);
			}
		}
	}
	return 0;
}