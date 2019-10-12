#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
const ll MAXN = 1e5 + 1;
const ll MAXM = 1e9 + 1;

ll Tk[MAXN];
int N, M;
bool check(ll limits) {
	ll cnt = 0;
	for (int i = 1; i <= N; i++) {
		cnt += limits / Tk[i];
		if (cnt >= M) break;
	}
	return cnt >= M;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; i++) {
			scanf("%llu", &Tk[i]);
		}
		ll ans = 1e18;
		ll low = 0;
		ll high = 1e18;
		while (low <= high) {
			ll mid = (low + high) / 2;
			if (check(mid)) {
				high = mid - 1;
				ans = min(ans, mid);
			}
			else {
				low = mid + 1;
			}
		}
		printf("#%d %llu\n", test_case, ans);
	}
	return 0;
}

