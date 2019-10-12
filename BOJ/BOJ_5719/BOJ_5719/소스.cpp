#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAXN 500
#define INF 98765432
using namespace std;

vector<pair<int, int>> v[MAXN];
bool visited[MAXN][MAXN];

vector<pair<int, int>> trace[MAXN];
int N, M;
int start, last;
int min_len = 98765432;
int ans = 98765432;


vector<int> dijkstra(int start, int vertex) {
	vector<int> distance(vertex, INF);
	distance[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur_vertex = pq.top().second;
		pq.pop();
		if (distance[cur_vertex] < cost) continue;
		for (int i = 0; i < v[cur_vertex].size(); i++) {
			int next = v[cur_vertex][i].first;
			int next_dist = v[cur_vertex][i].second + cost;
			if (v[cur_vertex][i].second == -1) continue;
			if (distance[next] > next_dist) {
				distance[next] = next_dist;
				pq.push({ -next_dist,next });

				trace[next].clear();
				trace[next].push_back({ cur_vertex,next_dist });
			}
			else if (distance[next] == next_dist) {
				trace[next].push_back({ cur_vertex,next_dist });
			}
		}
	}
	return distance;
}
void bfs(int destination) {
	queue<int> q;
	q.push(destination);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < trace[cur].size(); i++) {
			int next = trace[cur][i].first;
			if (visited[cur][next]) continue;
			for (int i = 0; i < v[next].size(); i++) {
				if (v[next][i].first == cur) {
					v[next][i].second = -1;
				}
			}
			q.push(next);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	while (1){
		memset(visited, false, sizeof(visited));
		memset(trace, 0, sizeof(trace));
		for (int i = 0; i < MAXN; i++) {
			v[i].clear();
		}
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		cin >> start >> last;
	
		for (int i = 0; i < M; i++) {
			int tmp_x, tmp_y, tmp_w;
			cin >> tmp_x >> tmp_y >> tmp_w;
			v[tmp_x].push_back({ tmp_y,tmp_w });
		}
		dijkstra(start, N);
		bfs(last);
		vector<int> ans = dijkstra(start, N);
		if (ans[last] == INF) cout << -1 << "\n";
		else cout << ans[last] << "\n";
	
	}
	return 0;
}