#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 1000
#define INF 987654321
using namespace std;

map<int, int> mp;
vector<int> idx;
vector<long long> psum;
int N;
long long total_num = 0;
long long sum = 0;
int ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int val;
			cin >> val;
			if (val) {
				if (!mp.count(val)) {
					idx.push_back(val);
					mp[val] = 1;
				}
				else {
					mp[val] += 1;
				}
			}
			total_num += val;
		}
	}
	sort(idx.begin(), idx.end());
	psum.resize(idx.size(), 0);
	
	sum = 0;
	ans = 1;
	int time = 0;
	long long target = total_num / 2;
	if (total_num % 2 == 1) {
		target += 1;
	}
	long long tmp = total_num;
	if (idx.size() == 1) {
		ans = idx[0] / 2;
		if (idx[0] % 2)ans++;
		cout << ans << "\n";
		return 0;
	}
	for (int i = idx.size() - 1; i >= 1; i--) {

		if (sum + (idx[i] - idx[i - 1])*mp[idx[i]] > target) {
			int low = idx[i - 1];
			int high = idx[i];
			int tmp = sum;
			ans = idx[i];
			while (low <= high) {
				int mid = (low + high) / 2;
				if (tmp + (mid - idx[i - 1])*mp[idx[i]] >= target) {
					ans = mid;
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}
			break;
			
		}
		else if (sum + (idx[i] - idx[i - 1]) * mp[idx[i]] == target) {
			ans = idx[i];
			break;
		}
		
		sum +=  (idx[i] - idx[i - 1])*mp[idx[i]];
	}
	cout << ans << "\n";

	return 0;
}