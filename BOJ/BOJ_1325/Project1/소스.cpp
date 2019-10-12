#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 10001

using namespace std;

vector<int> v[MAXN];

int visited[MAXN];
int res[MAXN];
int N, M;
int ans = 0;
int sum;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int tmp_x, tmp_y;
		cin >> tmp_x >> tmp_y;
		v[tmp_y].push_back(tmp_x);
	}
	memset(visited, -1, sizeof(visited));
	for (int i = 1; i <= N; i++) {
		int root = i;
		if (visited[i] == root) continue;
		queue<int> q;
		q.push(i);
		visited[i] = root;
		res[root]++;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < v[now].size(); i++) {
				int next = v[now][i];
				if (visited[next] == root) continue;
				q.push(next);
				visited[i] = root;
				res[root]++;
			}
		}
		
	}
	for (int i = 0; i <= N; i++) {
		if (res[i] > ans) ans = res[i];
	}
	for (int i = 1; i <= N; i++) {

		if (res[i] == ans) {
			cout << i << " ";
		}

	}
	cout << "\n";
	return 0;
}