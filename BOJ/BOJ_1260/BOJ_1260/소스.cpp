#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

int N, M, start_v;

queue<int> q;
void dfs(int now, vector<vector<int>> v, bool visited[]) {
	visited[now] = true;
	printf("%d ", now);
	for (auto it = v[now].begin(); it != v[now].end(); it++) {
		int next = (*it);
		if (visited[next]) continue;
		dfs(next, v, visited);
	}
}
void bfs(int start_v, vector<vector<int>> v, bool visited[]) {
	visited[start_v] = true;
	q.push(start_v);
	printf("%d ", start_v);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (auto it = v[curr].begin(); it != v[curr].end(); it++) {
			int next = (*it);
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				printf("%d ", next);
			}
		}
	}
}
int main() {
	cin >> N >> M >> start_v;
	bool visited[1001];
	memset(visited, false, sizeof(visited));
	vector<vector<int>> v(N+1);
	int v_1, v_2;
	for (int i = 0; i < M; i++) {
		cin >> v_1 >> v_2;
		v[v_1].push_back(v_2);
		v[v_2].push_back(v_1);
	}
	for (int i = 0; i <= N; i++){
		sort(v[i].begin(), v[i].end());
	}
	dfs(start_v, v, visited);
	printf("\n");
	memset(visited, false, sizeof(visited));
	bfs(start_v, v, visited);
	return 0;
}