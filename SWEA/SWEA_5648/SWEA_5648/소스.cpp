#include <iostream>
#include <vector>
#include <queue>
#define MAXN 4000+4
using namespace std;

int map[MAXN][MAXN];
int dx[] = {-1,1,0,0};
int dy[] = { 0,0,-1,1 };
int N;
struct node {
	int x;
	int y;
	int dir;
	int p;
};
bool is_match(int dir1, int dir2) {
	if (dir1 == 0) {
		if (dir2 == 1) return true;
	}
	else if (dir1 == 1) {
		if (dir2 == 0) return true;
	}
	else if (dir1 == 2) {
		if (dir2 == 3) return true;
	}
	else if (dir1 == 3) {
		if (dir2 == 2) return true;
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
		cin >> N;
		vector<node> v;
		int tmp_x, tmp_y, tmp_dir, tmp_p;
		for (int i = 0; i < N; i++) {
			cin >> tmp_x >> tmp_y >> tmp_dir >> tmp_p;
			v.push_back({ 2*(-tmp_y+ 1000),2*(tmp_x + 1000),tmp_dir,tmp_p });
		}
		int sum = 0;
		while (!v.empty()) {
			int v_size = v.size();
			for (int i = 0; i < v_size; i++) {
				map[v[i].x][v[i].y] = 0;
				int dir = v[i].dir;
				int nx = v[i].x + dx[dir];
				int ny = v[i].y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= MAXN || ny >= MAXN) {
					v[i].p = 0;
					continue;
				}
				v[i].x = nx;
				v[i].y = ny;
				map[nx][ny] += v[i].p;
			}
			for (int i = 0; i < v_size; i++) {
				if (v[i].p == 0) continue;
				if (map[v[i].x][v[i].y] != v[i].p) {
					sum += map[v[i].x][v[i].y];
					map[v[i].x][v[i].y] = 0;
					v[i].p = 0;
				}
			}
			vector<node> tmp;
			tmp.assign(v.begin(), v.end());
			v.clear();
			int tmp_size = (int)tmp.size();
			for (int i = 0; i < tmp_size; i++) {
				if (tmp[i].p != 0) {
					v.push_back(tmp[i]);
				}
			}
		}
		cout << "#"<<test_case<<" "<<sum << "\n";
	}
	return 0;
}