#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int A[1001][1001];
int D[1001][1001];
int N, M;

int main() {
	
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &A[i][j]);
		}
	}
	
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == 0 || j == 0){
				D[i][j] = A[i][j];
			}
			else if (A[i][j]) {
				D[i][j] = min(min(D[i - 1][j], D[i][j - 1]), D[i - 1][j - 1]) + 1;
			}
			ans = max(ans, D[i][j]);
		}
	}
	printf("%d", ans*ans);
}