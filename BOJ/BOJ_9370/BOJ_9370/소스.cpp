#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 987654321
#define MAXV 2000 + 1

using namespace std;

vector<pair<int, int>> graph[MAXV];
vector<pair<int, int>> trace[MAXV];
int N, M, T;
int S, G, H;
bool flag;
vector<int> dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	vector<int> dist(N + 1, INF);
	
	pq.push({ 0,start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].first;
			int next_cost = graph[here][i].second + cost;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ -next_cost,next });
			}
		
		}
	}
	return dist;
}
void check(int last,int cnt) {
	if (cnt == 2) {
		flag = true;
		return;
	}
	if (last == G || last == H) {
		cnt += 1;
	}
	for (int i = 0; i < trace[last].size(); i++) {
		check(trace[last][i].first,cnt);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> N >> M >> T;
		cin >> S >> G >> H;
		for (int i = 0; i < MAXV; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < M; i++) {
			int from, to, w;
			cin >> from >> to >> w;
			graph[from].push_back({ to,w });
			graph[to].push_back({ from,w });
		}
		vector<int> dist1 = dijkstra(S);
		vector<int> e;
		for (int i = 0; i < T; i++) {
			int tmp;
			cin >> tmp;
			e.push_back(tmp);
		}
		sort(e.begin(), e.end());
		int start;
		if (dist1[G] < dist1[H]) {
			start = H;
		}
		else {
			start = G;
		}
		vector<int> dist2 = dijkstra(start);
		for (int i = 0; i < e.size(); i++) {
			int here = e[i];
			if (dist1[here] == (dist1[start] + dist2[here])) {
				cout << here << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}

