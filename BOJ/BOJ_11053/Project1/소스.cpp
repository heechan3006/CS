#include <iostream>
#include <algorithm>
#include <vector>
const int MAXN = 1e6 + 1;
const int INF = 987654321;
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	v.push_back(-INF);
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (v.back() < tmp) {
			v.push_back(tmp);
		}
		else {
			vector<int>::iterator it = lower_bound(v.begin(), v.end(), tmp);
			*it = tmp;
		}
	}
	cout << v.size() - 1 << "\n";
	return 0;
}