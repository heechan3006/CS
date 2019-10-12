#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#define MAXN 1000 +1

using namespace std;

int cache[MAXN][MAXN];
int N, M;
int main() {
	scanf("%d%d", &N, &M);
	
	int ans = 0;
	int tmp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &tmp);
			if (tmp == 0) {
				cache[i][j] = min(cache[i - 1][j - 1], min(cache[i - 1][j], cache[i][j - 1])) + 1;
				ans = max(ans, cache[i][j]);
			}
		}
	}
	printf("%d", ans);
	return 0;
}