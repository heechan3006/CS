#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int D[4002];
int A[4002];
int N, M;
int S, E;

int main() {
	scanf("%d", &N);
	N = 2 * N - 1;
	memset(A, -1, sizeof(A));
	for (int i = 0; i < N; i+=2) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &M);
	int r =-1, p = -1;
	
	for (int i = 0; i < N; i++) {
		if (r < i) D[i] = 0;
		else {
			D[i] = min(r - i, D[2 * p - i]);
		}
		while (i - D[i] - 1 >= 0 && i + D[i] + 1 < N && A[i - D[i] - 1] == A[i + D[i] + 1]) D[i]++;
		if (i + D[i] > r) {
			r = i + D[i];
			p = i;
		}
	}

	for (int i = 0; i < M; i++) {
		scanf("%d%d", &S, &E);
		S = S-1<<1;
		E = E-1<<1;
		int center = (S + E) >> 1;
		
		if (D[center] >= E-center) printf("1\n");
		else printf("0\n");
	}
	return 0;
}