#include <iostream>
#define MAXN 1002
using namespace std;

bool map[MAXN][MAXN];
int C, R,K;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C >> R>>K;
	for (int i = 0; i <= 1001; i++) {
		map[i][0] = map[0][i] = map[R + 1][i] = map[i][C + 1] = true;
	}
	if (K > R * C) {
		cout << "0";
		return 0;
	}
	int x = 0, y = 1, d = 0;
	for (int i = 1; i <= R * C; i++) {
		x += dx[d];
		y += dy[d];
		map[x][y] = true;
		if (map[x + dx[d]][y + dy[d]]) d = (d + 1) % 4;
		if (i == K) {
			cout << y << " " << x;
			return 0;
		}
	}
}
