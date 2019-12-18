#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAXN 50
#define INF 987654321
using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];

int N, M;
int total_cnt = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool used[10];
vector<pair<int, int> > virus;
struct node {
	int x;
	int y;
	int dist;
};

int ans = INF;
bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (copy_map[i][j] == 0) return false;
		}
	}
	return true;
}
int bfs() {

	memcpy(copy_map, map, sizeof(map));
	queue<node> q;
	
	for (int i = 0; i < virus.size(); i++) {
		if (used[i]) {
			q.push({ virus[i].first,virus[i].second,0 });
			
		}
		else {
			copy_map[virus[i].first][virus[i].second] = 0;
		}
	}
	int time = 0;
	while (!q.empty()) {
		
		int x = q.front().x;
		int y = q.front().y;
		int cur_dist = q.front().dist;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (copy_map[nx][ny]) continue;
				
			copy_map[nx][ny] = 2;
			q.push({ nx,ny, cur_dist+1});
			time = max(time, cur_dist+1);
			
		}
		
	}
	if (check()) return time ;
	return -1;
	

}
void dfs(int now, int cnt) {
	if (ans == 0) return;
	if (cnt == M) {
		int sum = bfs();
		if (sum != -1 && ans > sum) ans = sum;
		return;
	}
	for (int i = now; i < virus.size(); i++) {
		used[i] = true;
		dfs(i + 1, cnt + 1);
		used[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (!map[i][j]) total_cnt++;
			else if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
	dfs(0, 0);
	if (ans == INF) cout << "-1\n";
	else {
		cout << ans << "\n";
	}
	return 0;
}