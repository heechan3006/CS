#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int D[1001][1001];
int A[1001][1001];
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}
	memset(D, 0, sizeof(D));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			D[i][j] = max(D[i - 1][j], D[i][j - 1]) + A[i][j];
		}
	}
	cout << D[N][M] << "\n";
}