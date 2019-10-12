#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 10001

using namespace std;

vector<int> v[MAXN];
vector<int> res;
bool visited[MAXN];
int N, M;
int ans = 0;
int sum;

void dfs(int idx) {
	visited[idx] = true;
	
	for (int i = 0; i < v[idx].size(); i++) {
		int next = v[idx][i];
		if (!visited[next]) {
			sum++;
			dfs(v[idx][i]);
		}
		
	}
}
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
	for (int i = 1; i <= N; i++) {
		
		memset(visited, false, sizeof(visited));
		sum = 0;
		dfs(i);
		if (ans == sum) {
			res.push_back(i);
		}
			
		if (ans < sum) {
			ans = sum;
			res.clear();
			res.push_back(i);
		}
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) {
		
		cout << res[i] << " ";
		
	}
	cout << "\n";
	return 0;
}