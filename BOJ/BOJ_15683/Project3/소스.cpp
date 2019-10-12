#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;
int dirs[8];
int types[6] = { 0,1,5,3,7,15 };

int map[8][8];
int copy_map[8][8];
int N, M;
struct node {
	int x;
	int y;
	int kind;
};
vector<node> camera;
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
int ans = INF;
void check(int x, int y, int bits) {
	for (int i = 0; i < 4; i++) {
		if (bits & (1 << i)) {
			int nx = x;
			int ny = y;
			while (1) {
				nx += dx[i];
				ny += dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (copy_map[nx][ny] == 6) break;
				copy_map[nx][ny] = 1;
			}
		}
	}
}
void go(int now) {
	if (ans == 0) return;
	if (now == camera.size()) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copy_map[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < camera.size(); i++) {
			if (types[camera[i].kind] == 15) check(camera[i].x, camera[i].y, types[camera[i].kind]);
			else{
				check(camera[i].x, camera[i].y, (types[camera[i].kind] << dirs[i]) % 15);
			}
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy_map[i][j] ==0) cnt++;
			}
		}
		if (ans > cnt) ans = cnt;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (camera[now].kind == 5 && i >= 1) return;
		if (camera[now].kind == 2 && i >= 2) return;
		dirs[now] = i;
		go(now + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6) {
				camera.push_back({ i,j,map[i][j] });
			}
		}
	}
	go(0);
	cout << ans << "\n";
	return 0;
}