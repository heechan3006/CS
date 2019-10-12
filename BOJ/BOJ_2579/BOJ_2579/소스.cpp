#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int D[301];
int A[301];
int N;
int go(int n) {
	if (D[n] != -1) return D[n];
	D[n] = max(go(n - 3) + A[n - 1] + A[n], go(n - 2) + A[n]);
	return D[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	memset(D, -1, sizeof(D));
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	
	cout << go(N) << "\n";
}