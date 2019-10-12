#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 200001
using namespace std;

int N, C;
vector<int> house;

bool possible(long long dist) {
	int cnt = 1;
	int prev = house[0];
	for (int i = 0; i < house.size(); i++) {
		if (house[i] - prev >= dist) {
			cnt++;
			prev = house[i];
		}
	}
	if (cnt >= C) return true;
	return false;
}
int main() {
	scanf("%d%d", &N, &C);
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		house.push_back(tmp);
	}
	sort(house.begin(), house.end());
	int row = 1;
	int high = house[N - 1] - house[0];
	int ans = 0;
	while (row <= high) {
		int mid = (row + high) / 2;
		if (possible(mid)) {
			if (ans < mid) ans = mid;
			row = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
