#include <iostream>
#include <map>
using namespace std;
#define ll long long
int N;
map<ll, int> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	while (N--) {
		ll tmp;
		cin >> tmp;
		mp[tmp]++;
	}
	ll ans;
	int maxcnt = 0;
	for (map<ll,int>::iterator it = mp.begin(); it != mp.end(); it++) {
		
		if (maxcnt < it->second) {
			ans = it->first;
			maxcnt = it->second;
		}
		else if (maxcnt == it->second && ans > it->first) {
			ans = it->first;
			maxcnt = it->second;
		}
	}
	cout << ans << "\n";
	return 0;
}

