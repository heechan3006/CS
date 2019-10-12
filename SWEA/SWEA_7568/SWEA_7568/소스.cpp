#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 100000
using namespace std;

int N, M;
int A[MAXN];
int ans[MAXN];
int res;
int Binary(int start, int end, int x) {
	int left = start;
	int right = end;
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		
		if (A[mid] >= x) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case<=t; test_case++){
		res = 0;
		memset(ans, 0, sizeof(ans));
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
		}
		sort(A, A + N);
		scanf("%d", &M);
		int tmp;
		bool flag = false;
		for (int i = 0; i < M; i++) {
			scanf("%d", &tmp);
			if (tmp > A[N - 1]) {
				flag = true;
			}
			ans[Binary(0, N - 1, tmp)]++;
		}
		printf("#%d ",test_case);
		if (flag) printf("-1\n");
		else {
			for (int i = 0; i < N - 1; i++) {
				int tmp;
				if (M % (N - i)) {
					tmp = min(ans[i], M / (N - i)+1);
				}
				else {
					tmp = min(ans[i], M / (N - i));
				}
				res = max(tmp, res);
				M -= tmp;
				ans[i] -= tmp;
				ans[i + 1] += ans[i];
			}
			res = max(M, res);
			printf("%d\n", res);
		}
	}
	return 0;
}
