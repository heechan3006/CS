#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAXN 1000001

long long Num[MAXN];
int N;

int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case<=t; test_case++){
		memset(Num, 0, sizeof(Num));
		scanf("%d", &N);
		int tmp;
		long long ans = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &tmp);
			Num[tmp]++;
			if (ans < tmp) ans = tmp;
		}
		long long sum = 0;
		for (int i = ans; i >= 0; i--) {
			sum += Num[i];
			if (sum >= i) {
				break;
			}
		}
		printf("#%d %llu\n", test_case,sum);
	}
	return 0;
}

