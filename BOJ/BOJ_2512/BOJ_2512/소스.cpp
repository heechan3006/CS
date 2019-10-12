#include <iostream>
#include <algorithm>
#define MAXM 1000000000
#define MAXN 10000
using namespace std;
typedef unsigned long long ll;
int N, M;
ll map[MAXN];
ll ans = 0;
ll max_v = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		max_v = max(max_v, map[i]);
		sum += map[i];
	}
	cin >> M;
	if (sum <= M) {
		cout << max_v << "\n";
		return 0;
	}
	ll low = 0;
	ll high = MAXM;
	while (low <= high) {
		ll mid = (low + high) / 2;
		ll sum = 0;
		for (int i = 0; i < N; i++) {
			if (mid >= map[i]) {
				sum += map[i];
			}
			else {
				sum += mid;
			}
		}
		if (sum <= M) {
			low = mid + 1;
			ans = max(ans, mid);
		}
		else {
			high = mid - 1;
		}
	}
	cout << ans << "\n";
	return 0;
}