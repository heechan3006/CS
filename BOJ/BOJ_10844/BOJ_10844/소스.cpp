#include <iostream>
#include <algorithm>
#define MOD 1000000000
using namespace std;

int N;
long long D[101][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	D[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		D[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j==0){
				D[i][j] = D[i-1][j + 1]%MOD;
			}
			else if (j == 9) {
				D[i][j] = D[i-1][j - 1]%MOD;
			}
			else {
				D[i][j] = (D[i-1][j - 1] + D[i-1][j + 1])%MOD;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += D[N][i] % MOD;
	}
	cout << ans%MOD << "\n";
}