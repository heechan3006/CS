#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 500
#define INF 987654321
using namespace std;

int N;
int D[MAXN][MAXN];
pair<int, int> A[MAXN];
int dp(int left, int right) {
	if (left == right) return 0;
	if (D[left][right] != -1) return D[left][right];
	D[left][right] = INF;
	for (int i = left; i < right; i++) {
		D[left][right] = min(D[left][right], dp(left, i) + dp(i + 1, right) + A[left].first * A[i].second * A[right].second);
	}
	return D[left][right];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}
	memset(D, -1, sizeof(D));
	int ans = dp(0, N - 1);
	cout << ans << "\n";
}