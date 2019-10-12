#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <tuple>
using namespace std;

char map[50][50];
int visited[50][50][2];
int N;
int s_turn, e_turn, sx, sy, ex, ey;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool check_tree(int x, int y, int turn) {
	if (turn == 0) {
		for (int i = y-1; i <= y+ 1; i++) {
			if (map[x][i] == '1') return false;
		}
	}
	else {
		for (int i = x - 1; i <= x + 1; i++) {
			if (map[i][y] == '1') return false;
		}
	}
	return true;
}
bool check(int x, int y) {
	if (x - 1 < 0 || x + 1 >= N || y - 1 < 0 || y + 1 >= N) return false;
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (map[i][j]  == '1') {
				return false;
			}
		}
	}
	return true;
}
int bfs() {
	queue<tuple<int, int, int>> q;
	q.push({ sx,sy,s_turn });
	visited[sx][sy][s_turn] = 0;
	while (!q.empty()) {
		int cx, cy, cur_turn;
		tie(cx, cy, cur_turn) = q.front();
		if (cx == ex && cy == ey && cur_turn == e_turn) return visited[cx][cy][cur_turn];
		q.pop();
		for (int k = 0 ; k< 5; k++){
			if (k == 4) {
				if (!check(cx, cy)) continue;
				if (visited[cx][cy][(cur_turn + 1) % 2] != -1) continue;
				visited[cx][cy][(cur_turn + 1) % 2] = visited[cx][cy][cur_turn]+1;
				q.push({ cx,cy, (cur_turn + 1) % 2 });
				
			}
			else {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (cur_turn == 0) {
					if (ny - 1 < 0 || ny + 1 >= N || nx < 0 || nx >= N) continue;		
				}
				else {
					if (nx - 1 < 0 || nx + 1 >= N || ny < 0 || ny >= N) continue;
					
				}
				if (!check_tree(nx, ny, cur_turn)) continue;
				if (visited[nx][ny][cur_turn] != -1) continue;
				visited[nx][ny][cur_turn] = visited[cx][cy][cur_turn] + 1;
				q.push({ nx,ny,cur_turn });
			}
		}
	}
	return 0;
}
int main() {
	cin >> N;
	vector<pair<int, int>> Start;
	vector<pair<int, int>> End;
	memset(visited, -1, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') Start.push_back({ i,j });
			else if (map[i][j] == 'E') End.push_back({ i,j });
		}
	}
	
	if (Start[0].first < Start[1].first) {
		s_turn = 1;
	}
	else if (Start[0].second < Start[1].second){
		s_turn = 0;
	}
	sx = Start[1].first;
	sy = Start[1].second;
	if (End[0].first < End[1].first) {
		e_turn = 1;
	}
	else if (End[0].second < End[1].second) {
		e_turn = 0;
	}
	ex = End[1].first;
	ey = End[1].second;
	
	int ans = bfs();
	printf("%d\n", ans);
}