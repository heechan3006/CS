#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 101
using namespace std;

char map[MAXN][MAXN];

bool visited[MAXN][MAXN];

int H,W,N;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int sx, sy;
bool flag;
vector<pair<int, int>> cluster;
void down() {
	bool loop = true;
	while(loop){
		for (int i = 0; i < cluster.size(); i++) {
			int x = cluster[i].first;
			int y = cluster[i].second;
			map[x][y] = '.';
		}
		for (int i = 0; i < cluster.size(); i++) {
			int x = cluster[i].first;
			int y = cluster[i].second;
			x++;
			if (x == H || map[x][y] == 'x') {
				loop = false;
				break;
			}	
		}
		if (loop) {
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
void dfs(int x, int y) {
	if (x == H - 1) {
		flag = true;
	}
	cluster.push_back({ x,y });
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
		if (visited[nx][ny]) continue;
		if (map[nx][ny] == 'x') {
			dfs(nx, ny);
		}
	}
}
void clust() {
	memset(visited, false, sizeof(visited));
	for (int k = 0;  k < 4; k++){
		cluster.clear();
		int nx = sx + dx[k];
		int ny = sy + dy[k];
		if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
		if (map[nx][ny] == 'x' && !visited[nx][ny]) {
			flag = false;
			dfs(nx, ny);
			if (!flag){
				down();
			}
		}
	}
	return;
}
void crash(int h,int dir) {
	sx = -1;
	sy = -1;
	if (dir%2 == 1){
		for (int i = 0; i < W; i++) {
			if (map[H - h][i] == 'x') {
				map[H - h][i] = '.';
				sx = H-h;
				sy = i;
				break;
				
			}
		}	
	}
	else {
		for (int i = W-1; i >= 0; i--) {
			if (map[H - h][i] == 'x') {
				map[H - h][i] = '.';
				sx = H - h;
				sy = i;
				break;
			}
		}
	}
	
	return;
}
int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}
	cin >> N;
	int h;
	for (int i = 1 ; i<= N; i++){
		cin >> h;
		crash(h,i);
		if (sx == -1 && sy == -1) continue;
		clust();
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	return 0;
}
