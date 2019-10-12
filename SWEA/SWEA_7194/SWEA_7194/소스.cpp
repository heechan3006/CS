#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int s, t, a, b;
int day = 10e5;

int main() {
	int test;
	scanf("%d", &test);
	for (int test_case= 1; test_case<=test; test_case++){
		scanf("%d %d %d %d", &s, &t, &a, &b);
		day = 10e5;
		if (b == 1) {
			if ((t - s) % a == 0) day = (t - s) / a;
		}
		else{
			const int limit = t / b;
			for (int tc = 0; ; ++tc, s *= b) {
				if ((t - s) % a == 0) {
					int tmp_ans = tc;
					int tmp = (t - s) / a;
					for (int i = 0; i < tc; ++i) {
						tmp_ans += tmp % b;
						tmp /= b;
					}
					tmp_ans += tmp;
					if (day > tmp_ans) day = tmp_ans;
				}
				if (s > limit) break;
			}
		}
		printf("#%d ", test_case);
		if (day == 10e5) {
			printf("-1\n");
		}
		else {
			printf("%d\n", day);
		}
	}
	return 0;
}