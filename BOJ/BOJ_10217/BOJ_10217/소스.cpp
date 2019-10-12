#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 987654321
#define MAXV 100 + 3
#define MAXM 10000 + 3
using namespace std;

struct info {
	int to;
	int c;
	int d;
	
};
vector<info> graph[MAXV];
// 비용, 거리
int dist[MAXV][MAXM];
int N, M, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> N >> M >> K;
		for (int i = 0; i < MAXV; i++) {
			graph[i].clear();
			for (int j = 0; j < MAXM; j++) {
				dist[i][j] = INF;
			}
		}
		for (int i = 0; i < K; i++) {
			int from, to, c, d;
			cin >> from >> to >> c >> d;
			graph[from].push_back({ to,c,d });
		}
		bool flag = false;
		// d, c, to
		priority_queue<pair<int,pair<int,int>>> pq;
		pq.push({ 0,{0,1} });
		dist[1][0] = 0;
		while (!pq.empty()) {
			int cur_d = -pq.top().first;
			int cur_c = pq.top().second.first;
			int cur = pq.top().second.second;
			if (cur == N) {
				cout << cur_d << "\n";
				flag = true;
				break;
			}
			pq.pop();
			for (int i = 0; i < graph[cur].size(); i++) {
				int next = graph[cur][i].to;
				int next_c = graph[cur][i].c + cur_c;
				int next_d = graph[cur][i].d + cur_d;
				if (dist[next][next_c] > next_d && next_c <= M) {
					for (int k = next_c+1; k<=M; k++){
						if (dist[next][k] <= next_d) break;
						dist[next][k] = next_d;
					}
					dist[next][next_c] = next_d;
					pq.push({ -next_d,{next_c,next} });
				}
			}
		}
		if (!flag) cout << "Poor KCM\n";
	}
	return 0;
}