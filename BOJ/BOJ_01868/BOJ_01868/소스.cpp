#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

char map[301][301];
int dist[301][301];
bool visited[301][301];
int n;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int t;
queue<pair<int, int>> q;

void change_dist() {
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int cnt = 0;
			if (map[i][j] == '*') continue;
			
			for (int k = 0; k < 8; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (map[nx][ny] == '*') cnt += 1;
				
			}
			dist[i][j] = cnt;
		}
	}
}
void bfs(int i, int j) {
	
	
	q.push({ i,j });
	while (!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		visited[cx][cy] = true;
		q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (map[nx][ny] == '*') continue;
			if (visited[nx][ny] == true) continue;
			visited[nx][ny] = true;
			if (dist[nx][ny] == 0) q.push({ nx,ny });
			
		}
	}
}
int main() {
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++){
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf(" %1c", &map[i][j]);
			}
		}
		memset(dist, -1, sizeof(dist));
		change_dist();
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j] == 0 && !visited[i][j]){
					bfs(i,j);
					count++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j] != -1 && !visited[i][j]) count++;
			}
		}
		printf("#%d %d\n",test_case,count);
		memset(visited, false, sizeof(visited));
	}
}