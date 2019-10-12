#include <iostream>
#define MOD 1000000000
using namespace std;

int N, K;
int D[201][201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i <= N; i++) {
		D[i][1] = 1;
	}
	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				D[j][i] = (D[j][i] + D[j - k][i - 1])%MOD;
			}
		}
	}
	cout << D[N][K] % MOD << "\n";
}