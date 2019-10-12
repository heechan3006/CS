#include <iostream>
#include <vector>
#define MAXN 400+4
using namespace std;

int N, K, S;
bool visited[MAXN][MAXN];
vector<int> graph[MAXN];
void dfs(int now, int next) {
	visited[now][next] = true;
	for (int i = 0; i < graph[next].size(); i++) {
		int next_tmp = graph[next][i];
		if (!visited[now][next_tmp]) {
			dfs(now, next_tmp);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	for (int i = 1; i <= N; i++) {
		dfs(i, i);
	}
	cin >> S;
	while (S--){
		int u, v;
		cin >> u >> v;
		if (visited[u][v]==true) cout << "-1\n";
		else if (visited[v][u]==true) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
