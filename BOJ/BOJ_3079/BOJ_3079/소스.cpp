#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define MAXN 100000+1
#define MAXV 1000000000+1
using namespace std;

long long Time[MAXN];
int N, M;

bool check(long long limit_time) {
	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt += limit_time / Time[i];
	}
	return cnt >= M;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &Time[i]);
	}
	long long low = 1;
	long long high = 1e18;
	long long ans = 1e18;
	long long mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (check(mid)) {
			ans = min(ans, mid);
			high = mid-1;
		}
		else {
			low = mid + 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
