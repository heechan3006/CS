#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 98765432
using namespace std;
int visited[13];
int map[13][20];
int D, W, K;
int ans;
int check() {
	
	for (int j = 0; j < W; j++) {
		int cnt = 1;
		int res = 0;
		if (visited[0] == 0) res = map[0][j];
		else res = visited[0];
		for (int i = 1; i < D; i++) {
			if (visited[i] == 0 && res != map[i][j] || visited[i] != 0 && res != visited[i]) {
				if (visited[i] == 0) {
					res = map[i][j];
				}
				else {
					res = visited[i];
				}
				
				cnt = 1;
				continue;
			}
			cnt++;
			if (cnt >= K) break;
		}
		if (cnt < K) return false;
	}
	return true;
}
void dfs(int now,int cnt) {
	if (cnt > K || cnt >= ans) return;
	if (now == D + 1) {
		if (check()&&(ans>cnt)) {
			ans = cnt;
		}
		return;
	}
	
	visited[now] = 0;
	dfs(now + 1, cnt);
	visited[now] = 1;
	dfs(now + 1,cnt+1);
	visited[now] = 2;
	dfs(now + 1,cnt+1);
	visited[now] = 0;
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int test_case=1; test_case<=t; test_case++){
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
				map[i][j]++;
			}
		}
		memset(visited, false, sizeof(visited));
		ans = INF;
		dfs(0,0);
		cout << "#"<< test_case<<" "<<ans << "\n";
	}
	return 0;
}