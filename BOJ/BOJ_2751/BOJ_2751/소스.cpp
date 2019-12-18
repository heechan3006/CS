#include <iostream>
#include <algorithm>
const int MAXN = 1e6;
int num[MAXN];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	std::sort(num, num+N);
	for (int i = 0; i < N; i++) {
		printf("%d\n", num[i]);
	}
	return 0;
}