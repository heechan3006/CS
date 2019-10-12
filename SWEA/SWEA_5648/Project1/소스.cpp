#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 4000 + 4
using namespace std;


int N,K;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
struct node {
	int x;
	int y;
	int dir;
	int energy;
};
queue<node> q;
vector<node> v;
int ans;
int map[MAXN][MAXN];
bool check(node a) {
	int x = a.x;
	int y = a.y;
	int dir = a.dir;
	for (int i = 0; i < v.size(); i++) {
		if (x == v[i].x && y == v[i].y) continue;
		if (((dir == 0 && v[i].dir == 1) || (dir == 1 && v[i].dir == 0)) && v[i].y == y) {
			if (dir == 0 && v[i].x < x) return true;
			if (dir == 1 && v[i].x > x) return true;
		}
		if ((dir == 0 || dir == 1) && (v[i].dir == 3 || v[i].dir == 2) && abs(v[i].y - y) == abs(v[i].x - x)) {
			if (dir == 0 && v[i].x < x) return true;
			if (dir == 1 && v[i].x > x) return true;
			
		}
		if (((dir == 2 && v[i].dir == 3) || (dir == 3 && v[i].dir == 2)) && v[i].x == x) {
			if (dir == 2 && v[i].y < y) return true;
			if (dir == 3 && v[i].y > y) return true;
		}
		if ((dir == 3 || dir == 2) && (v[i].dir == 0 || v[i].dir == 1) && abs(v[i].y - y) == abs(v[i].x - x)) {
			if (dir == 2 && v[i].y < y) return true;
			if (dir == 3 && v[i].y > y) return true;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int test_case=1; test_case<=t; test_case++){
		memset(map, 0, sizeof(map));
		cin >> N;
		ans = 0;
		for (int i = 0; i < N; i++) {
			int tmp_x, tmp_y, tmp_dir, tmp_e;
			cin >> tmp_x >> tmp_y >> tmp_dir >> tmp_e;
			tmp_x = 2*(tmp_x+1000);
			tmp_y = 2*(-tmp_y +1000);
			v.push_back({ tmp_y,tmp_x,tmp_dir,tmp_e });
			
		}
		while (!v.empty()) {
			for (int i = 0; i < v.size(); i++) {
				if (!check(v[i])) {
					v.erase(v.begin() + i);
					i--;
				}
			}
			for (int i = 0; i < v.size(); i++) {
				
				int x = v[i].x;
				int y = v[i].y;
				map[x][y] = 0;
				int dir = v[i].dir;
				int p = v[i].energy;
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= MAXN || ny >= MAXN) {
					v.erase(v.begin() + i);
					i--;
					continue;
				}
				v[i].x = nx;
				v[i].y = ny;
				map[nx][ny] += p;
			}
			vector<node> tmp;
			for (int i = 0; i < v.size(); i++) {
				if (map[v[i].x][v[i].y] != v[i].energy) {
					ans += v[i].energy;
					tmp.push_back(v[i]);
					v.erase(v.begin() + i);
					i--;
				}
			}
			for (int i = 0; i < tmp.size(); i++) {
				if (map[tmp[i].x][tmp[i].y] == 0) continue;
				map[tmp[i].x][tmp[i].y] = 0;
			}
			
		}
		cout << "#"<<test_case<<" "<<ans << "\n";
	}
	return 0;
}
