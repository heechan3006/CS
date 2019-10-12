#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;
int used[14];
int N, M;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
int ans;
int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
void dfs(int now, int cnt) {
	if (cnt == M) {
		vector<pair<int, int>> tmp;
		for (int i = 0; i < chicken.size(); i++) {
			if (used[i]) {
				tmp.push_back(chicken[i]);
			}
		}
		int sum = 0;
		for (int i = 0; i < home.size(); i++) {
			int d = INF;
			for (int j = 0; j < tmp.size(); j++) {
				d = min(d, dist(home[i], tmp[j]));
			}
			sum += d;
		}
		if (ans > sum) ans = sum;
		return;
	}
	for (int i = now; i < chicken.size(); i++) {
		if (!used[i]) {
			used[i] = true;
			dfs(i+1,cnt + 1);
			used[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1) {
				home.push_back({ i,j });
			}
			else if (tmp == 2) {
				chicken.push_back({ i,j });
			}
		}
	}
	ans = INF;
	dfs(0,0);
	cout << ans << "\n";
	return 0;
}

