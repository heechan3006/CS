#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> v;
int main() {
	scanf("%d%d", &N, &K);
	int tmp;
	int max_coin = 0;
	int max_idx = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
		if (max_coin < tmp) {
			max_coin = tmp;
			max_idx = i;
		}
	}
	int ans = 0;
	
	for (int i = max_idx; i >= 0; i--) {
		ans += K / v[i];
		K %= v[i];
	}
	printf("%d\n", ans);
}
