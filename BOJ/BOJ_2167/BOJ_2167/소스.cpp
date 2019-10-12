#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int D[301][301];
int A[301][301];
int K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
			D[i][j] = A[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			D[i][j] += D[i - 1][j] + D[i][j - 1]-D[i-1][j-1];
		}
	}
	cin >> K;
	while (K--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = D[x2][y2] - D[x1 - 1][y2] - D[x2][y1 - 1] + D[x1 - 1][y1 - 1];
		cout << ans << "\n";
	}
}