#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>

using namespace std;

int N, M;
int A[1001];
int B[1001];
int score[1001];


int main() {
	int t;
	scanf("%d", &t);
	for (int test_case= 1; test_case <= t; test_case++){
		scanf("%d %d", &N, &M);
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(score, 0, sizeof(score));
		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
		}
		for (int i = 0; i < M; i++) {
			scanf("%d", &B[i]);
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (B[i] >= A[j]) {
					score[j] += 1;
					break;
				}
			}
		}
		int ans = 0;
		int loc = 0;
		for (int i = 0; i < N; i++) {
			if (ans < score[i]) {
				ans = score[i];
				loc = i+1;
			}
		}
		printf("#%d %d\n", test_case,loc);
	}
	return 0;
}