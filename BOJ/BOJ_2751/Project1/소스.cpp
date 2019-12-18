#include <iostream>
#include <algorithm>
const int MAXN = 2e6+1;
int num[MAXN];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d",&tmp);
		num[tmp + 1000000]++;
	}
	
	for (int i = 0; i < MAXN; i++) {
		if (num[i] == 0) continue;
		printf("%d\n", i-1000000);
	}
	return 0;
}