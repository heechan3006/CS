#include <iostream>
#include <cstring>
#define MAXN 100

using namespace std;

int map[MAXN][MAXN];
int cache[MAXN][MAXN];
int N;

int jump2(int x, int y) {
	if (x >= N || y >= N) return 0;
	if (x == N - 1 && y == N - 1) return 1;
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	return ret = (jump2(x + map[x][y], y)) || (jump2(x, y + map[x][y]));
}
bool jump1(int x, int y) {
	if (x >= N || y >= N) return false;
	if (x == N - 1 && y == N - 1) return true;
	return jump1(x + map[x][y], y) || jump1(x, y + map[x][y]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		if (jump2(0, 0)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}