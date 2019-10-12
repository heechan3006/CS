#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 100
using namespace std;

bool visited_l[MAXN];
bool visited_h[MAXN];
int N, M;
int result[MAXN];
int ans;
vector<int> light[MAXN];
vector<int> heavy[MAXN];
int dfs_l(int now) {
	int ret = 1;
	for (int i = 0; i < light[now].size(); i++) {
		int next = light[now][i];
		if (visited_l[next]) continue;
		visited_l[next] = true;
		ret += dfs_l(next);
	}
	return ret;
}
int dfs_h(int now) {
	int ret = 1;
	for (int i = 0; i < heavy[now].size(); i++) {
		int next = heavy[now][i];
		if (visited_h[next]) continue;
		visited_h[next] = true;
		ret += dfs_h(next);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int tmp_l, tmp_h;
		cin >> tmp_h >> tmp_l;
		heavy[tmp_h].push_back(tmp_l);
		light[tmp_l].push_back(tmp_h);
	}
	ans = 0;
	for (int i = 1; i <= N; i++) {
		memset(visited_l, false, sizeof(visited_l));
		memset(visited_h, false, sizeof(visited_h));
		visited_l[i] = true;
		visited_h[i] = true;
		if (dfs_l(i) > (N + 1) / 2) {
			ans++;
		}
		else if (dfs_h(i) > (N + 1) / 2) {
			ans++;
		}
		
	}
	cout << ans << "\n";
	return 0;
}