#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
const int MAXN = 20;
const int INF = 987654321;
struct node {
	int u;
	int v;
	int w;
	bool operator < (const node& a) const {
		return a.w < w;
	}
};


priority_queue<node> q;
int N;
int dist[MAXN][MAXN];
bool used[MAXN][MAXN];
bool visited[MAXN];
int ans = 0;

void go() {
	while (!q.empty()) {
		int u = q.top().u;
		int v = q.top().v;
		int weights = q.top().w;
		q.pop();
		if (!visited[u] || !visited[v]) {
			dist[u][v] = dist[v][u] = weights;
			visited[u] = visited[v] = true;
			ans+=weights;
		}
		else {
			bool flag = false;
			for (int k = 0; k < N; k++) {
				if (dist[u][k] != INF && dist[k][v] != INF && dist[u][k] + dist[k][v] == weights) {
					flag = true;
					break;
				}
				else if (dist[u][k] != INF && dist[k][v] != INF && dist[u][k] + dist[k][v] < weights) {
					cout << "-1\n";
					return;
				}
			}
			if (!flag) ans += weights;
			dist[u][v] = dist[v][u] = weights;
		}
	}
	cout << ans << "\n";
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = INF;
			int tmp;
			cin >> tmp;
			if (i == j) continue;
			if (!used[i][j]  && !used[j][i]) {
				used[i][j] = used[j][i] = true;
				q.push({ i,j,tmp });
			}
		}
	}
	go();
	return 0;
}

