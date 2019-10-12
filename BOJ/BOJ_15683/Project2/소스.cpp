#include <iostream>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;

int N, M;
// 90도 회전 수


int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int map[8][8];
int copy_map[8][8];
int ans;
int dirs[8] = { 0, };
struct node {
	int x;
	int y;
	int camera;
};
vector<node> v;
void check(int x, int y, int bit) {
	for (int i = 0; i < 4; i++) {
		if (bit & (1 << i)) {
			int nx = x;
			int ny = y;
			while (1) {
				nx += dx[i];
				ny += dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (copy_map[nx][ny] == 6) break;
				copy_map[nx][ny] = map[x][y];
				
			}
		}
	}
}
void go(int now) {
	if (now == v.size()) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copy_map[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].x;
			int y = v[i].y;
			int cur = v[i].camera;
			// 1방향 카메라
			if (cur == 1) {
				check(x, y, (1 << dirs[i]) % 15);
			}
			else if (cur == 2) {
				check(x, y, (5 << dirs[i]) % 15);
			}
			else if (cur == 3) {
				check(x, y, (3 << dirs[i]) % 15);
			}
			else if (cur == 4) {
				check(x, y, (7 << dirs[i]) % 15);
			}
			else if (cur == 5) {
				check(x, y, 15);
			}
		}
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy_map[i][j] == 0) sum++;
			}
		}
		if (ans > sum) ans = sum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		
		dirs[now] = i;
		go(now + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6) {
				v.push_back({ i,j,map[i][j] });
				
			}
		}
	}
	ans = INF;
	go(0);
	cout << ans << "\n";
	return 0;
}