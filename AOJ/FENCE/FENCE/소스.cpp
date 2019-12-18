#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& v, int left, int right) {
	if (left == right) {
		return v[left];
	}
	int mid = (left + right) / 2;
	int ret = max(solve(v,left, mid), solve(v,mid+1, right));
	int low = mid;
	int high = mid + 1;
	int height = min(v[low], v[high]);
	ret = max(ret, 2 * height);
	while (left < low || high < right) {
		if (high < right && (low == left || v[low - 1] < v[high + 1])) {
			high++;
			height = min(height, v[high]);
		}
		else {
			low--;
			height = min(height, v[low]);
		}
		ret = max(ret, height*(high - low + 1));
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;
		vector<int> v(N, 0);
		for (int j = 0; j < N; j++) {
			cin >> v[j];
		}
		cout << solve(v, 0, v.size() - 1) << "\n";
	}
	return 0;
}
