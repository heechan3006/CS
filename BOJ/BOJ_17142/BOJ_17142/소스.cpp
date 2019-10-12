#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 50

using namespace std;
int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];
int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> v;
vector<int> temp;
int ans = 987654321;
void go(int cnt) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i]) {
			q.push(v[i]);
			copy_map[v[i].first][v[i].second] = 3;
		}
	}
	int time = 0;
	bool flag = false;
	while (!q.empty()) {
		int q_size = q.size();
		if (!cnt) {
			flag = true;
			if (ans > time) ans = time;
			break;
		}
		time++;
		for (int i = 0; i < q_size; i++) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (copy_map[nx][ny] == 0 || copy_map[nx][ny] == 2) {
					if (copy_map[nx][ny] == 0) cnt--;
					
					copy_map[nx][ny] = 3;
					q.push({ nx,ny });
				}
			}
			
		}
	}
	return;
}
int main() {
	int cnt = 0;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				v.push_back({ i,j });
			}
			else if (map[i][j] == 0) {
				cnt++;
			}
		}
	}
	if (cnt == 0) {
		printf("0\n");
		return 0;
	}
	sort(v.begin(), v.end());
	temp.resize(v.size());
	for (int i = 0; i < temp.size(); i++) {
		temp[i] = 0;
	}
	for (int i = 0; i < M; i++) {
		temp[i] = 1;
	}
	sort(temp.begin(), temp.end());
	
	do {
		go(cnt);
	} while (next_permutation(temp.begin(), temp.end()));
	if (ans == 987654321) {
		printf("-1\n");
	}
	else {
		printf("%d\n", ans);
	}
}
