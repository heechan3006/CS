#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAXN 10001

using namespace std;

vector<pair<int, int>> v[MAXN];
bool visited[MAXN];
int N, M;
int start, last;
bool bfs(int cost) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == last) return true;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int next_w = v[now][i].second;
			if (!visited[next] && next_w >= cost) {
				visited[next] = true;
				q.push(next);
			}
			
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// N : 섬 개수, M : 다리 개수
	cin >> N >> M;
	int max_w = 0;
	for (int i = 0; i < M; i++) {
		int tmp_x, tmp_y, tmp_w;
		cin >> tmp_x >> tmp_y >> tmp_w;
		v[tmp_x].push_back({ tmp_y,tmp_w });
		v[tmp_y].push_back({ tmp_x,tmp_w });
		if (max_w < tmp_w) max_w = tmp_w;
	}
	
	cin >> start >> last;
	int low = 0;
	int high = max_w;
	
	while (low <= high) {
		memset(visited, false, sizeof(visited));
		int mid = (low + high) / 2;
		if (bfs(mid)) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << high << "\n";
	return 0;
}
