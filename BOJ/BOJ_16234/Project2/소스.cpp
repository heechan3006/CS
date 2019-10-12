#include <iostream>
#include <vector>
#include <cstring>

#define MAXN 50

using namespace std;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N, L, R;
struct node {
	int x;
	int y;
	int num;
};
vector<node> v;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y, int cnt) {
	visited[x][y] = true;
	v.push_back({ x,y,map[x][y] });
	
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (!visited[nx][ny] && abs(map[nx][ny]-map[x][y])>=L && abs(map[nx][ny] - map[x][y]) <= R) {
			dfs(nx, ny, cnt + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int time = 0;
	while (1) {
		bool flag = false;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					
					v.clear();
					dfs(i, j, 1);
					if (v.size() > 1) {
						flag = true;
						int sum = 0;
						for (int i = 0; i < v.size(); i++) {
							sum += v[i].num;
						}
						sum /= v.size();
						for (int i = 0; i < v.size(); i++) {
							map[v[i].x][v[i].y] = sum;
						}
					}

				}
			}
		}
		if (!flag) {
			printf("%d\n", time);
			break;
		}
		time++;
		
	}
	return 0;
}