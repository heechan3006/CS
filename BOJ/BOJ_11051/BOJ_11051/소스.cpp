#include <iostream>
#include <cstring>
#define MOD 10007
using namespace std;

int D[1001][1001];
int N, K;
int go(int n, int k) {
	if (k == 0 || n==k) return D[n][k] = 1;
	if (D[n][k] != -1) return D[n][k];
	D[n][k] = go(n - 1, k - 1)%MOD + go(n - 1, k)%MOD;
	return D[n][k];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	memset(D, -1, sizeof(D));
	cout << go(N, K)%MOD << "\n";
}