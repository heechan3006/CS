#include <iostream>
#include <stack>
#include <vector>
#define MAXN 101
using namespace std;

int N;
int map[MAXN][MAXN];
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
void make_curve(int x, int y, int d, int g) {
	vector<int> v;
	stack<int> st;
	v.push_back(d);
	while (g--) {
		for (int i = 0; i < v.size(); i++) {
			st.push(v[i]);
		}
		while (!st.empty()) {
			int dir = st.top();
			st.pop();
			dir = (dir + 1) % 4;
			v.push_back(dir);
		}
	}
	map[x][y] = 1;
	for (int i = 0; i < v.size(); i++) {
		x += dx[v[i]];
		y += dy[v[i]];
		map[x][y] = 1;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int sx, sy, d, g;

	for (int i = 0; i < N; i++) {
		cin >> sx >> sy >> d >> g;
		make_curve(sy, sx, d, g);
	}
	int ans = 0;
	for (int i = 0; i < MAXN-1; i++) {
		for (int j = 0; j < MAXN-1; j++) {
			if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1) ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}