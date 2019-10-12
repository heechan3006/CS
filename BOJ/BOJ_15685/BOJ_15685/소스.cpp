#include <iostream>
#include <vector>
#define MAXN 101
using namespace std;
int map[MAXN][MAXN];
int N;
int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 };
int X, Y, D, G;
vector<int> v;
void make_dir(int d, int g) {
	v.push_back(d);
	while (g--){
		for (int j = v.size() - 1; j >= 0; j--) {
			int dir = v[j];
			v.push_back((dir + 1) % 4);
		}
	}
}
void solve(int x, int y, int d, int g) {
	make_dir(d, g);
	for (int i = 0; i < v.size(); i++) {
		x = x + dx[v[i]];
		y = y + dy[v[i]];
		map[y][x] = 1;
	}
}
int main() {
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> X >> Y >> D >> G;
		map[Y][X] = 1;
		v.clear();

		solve(X, Y, D, G);
	}
	int count = 0;
	for (int i = 0; i < MAXN-1; i ++) {
		for (int j = 0; j < MAXN-1; j ++) {
			if (map[i][j]&&map[i][j + 1]&& map[i + 1][j]&& map[i + 1][j + 1]) {
				count++;
			}
		}
	}
	printf("%d\n", count);
	return 0;
}