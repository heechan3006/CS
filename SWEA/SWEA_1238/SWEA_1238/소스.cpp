#include <iostream>
#include <map>
#include <queue>
#include <memory.h>

using namespace std;

int N;
int s_node;
bool visited[101];
int dist[101];

pair<map<int, int>::iterator, map<int, int>::iterator> iter_pair;
map<int, int>::iterator iter;
int main() {
	freopen("real_input.txt", "r", stdin);
	for (int t = 1; t <= 10; t++){
		fill(&dist[0], &dist[101], -1);
		memset(visited, false, sizeof(visited));
		scanf("%d %d", &N, &s_node);
		multimap<int, int> m;
		for (int i = 0; i < N/2; i++) {
			int tmp_from, tmp_to;
			scanf("%d %d", &tmp_from, &tmp_to);
			m.insert({ tmp_from, tmp_to });
		}
		queue<int> q;
		
		q.push(s_node);
		visited[s_node] = true;
		dist[s_node] = 0;
		int max_dist = 0;
		int ans = 0;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			iter_pair = m.equal_range(node);
		
			for (iter = iter_pair.first; iter != iter_pair.second; ++iter) {
				int to = (*iter).second;
				if (!visited[to]) {
					visited[to] = true;
					q.push(to);
					dist[to] = dist[node] + 1;
				}
			
			}
		}
	
		for (int i = 0; i < 100; i++) {
			if (dist[i] == -1) continue;
			if (max_dist <= dist[i]) {
				max_dist = dist[i];
				ans = i;
			}
		}
		//printf("%d\n", ans);
		printf("#%d %d\n", t,ans);
	}
	return 0;
	
}