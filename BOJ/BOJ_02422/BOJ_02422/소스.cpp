#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, M;

int a[201][201];

int main() {
	scanf("%d%d", &N, &M);
	int tmp_a, tmp_b;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &tmp_a, &tmp_b);
		a[tmp_a][tmp_b] = a[tmp_b][tmp_a] = true;
	}
	int ans = 0;
	for (int i = 1; i <= N-2; i++) {
		for (int j = i + 1; j <= N-1; j++) {
			for (int k = j + 1; k <= N; k++) {
				if (a[i][j] || a[i][k] || a[j][k]) continue;
				ans++;
			}
		}
	}
	printf("%d\n", ans);
}