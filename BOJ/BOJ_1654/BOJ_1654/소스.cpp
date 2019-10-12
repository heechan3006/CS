#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
vector<int> v;

bool possible(long long mid) {
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		cnt += v[i] / mid;
	}
	if (cnt >= N) return true;
	return false;
}
long long compute_num(long long mid, long long sum) {

	for (int i = 0; i < v.size(); i++) {
		sum += v[i] / mid;
	}
	return sum;
}
int main() {
	scanf("%d%d", &K, &N);
	int tmp;
	for (int i = 0; i < K; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	long long left = 1;
	long long right = v[K - 1];

	long long ans = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;

		if (possible(mid)) {
			if (ans < mid) ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;

		}

	}
	printf("%lld\n", ans);
}