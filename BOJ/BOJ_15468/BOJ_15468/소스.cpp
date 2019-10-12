#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define MAX_N 1500001
using namespace std;

int N;
int dist[MAX_N+50];
int T[MAX_N];
int P[MAX_N];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int tmp_t, tmp_p;
		scanf("%d%d", &tmp_t, &tmp_p);
		T[i] = tmp_t;
		P[i] = tmp_p;
	}
	for (int i = 0; i < N; i++) {
		dist[i + T[i]] = max(dist[i + T[i]], dist[i] + P[i]);
		dist[i + 1] = max(dist[i], dist[i + 1]);
	}
	printf("%d\n", dist[N]);
}
