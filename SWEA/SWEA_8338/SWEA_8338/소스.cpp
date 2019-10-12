#include <iostream>

int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {
		int N;
		scanf("%d", &N);
		int sum;
		for (int i = 0; i < N; i++) {
			int tmp;
			scanf("%d", &tmp);
			if (i == 0) sum = tmp;
			else {
				if (sum <= 1 || tmp <= 1) sum += tmp;
				else {
					sum *= tmp;
				}
			}
		}
		
		printf("#%d %d\n", test_case, sum);
	}
	return 0;
}