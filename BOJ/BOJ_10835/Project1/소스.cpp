#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 2000

using namespace std;

int card_a[MAXN];
int card_b[MAXN];
int cache[MAXN][MAXN];
int ans;
int N;
int dp(int idx_a, int idx_b) {
	if (idx_a >= N || idx_b >= N) return 0;
	int& ret = cache[idx_a][idx_b];
	if (ret != -1) return ret;
	ret = 0;
	
	// 오른쪽 < 왼쪽일때
	if (card_b[idx_b] < card_a[idx_a]) {
		ret += max({ dp(idx_a, idx_b + 1) + card_b[idx_b],dp(idx_a + 1, idx_b), dp(idx_a + 1, idx_b + 1) });
		
	}
	else {
		ret += max(dp(idx_a + 1, idx_b), dp(idx_a + 1, idx_b + 1) );
	}
	return ret;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &card_a[i]);
	}
	for (int j = 0; j < N; j++) {
		scanf("%d", &card_b[j]);
	}
	memset(cache, -1, sizeof(cache));
	printf("%d\n",dp(0, 0));
	return 0;
}