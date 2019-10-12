#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int map[40][40];
int N, M, H;
int ans;

vector<pair<int, int>> v;
bool go() {
	for (int j = 0; j < N; j++) {
		int i = 0;
		int idx = j;
		while (i <= H){
			if (map[i][idx] == 1) {
				idx++;
			}
			else if (map[i][idx] == 2) {
				idx--;
			}
			
			i++;
		}
		if (idx != j) return false;
	}
	return true;
}
void dfs(int now,int cnt) {
	if (ans <= cnt) return;
	if (go()) {
		ans = min(ans, cnt);
		return;
	}
	if (cnt >= 3) {
		return;
	}
	
	for (int i =now; i < v.size(); i++){
		if (map[v[i].first][v[i].second] == 0 && map[v[i].first][v[i].second+1]==0){

			map[v[i].first][v[i].second] = 1;
			map[v[i].first][v[i].second+1] = 2;
			dfs(i,cnt+1);
			map[v[i].first][v[i].second] = map[v[i].first][v[i].second+1] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		map[a][b] = 1;
		map[a][b + 1] = 2;
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] == 0 && map[i][j + 1] == 0) {
				v.push_back({ i,j });
			}
		}
	}
	
	ans = 4;
	dfs(0,0);
	if (ans == 4) {
		cout << -1 << "\n";
	}
	else{
		cout << ans << "\n";
	}
	return 0;
}