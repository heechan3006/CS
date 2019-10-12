#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 102
using namespace std;

vector<int> v[MAXN];
bool visited[MAXN];
int N;
vector<pair<int, int>> coord;
int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
bool flag;
void dfs(int now) {
	if (now == N + 1) {
		flag = true;
		return;
	}
	visited[now] = true;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		for (int i = 0; i < MAXN; i++) {
			v[i].clear();
		}
		memset(visited, false, sizeof(visited));
		coord.clear();
		
		cin >> N;
		for (int i = 0; i < N + 2; i++) {
			int tmp_x, tmp_y;
			cin >> tmp_x >> tmp_y;
			coord.push_back({ tmp_x,tmp_y });
		}
		for (int i = 0; i < N + 2; i++) {
			for (int j = i + 1; j < N + 2; j++) {
				if (dist(coord[i], coord[j]) <= 50 * 20) {
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		flag = false;
		dfs(0);
		if (flag) cout << "happy\n";
		else cout << "sad\n";
	}
	return 0;
}