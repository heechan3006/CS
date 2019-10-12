#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define MAX_N 1000000
using namespace std;

int N, M;
long long tree[MAX_N];

bool possible(long long mid) {
	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		if (tree[i] - mid >= 0) {
			cnt += tree[i] - mid;
		}
		
	}
	if (cnt >= M) return true;
	return false;
}
int main() {
	scanf("%d%d", &N, &M);
	long long high = 0;
	
	for (int i = 0; i < N; i++) {
		scanf("%lld", &tree[i]);
		high = max(high, tree[i]);
	}
	
	long long row = 1;
	long long ans = 0;
	
	while (row <= high) {
		long long mid = (row + high) / 2;
		if (possible(mid)) {
			if (ans < mid) ans = mid;
			row = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	printf("%lld\n", ans);
	
}