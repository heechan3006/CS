#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <tuple>
#include <queue>
#include <algorithm>
#define MAXN 1000
using namespace std;

char map[MAXN][MAXN];
int N, M, P;
int S[10];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
queue<int> q1;
queue<tuple<int, int, int>> main_q[10];
int main() {
	scanf("%d%d%d", &N, &M, &P);
	
	
	vector<int> v(P + 1, 0);
	for (int i = 1; i <= P; i++) {
		scanf("%d", &S[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#' || map[i][j] == '.') continue;
			v[(int)(map[i][j] - '0')]++;
			main_q[(int)(map[i][j]-'0')].push({ i,j,0  });
			
		}
	}
	for (int i = 1; i <= P; i++) {
		q1.push(i);
	}
	while (!q1.empty()) {
		int player = q1.front();
		q1.pop();
		for (int i = 0; i < S[player]; i++) {
			int qs = main_q[player].size();
			if (qs == 0) break;
			while (qs--) {

				int curr_x, curr_y, curr_cnt;
				tie(curr_x, curr_y, curr_cnt) = main_q[player].front();
				main_q[player].pop();

				for (int k = 0; k < 4; k++) {
					int nx = curr_x + dx[k];
					int ny = curr_y + dy[k];
					int next_cnt = curr_cnt + 1;
					if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
					if (map[nx][ny] == '.') {
						map[nx][ny] = map[curr_x][curr_y];
						v[player]++;
						main_q[player].push({ nx, ny, next_cnt });
					}
				}
			}
		}
		if (main_q[player].size()) q1.push(player);
	}
	for (int i = 1; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	return 0;

}

