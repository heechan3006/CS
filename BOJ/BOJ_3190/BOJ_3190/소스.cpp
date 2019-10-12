#include <iostream>
#include <deque>
#include <cstring>
#include <vector>
#define MAXN 101
using namespace std;

int map[MAXN][MAXN];
int N, K, L, sec;
char dir;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
deque <pair<int,int>> q;
int main() {
	cin >> N >> K;
	memset(map, -1, sizeof(map));
	int tmp_x, tmp_y;
	for (int i = 0; i < K; i++) {
		cin >> tmp_x >> tmp_y;
		map[tmp_x][tmp_y] = 0;
	}
	cin >> L;
	vector<pair<int, char>> v;
	for (int i = 0; i < L; i++) {
		cin >> sec >> dir;
		v.push_back({ sec,dir });
	}
	q.push_back({ 1,1 });
	map[1][1] = 1;
	int k = 0;
	int t = 0;
	int l = 0;
	while (1) {
		t++;
		int sx = q.back().first;
		int sy = q.back().second;
		int nx = sx + dx[k];
		int ny = sy + dy[k];
		if (nx <= 0 || ny <= 0 || nx > N || ny > N ) {
			break;
		}
		if (map[nx][ny] == 1) {
			break;
		}
		q.push_back({ nx,ny });
		if (map[nx][ny] == 0) {
			map[nx][ny] = 1;
				
		}
		else{
			int ex = q.front().first;
			int ey = q.front().second;
			map[nx][ny] = 1;
			map[ex][ey] = -1;
			q.pop_front();
		}
		if (l < L && v[l].first == t) {
			if (v[l].second == 'D') {
				k++;
				if (k > 3) k = 0;
			}
			else {
				k--;
				if (k < 0) k = 3;
			}
			l++;
		}
	}
	
	printf("%d\n", t);
	return 0;
}