#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 1001
using namespace std;

int N, M;
vector<vector<int>> graph;

int Match[MAXN];
bool visited[MAXN];
bool dfs(int a) {
	if (visited[a]) return false;
	visited[a] = true;
	for (int b = 0; b < graph[a].size(); b++){
		int next = graph[a][b];
		if (!Match[next] || dfs(Match[next])) {
			Match[next] = a;
			return true;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	graph.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int tmp;
			cin >> tmp;
			graph[i].push_back(tmp);
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++){
			memset(visited, false, sizeof(visited));
			if (dfs(i)) ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
