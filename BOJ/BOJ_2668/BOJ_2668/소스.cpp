#include <iostream>

using namespace std;

int map[101];
bool visited[101];
bool cycle[101];
int N;
int ans;
bool dfs(int now,int node) {
	
	if (visited[node]) return false;
	visited[node] = true;
	
	if (now == node || dfs(now,map[node])) {
		ans++;
		cycle[node] = true;
		return true;
	}
	visited[node] = false;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> map[i];
	}
	ans = 0;
	for (int i = 1; i <= N; i++) {
		dfs(i,map[i]);
	}
	cout << ans << "\n";
	for (int i = 1; i <= N; i++) {
		if (cycle[i]) cout << i << "\n";
	}
	return 0;
}