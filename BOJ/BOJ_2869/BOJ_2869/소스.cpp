#include <iostream>
#include <algorithm>
#define MAXN 1e9
using namespace std;
long long A, B, V;
bool check(long long x) {
	if ((x - 1) * (A - B) + A >= V) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> A >> B >> V;
	long long low = 0;
	long long high = MAXN;
	long long ans = MAXN;
	while (low <= high) {
		long long mid = (low + high) / 2;
		if (check(mid)) {
			high = mid - 1;
			ans = min(ans, mid);
		}
		else {
			low = mid + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
