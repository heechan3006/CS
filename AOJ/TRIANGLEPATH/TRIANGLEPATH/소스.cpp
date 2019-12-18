#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 100;

int map[MAXN][MAXN];
int cache[MAXN][MAXN];
int N;
// 전체 경로의 최대합을 반환
int pathSum(int x, int y, int sum) {
	if (x == N) return sum;
	return max(pathSum(x + 1, y, sum + map[x + 1][y]), pathSum(x + 1, y + 1, sum + map[x + 1][y + 1]));
}
// 부분 경로의 최대합을 반환
int path2(int x, int y) {
	if (x == N) return map[x][y];
	int& ret = cache[x][y];
	if (ret != -1) return ret;

	return ret = map[x][y] + max(path2(x + 1, y), path2(x + 1, y + 1));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= i; j++) {
				cin >> map[i][j];
			}
		}
		cout << path2(1, 1) << "\n";
	}
	return 0;
}