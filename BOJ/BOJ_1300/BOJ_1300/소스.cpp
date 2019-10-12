#include <iostream>
#include <algorithm>

typedef unsigned long long ll;
using namespace std;
int N;
ll K;
ll ans = 0;
ll order(ll target) {
	ll sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += min(ll(N), target / i);
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	ll low = 0;
	ll high = min(ll(N) * ll(N), K);
	while (low <= high) {
		ll mid = (low + high) / 2;
		if (order(mid) >= K) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}