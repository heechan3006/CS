#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

long long s[101][101];
int n,m;
long long psum(int x1, int y1, int x2, int y2) {
	return s[x2][y2] - s[x2][y1] - s[x1][y2] + s[x1][y1];
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1lld", &s[i][j]);
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i-1][j-1];
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = max({ ans, s[i][m] * psum(i, 0, n, j) * psum(i, j, n, m),
				s[n][j] * psum(0, j, i, m) * psum(i, j, n, m),
				s[i][j] * psum(i, 0, n, j) * psum(0, j, n, m),
				s[i][j] * psum(0, j, i, m) * psum(i, 0, n, m) });
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ans = max(ans,s[i][m] * psum(i, 0, j, m)* psum(j, 0, n, m));
		}
	}
	for (int i = 1; i < m; i++) {
		for (int j = i + 1; j <= m; j++) {
			ans = max(ans, s[n][i] * psum(0, i, n, j) * psum(0, j, n, m));
		}
	}
	printf("%lld", ans);
	return 0;
}
