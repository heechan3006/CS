#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 101
using namespace std;

char map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N, M;
int K;
int num[MAXN];
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int max_v = 0;
vector<pair<int, int> > cluster;
bool flag;
void check(int x, int y) {
	if (x == N - 1) flag = true;
	cluster.push_back({ x,y });
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (map[nx][ny] =='x' && !visited[nx][ny]) {
			check(nx, ny);
		}
	}
}
void drop() {
	bool possible = true;
	while (possible) {
		for (int i = 0; i < cluster.size(); i++) {
			map[cluster[i].first][cluster[i].second] = '.';
		}
		for (int i = 0; i < cluster.size(); i++) {
			int tmp_x = cluster[i].first;
			tmp_x++;
			if (map[tmp_x][cluster[i].second] == 'x' || tmp_x == N) {
				possible = false;
				break;
			}
		}
		if (possible) {
			for (int i = 0; i < cluster.size(); i++) {
				cluster[i].first += 1;
				map[cluster[i].first][cluster[i].second] = 'x';
			}
		}
		else {
			for (int i = 0; i < cluster.size(); i++) {
				map[cluster[i].first][cluster[i].second] = 'x';
			}
		}
	}

}
void go(int x,int mode) {
	if (mode == 0) {
		for (int j = 0; j < M; j++) {
			if (map[x][j] == 'x') {
				memset(visited, false, sizeof(visited));
				map[x][j] = '.';
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
					if (map[nx][ny] == 'x' && !visited[nx][ny]) {
						cluster.clear();
						flag = false;
						check(nx, ny);
						if (!flag) {

							drop();
						}
					}
				}
				break;
			}
		}
	}
	else {
		for (int j = M-1; j >= 0; j--) {
			if (map[x][j] == 'x') {
				memset(visited, false, sizeof(visited));
				map[x][j] = '.';
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
					if (map[nx][ny] == 'x' && !visited[nx][ny]) {
						cluster.clear();
						flag = false;
						check(nx, ny);
						if (!flag) {

							drop();
						}
					}
				}
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char tmp;
			scanf(" %1c", &map[i][j]);
		}
	}
	
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int tmp;
		scanf("%d", &tmp);
		num[i] = N - tmp;
	}
	for (int i = 0; i < K; i++) {
		go(num[i],i%2);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}