#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

#define MAX_N 200
using namespace std;

int N;
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case<=t; test_case++){
		scanf("%d", &N);
		int ans = 0;
		for (int w = 0; w*w <= N; w++) {
			for (int x = w; w*w + x * x <= N; x++) {
				for (int y = x; w*w + x*x + y * y <= N; y++) {
					int z = sqrt(N - (w * w + x * x + y * y));
					if (z < y) break;
					if (w * w + x * x + y * y + z * z == N) {
						ans++;
					}
				}
			}
		}
		printf("#%d %d\n", test_case,ans);
	}
	return 0;
}
