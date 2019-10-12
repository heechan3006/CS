#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

bool d[31][31][31][436];
char ans[32];
int N, K;
int go(int i, int a, int b, int p) {
	if (i == N) {
		if (p == K) return true;
		else return false;
	}
	if (d[i][a][b][p]) return false;
	d[i][a][b][p] = true;
	ans[i] = 'A';
	if (go(i + 1, a + 1, b, p)) return true;
	ans[i] = 'B';
	if (go(i + 1, a, b + 1, p + a)) return true;
	ans[i] = 'C';
	if (go(i + 1, a, b, p + a + b)) return true;
	return false;
}
int main() {
	scanf("%d%d", &N, & K);
	if (go(0, 0, 0, 0)) {
		printf("%s\n", ans);
	}
	else {
		printf("-1\n");
	}
}

