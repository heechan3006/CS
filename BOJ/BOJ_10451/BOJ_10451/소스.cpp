#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N;

bool visited[1001];

void dfs(int now,bool visited[],vector<int> v[]) {
	visited[now] = true;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!visited[next]) {
			dfs(next, visited,v);
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--){
		vector<int> v[1001];
		cin >> N;
		memset(visited, false, sizeof(visited));
		int tmp;
		int idx = 1;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			v[idx].push_back(tmp);
			idx++;
		}
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				dfs(i,visited,v);
				cnt++;
			}
		}
		printf("%d\n", cnt);
		
	}
	return 0;
}