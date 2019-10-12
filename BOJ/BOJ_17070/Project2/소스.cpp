#include <iostream>
#include <cstring>
#define MAXN 33
using namespace std;

int map[MAXN][MAXN];
int D[MAXN][MAXN][3];
int N;
int ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	D[0][1][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == 0 && j == 0) continue;
			if (map[i][j] == 1) continue;
			if (map[i][j + 1] == 0) {
				D[i][j + 1][0] = D[i][j][0] + D[i][j][2];
			}
			if (map[i + 1][j] == 0) {
				D[i + 1][j][1] = D[i][j][1] + D[i][j][2];
			}
			if (i + 1 < N && j + 1 < N) {
				if (map[i + 1][j + 1] == 0 && map[i+1][j]==0 && map[i][j+1] ==0) {
					D[i + 1][j + 1][2] = D[i][j][0] + D[i][j][1] + D[i][j][2];
				}
			}
			
		}
	}
	for (int i = 0; i < 3; i++) {
		ans += D[N - 1][N - 1][i];
	}
	cout << ans << "\n";
	return 0;
}
