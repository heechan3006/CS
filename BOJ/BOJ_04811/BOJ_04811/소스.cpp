#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
int N;
long long dist[31][31];

long long calc(int f, int h) {
	if (dist[f][h] != -1) return dist[f][h];
	if (f == 0) return 1;
	if (h == 0) return dist[f][h] = calc(f - 1, h + 1);
	return dist[f][h] = calc(f - 1, h + 1) + calc(f, h - 1);
}
int main() {
	memset(dist, -1, sizeof(dist));
	while (1) {
		scanf("%d", &N);
		if (N == 0) break;
		printf("%llu\n",calc(N, 0));
	}
	return 0;
}