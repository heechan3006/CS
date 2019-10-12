#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 20
using namespace std;

int N;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int sx, sy;
struct node {
	int d;
	int size;
	int x;
	int y;
	int cnt;
};

queue<node> q;
bool compare(node a, node b) {
	if (a.d <= b.d) {
		if (a.d == b.d) {
			if (a.x <= b.x) {
				if (a.x == b.x) {
					if (a.y < b.y) {
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				sx = i;
				sy = j;
				map[i][j] = 0;
				q.push({ 0,2,i,j,0 });
			}
		}
	}
	int time = 0;
	while (1){
		memset(visited, false, sizeof(visited));
		int tmp_d = 0;
		visited[q.front().x][q.front().y] = true;
		vector<node> v;
		while (!q.empty()) {
			int q_size = q.size();
			tmp_d++;
			while (q_size--) {
				int s = q.front().size;
				int x = q.front().x;
				int y = q.front().y;
				int cnt = q.front().cnt;
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (visited[nx][ny]) continue;
					if (map[nx][ny] <= s) {
						if (map[nx][ny] < s && map[nx][ny]!=0) {
							v.push_back({ tmp_d,s,nx,ny,cnt });
						}
						visited[nx][ny] = true;
						q.push({ tmp_d,s,nx,ny,cnt });
					}
				}
			}
			
		}
		if (!v.size()) break;
		sort(v.begin(), v.end(), compare);
		map[v[0].x][v[0].y] = 0;
		v[0].cnt++;
		if (v[0].cnt == v[0].size) {
			v[0].size++;
			v[0].cnt = 0;
		}
		q.push(v[0]);
		time += v[0].d;
	}
	printf("%d", time);
	return 0;
}