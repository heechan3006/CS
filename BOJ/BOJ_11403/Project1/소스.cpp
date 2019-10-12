#include <iostream>
#include <cstring>
#define MAXN 100
#define INF 987654321
using namespace std;
int N;
int map[MAXN][MAXN];
int D[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			D[i][j] = INF;
			if (map[i][j]) D[i][j] = map[i][j];
		}
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];

				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (D[i][j] == INF) cout << 0 << " ";
			else cout << 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}