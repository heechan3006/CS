#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N;
vector<int> v[101];
bool visited[101][101];
void dfs(int x,int y) {
	if (!v[y].size()) return;
	for (int i = 0; i < v[y].size(); i++){
		if (!visited[x][v[y][i]]) {
			visited[x][v[y][i]] = true;
			dfs(x,v[y][i]);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			if (tmp) v[i].push_back(j);
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++) {
		if (!v[i].size()) continue;
		dfs(i,i);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}