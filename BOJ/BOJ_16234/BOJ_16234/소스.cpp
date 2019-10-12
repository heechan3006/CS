#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int A[51][51];
int dist[51][51];
bool visited[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int L, R;
int sum, cnt;
vector<pair<int,int>> v;

bool check(int x1, int y1, int x2, int y2) {
	if (L <= abs(A[x1][y1] - A[x2][y2]) && abs(A[x1][y1] - A[x2][y2]) <= R) return true;
	return false;
}


void dfs(int x, int y) {
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (visited[nx][ny]) continue;
		if (check(x, y, nx, ny)) {
			visited[nx][ny] = true;
			sum += A[nx][ny];
			cnt++;
			v.push_back({ nx,ny });
			dfs(nx, ny);
		}
	}
}
int main() {
	scanf("%d%d%d", &N, &L, &R);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	
	int count = 0;
	while (1){

		bool found = false;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]) continue;
				visited[i][j] = true;
				sum = A[i][j];
				cnt = 1;
				v.clear();
				v.push_back({ i,j });
				dfs(i, j);
				if (cnt >= 2) {
					for (int i = 0; i < v.size(); i++) {
						A[v[i].first][v[i].second] = sum / cnt;
					}
					found = true;
				}
			}
		}
		if (found) count++;
		else break;
		
		
	}
	printf("%d\n", count);
	return 0;
}