#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 101

using namespace std;
int N, M;
vector<int> graph[MAXN];
vector<int> v;
bool visited[MAXN];
int target;
int cnt;
int ans;
int level;
void dfs(int now) {
	if (graph[now].size() == 0) return;
	visited[now] = true;
	for (int i = 0; i < graph[now].size(); i++) {
		if (!visited[graph[now][i]]){
			level++;
			if (i == target) {
				if (cnt > level) {
					cnt = level;
				}
				visited[now] = false;
				level--;
				return;
			}
			dfs(graph[now][i]);
			level--;
		}
	}
	visited[now] = false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	ans = 100 * 100;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			memset(visited, false, sizeof(visited));
			cnt = 100*100;
			level = 0;
			target = j;
			dfs(i);
			sum += cnt;
		}
		if (ans >= sum) {
			if (ans == sum) {
				v.push_back(i);
			}
			else {
				v.clear();
				ans = sum;
				v.push_back(i);
			}
		}
	}
	cout << v[0] << "\n";
	return 0;
}