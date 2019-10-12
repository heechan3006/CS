#include <iostream>
#define MAXN 400+1
using namespace std;
int N, K,S;
int D[MAXN][MAXN];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int u, v;
		cin >> u >> v;
		D[u][v] = -1;
		D[v][u] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j || i == k || k == j) continue;
				if (D[i][k] == 1 && D[k][j] == 1) {
					D[i][j] = 1;
				}
				else if (D[i][k] == -1 && D[k][j] == -1) {
					D[i][j] = -1;
				}
			}
		}
	}
	cin >> S;
	while (S--) {
		int u, v;
		cin >> u >> v;
		cout << D[u][v] << "\n";
	}
	return 0;
}