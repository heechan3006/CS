#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;
int N;
int D[1000001];
int main() {
	cin >> N;
	memset(D, 0, sizeof(D));
	D[1] = 0;
	for (int i = 2; i <= N; i++) {
		D[i] = D[i - 1] + 1;
		if (i % 2 == 0) {
			D[i] = min(D[i], D[i / 2] + 1);
		}
		if (i % 3 == 0) {
			D[i] = min(D[i], D[i / 3] + 1);
		}
		
	}
	printf("%d\n", D[N]);
	return 0;
}
