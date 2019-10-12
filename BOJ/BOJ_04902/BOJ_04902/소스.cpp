#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;

int map[401][801];
int s[401][801];
long ans = 0;

void calc(int row, int left, int right, long sum) {
	if (row < 1 || row > N) return;
	if (left < 1 || right > 2 * row - 1) return;
	sum += s[row][right] - s[row][left - 1];
	if (sum > ans) ans = sum;
	if (left % 2 == 0) {
		calc(row - 1, left - 2, right, sum);
	}
	else {
		calc(row + 1, left, right + 2, sum);
	}
}
int main() {
	for (int t=1;; t++){
		scanf("%d", &N);
		if (N == 0) {
			break;
		}
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= 2*i-1; j++) {
				scanf("%d", &map[i][j]);
				s[i][j] = s[i][j - 1] + map[i][j];
			}
		}
		ans = -100000;
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= 2 * i - 1; j++) {
				calc(i, j, j, 0);
				
			}
		}
		
		printf("%d. %ld\n", t,ans);
	}
	return 0;
}