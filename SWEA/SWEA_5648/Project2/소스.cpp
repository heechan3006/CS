#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAXN 4004
using namespace std;

int map[MAXN][MAXN];
struct node {
	int x;
	int y;
	int dir;
	int energy;
};
int N;
vector<node> v;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int bfs() {
	int sum = 0;
	while (!v.empty()) {
		
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].x;
			int y = v[i].y;
			int energy = v[i].energy;
			int dir = v[i].dir;
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			map[x][y] = 0;
			if (nx < 0 || ny < 0 || nx >= MAXN || ny >= MAXN) {
				v.erase(v.begin() + i);
				i--;
				continue;
			}
			map[nx][ny] += energy;
			v[i].x = nx;
			v[i].y = ny;
		}
		vector<pair<int,int> > tmp;
		for (int i = 0; i < v.size(); i++) {
			if (map[v[i].x][v[i].y] != v[i].energy) {
				tmp.push_back({ v[i].x,v[i].y });
				sum += v[i].energy;
				v.erase(v.begin() + i);
				i--;
			}
		}
		for (int i = 0; i < tmp.size(); i++) {
			map[tmp[i].first][tmp[i].second] = 0;
		}
	}
	
	return sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		v.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			int x, y, dir, energy;
			cin >> x >> y >> dir >> energy;

			v.push_back({ MAXN / 2 - 2 * y,MAXN / 2 + 2 * x,dir,energy });
		}
		cout << "#"<<test_case<<" "<<bfs() << "\n";
	}
	
	
	
	return 0;
}