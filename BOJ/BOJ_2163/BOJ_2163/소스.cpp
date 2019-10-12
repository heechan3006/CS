#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int D[301][301];

int N, M;
int go(int n, int m) {
	if (D[n][m] != -1) return D[n][m];
	if (n == 1 && m == 1) return 0;
	if (n == 1) {
		return D[n][m] = go(n, m / 2) + go(n, m - m / 2) + 1;
	}
	else {
		return D[n][m] = go(n / 2, m) + go(n - n / 2, m) + 1;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	memset(D, -1, sizeof(D));
	cout << go(N, M) << "\n";
}