#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int A[2001];
bool D[2001][2001];
int S, E;
int N, M;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &M);
	for (int i = 1; i <= N; i++) {
		D[i][i] = true;
		if (A[i] == A[i + 1]) {
			D[i][i + 1] = true;
		}
	}
	for (int i = 3; i <= N; i++) {
		for (int j = 1; j <= N - i + 1; j++) {
			if (A[j] == A[j+i-1]&& D[j+1][j+i-2]){
				D[j][j + i - 1] = true;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &S, &E);
		printf("%d\n", D[S][E]);
	}
	return 0;
}
