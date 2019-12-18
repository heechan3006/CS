#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 1e14
#define MAXN 200000
using namespace std;
long long dist[MAXN];
int N, M; 
struct node {
	int idx;
	long long weights;
	bool operator < (const node& a) const {
		if (weights < a.weights) return true;
		return false;
	}
};
vector < vector<node> > adj;
priority_queue<node> pq;

long long path[MAXN];
void dijkstra() {
	dist[0] = 0;
	pq.push({ 0,0 });
	while (!pq.empty()) {
		long long cur_cost = pq.top().weights;
		int cur = pq.top().idx;
		
		pq.pop();
		if (dist[cur] < cur_cost) continue;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].idx;
			long long next_cost = adj[cur][i].weights;
			
			if (dist[next] > next_cost + dist[cur]){
				dist[next] = next_cost + dist[cur];
				pq.push({ next,next_cost });
				path[next] = next_cost;
			}
			
			else if (dist[next] == next_cost + dist[cur]) {
				if (path[next] > next_cost) path[next] = next_cost;
			}
		}
	}
}
int main() {
	setbuf(stdout, 0);
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {
		
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++) {
			path[i] = INF;
		}
		adj.resize(N);
		for (int i = 0; i < N; i++) {
			adj[i].clear();
		}
		for (int i = 0; i < M; i++) {
			int u, v;
			long long w;
			scanf("%d%d%llu", &u, &v, &w);
			
			adj[u-1].push_back({ v-1,w });
			adj[v-1].push_back({ u-1,w });
		}
		
		for (int i = 0; i < N; i++) {
			sort(adj[i].begin(), adj[i].end());
		}
		for (int i = 0; i < N; i++) {
			dist[i] = INF;
		}
		dijkstra();
		long long ans = 0;
		for (int i = 1; i < N; i++) {
			ans += path[i];
		}
		
		printf("#%d %d\n", test_case, ans);
	}
	
	return 0;
}

