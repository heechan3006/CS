#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 40000+1
int N,K;
pair<int, int> depth[MAXN];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int x, y, x1, y1;
	cin >> x >> y;
	for (int i = 0; i < N / 2 - 1; i++) {
		cin >> x >> y >> x1 >> y1;
		for (int j = x; j < x1; j++) {
			depth[j].first = y;
		}
	}
	cin >> x >> y;
	int row = x;
	cin >> K;
	vector<int> hole;
	for (int i = 0; i < K; i++) {
		cin >> x >> y >> x1 >> y1;
		hole.push_back(x);
	}
	for (int i = 0; i < hole.size(); i++) {
		x = hole[i];
		int height = depth[x].first;
		depth[x].second = height;
		// ¿ÞÂÊ
		for (int j = x - 1; j >= 0; j--) {
			height = min(height, depth[j].first);
			depth[j].second = max(depth[j].second, height);
		}
		// ¿À¸¥ÂÊ
		height = depth[x].first;
		for (int j = x + 1; j < row; j++) {
			height = min(height, depth[j].first);
			depth[j].second = max(depth[j].second, height);
		}
	}
	int res = 0;
	for (int i = 0; i < row; i++) {
		res += depth[i].first - depth[i].second;
	}
	cout << res << "\n";
	return 0;
}
