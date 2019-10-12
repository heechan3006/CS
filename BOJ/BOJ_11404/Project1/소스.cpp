#include <iostream>
#include <algorithm>

#define MAXV 100 + 1

using namespace std;
int D[MAXV][MAXV];
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		if (D[from][to] == 0) D[from][to] = w;
		else {
			D[from][to] = min(D[from][to], w);
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				if (D[i][k] == 0 || D[k][j] == 0) continue;
				if (D[i][j] == 0) {
					D[i][j] = D[i][k] + D[k][j];
				}
				else {
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << D[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
