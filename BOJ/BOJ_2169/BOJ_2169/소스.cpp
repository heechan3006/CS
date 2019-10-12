#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 1000
#define INF 98765432
using namespace std;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
long long D[MAXN][MAXN][3];

int N, M;
long long dp(int x, int y,int dir) {
	
	if (x == N - 1 && y == M - 1) {
		return map[x][y];
	}
	long long &result = D[x][y][dir];
	if (result != -INF) return result;
	visited[x][y] = true;
	long long res1 = -INF, res2 = -INF, res3 = -INF;
	if (y - 1 >= 0 && !visited[x][y - 1]) {
		res1 = dp(x, y - 1,0);
	}
	if (y + 1 < M && !visited[x][y + 1]) {
		res2 = dp(x, y + 1,1);
	}
	if (x + 1 < N && !visited[x + 1][y]) {
		res3 = dp(x + 1, y, 2);
	}
	visited[x][y] = false;
	result = max(res1, max(res2, res3)) + map[x][y];
	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			D[i][j][0]= D[i][j][1] = D[i][j][2] = -INF;
		}
	}
	memset(visited, false, sizeof(visited));
	long long ans = dp(0, 0, 0);
	cout << ans << "\n";
}