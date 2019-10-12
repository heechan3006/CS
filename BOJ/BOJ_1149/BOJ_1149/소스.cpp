#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int D[1001][3];
int N;
int A[1001][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	memset(D, 0, sizeof(D));
	for (int i = 1; i <= N; i++) {
		cin >> A[i][0] >> A[i][1] >> A[i][2];
	}
	D[1][0] = A[1][0];
	D[1][1] = A[1][1];
	D[1][2] = A[1][2];
	for (int i = 2; i <= N; i++) {
		D[i][0] = A[i][0]+min(D[i-1][1],D[i-1][2]);
		D[i][1] = A[i][1] + min(D[i - 1][0], D[i - 1][2]);
		D[i][2] = A[i][2] + min(D[i - 1][0], D[i - 1][1]);
	}
	int ans = min(min(D[N][0], D[N][1]), D[N][2]);
	cout << ans << "\n";
}