#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool adj[1001][1001];
bool visited[1001];
int N, M;
vector<int> aMatch;
vector<int> bMatch;
/*
bool dfs(int a) {
	if (visited[a]) return false;
	visited[a] = true;
	for (int b = 1; b <= M; b++) {
		if (adj[a][b]) {
			if (bMatch[b] == -1 || dfs(bMatch[b])) {
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
		}
	}
	return false;
}*/
bool dfs(int a) {
	for (int b = 1; b <= M; b++) {
		if (adj[a][b] && !visited[b] && bMatch[b] == -1) {
			visited[b] = true;
			bMatch[b] = a;
			return true;
		}
	}
	for (int b = 1; b <= M; b++) {
		if (adj[a][b] && !visited[b]) {
			visited[b] = true;
			if (dfs(bMatch[b])) {
				bMatch[b] = a;
				return true;
			}
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int tmp;
			cin >> tmp;
			adj[i][tmp] = 1;
		}
	}
	aMatch.resize(N + 1, -1);
	bMatch.resize(M + 1, -1);
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) ans++;
	}
	cout << ans << "\n";
}