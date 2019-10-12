#include <iostream>
#include <queue>
#include <vector>
#define MAXN 100001
#define INF 98765432
using namespace std;

int N, K, M;
vector<int> v[MAXN+2000];
int dist[MAXN+2000];
int bfs() {
	queue<int> q;
	q.push(1);
	dist[1] = 1;
	
	while (!q.empty()) {
		
		int cur = q.front();
		q.pop();
		if (cur == N) return dist[cur];
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (dist[next] == 0){
				q.push(next);
				if (next > MAXN) {
					dist[next] = dist[cur];
				}
				else dist[next] = dist[cur] + 1;
				
			}
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> M;
	
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < K; j++) {
			int tmp;
			cin >> tmp;
			v[MAXN + i].push_back(tmp);
			v[tmp].push_back(MAXN + i);
		}
		
	}
	int ans = bfs();
	
	cout << ans << "\n";
}
