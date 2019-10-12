#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int D[1001][31][2];
int num[1001];

int T, W;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T >> W;
	for (int i = 1; i <= T; i++) {
		cin >> num[i];
		num[i]--;
	}
	D[0][0][0] = 0;
	D[0][0][1] = 0;
	for (int i = 1; i <= T; i++) {
		D[i][0][0] = D[i - 1][0][0] + (num[i] == 0);
		for (int j = 1; j <= W; j++) {
			if (i < j) continue;
			if (j % 2 == 0) {
				D[i][j][0] = max(D[i - 1][j - 1][1], D[i - 1][j][0]) + (num[i] == 0);
			}
			else {
				D[i][j][1] = max(D[i - 1][j - 1][0], D[i - 1][j][1]) + (num[i] == 1);
			}
		}
	}
	int ans = 0;
	for (int j = 0; j <= W; j++) {
		ans = max(ans, D[T][j][1]);
		ans = max(ans, D[T][j][0]);
	}
	cout << ans << "\n";
}