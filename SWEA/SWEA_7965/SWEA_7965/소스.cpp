#include <iostream>
#define MOD 1000000007
#define MAXN 1000001
typedef unsigned long long ll;
using namespace std;

ll cache[MAXN];
ll power(ll k) {
	ll res = 1;
	ll n = k;
	while (n) {
		if (n & 1) {
			res *= k;
		}
		k *= k;
		n >>= 1;
		k %= MOD;
		res %= MOD;
	}
	return res;
}
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cache[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		cache[i] = (cache[i - 1] + power(i)) % MOD;
	}
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		cin >> N;
		cout << "#"<<test_case<<" "<<cache[N] << "\n";
	}
	return 0;
}