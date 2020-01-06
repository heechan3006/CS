#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define MAXN 20

pair<ll,ll> num[MAXN];

int N;
ll ans;
void dfs(int cur, ll x, ll y, int cnt1, int cnt2) {
	if (cur >= N) return;
	
	if (cnt1 < N / 2) {
		dfs(cur + 1, x + num[cur+1].first, y + num[cur+1].second, cnt1 + 1, cnt2);
	}
	if (cnt2 < N / 2) {
		dfs(cur + 1, x - num[cur+1].first, y - num[cur+1].second, cnt1, cnt2 + 1);
	}
	if (cur == N - 1) {
		ll sum = x * x + y * y;
		if (ans > sum) ans = sum;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i].first >> num[i].second;
	}
	ans = 1e11;
	dfs(0, num[0].first,num[0].second,1,0);
	cout << ans << "\n";

}

