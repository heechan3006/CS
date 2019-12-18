#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 500;
int map[MAXN];
int cache[MAXN];
int N;
int lis(const vector<int>& A) {
	if (A.size() == 0) return 0;
	int ret = 0;
	for (int i = 0; i < A.size(); i++) {
		vector<int> B;
		for (int j = i + 1; j < A.size(); j++) {
			if (A[i] < A[j]) {
				B.push_back(A[j]);
			}
		}
		ret = max(ret, 1 + lis(B));
	}
	return ret;
}
int lis2(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < N; next++) {
		if (map[start] < map[next]) {
			ret = max(ret, lis2(next) + 1);
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
			map[i] = v[i];
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			ans = max(ans,lis2(i));
		}
		cout << ans << "\n";
	}
	return 0;
}
