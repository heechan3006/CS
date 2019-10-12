#include <iostream>
#include <cstring>
using namespace std;

int map[100];
long long D[100][21];
int N;
long long dp(int now, int sum) {
	
	if (sum < 0 || sum > 20) return 0;
	if (now == N - 2) return sum == map[N-1];
	if (D[now][sum] != -1) return D[now][sum];
	D[now][sum] = 0;
	D[now][sum] += dp(now + 1, sum + map[now + 1]) + dp(now + 1, sum - map[now + 1]);
	return D[now][sum];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	memset(D, -1, sizeof(D));
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	long long ans = dp(0, map[0]);
	cout << ans << "\n";
}