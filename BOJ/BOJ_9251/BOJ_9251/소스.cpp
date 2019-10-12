#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int D[1001][1001];
string s1, s2;
int dp(int idx1, int idx2) {
	if (idx1 == s1.size() || idx2 == s2.size()) return 0;
	if (D[idx1][idx2] != -1) return D[idx1][idx2];
	D[idx1][idx2] = max(dp(idx1 + 1, idx2), max(dp(idx1, idx2 + 1), dp(idx1 + 1, idx2 + 1) + (s1[idx1] == s2[idx2])));
	return D[idx1][idx2];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s1 >> s2;
	memset(D, -1, sizeof(D));
	cout << dp(0, 0) << "\n";
}