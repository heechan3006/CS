#include <iostream>
#include <cstring>

int cow[4][100001];
int N, Q;

int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case<=t; test_case++){
		scanf("%d %d", &N, &Q);
		memset(cow, 0, sizeof(cow));
		for (int i = 1; i <= N; i++) {
			int tmp;
			scanf("%d", &tmp);
			cow[tmp][i] = 1;
		}
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= N; j++) {
				cow[i][j] += cow[i][j - 1];
			}
		}
		printf("#%d\n", test_case);
		for (int i = 0; i < Q; i++) {
			int left, right;
			scanf("%d %d", &left, &right);
			printf("%d %d %d\n", cow[1][right] - cow[1][left - 1], cow[2][right] - cow[2][left - 1], cow[3][right] - cow[3][left - 1]);
		}
	}
	return 0;
}