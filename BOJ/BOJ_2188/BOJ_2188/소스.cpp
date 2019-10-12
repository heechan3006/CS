#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
bool adj[201][201];

vector<int> aMatch, bMatch;

bool visited[201];
bool dfs(int a) {
	if (visited[a]) return false;
	visited[a] = true;
	for (int b = 0; b < M; b++) {
		if (adj[a][b]) {
			if (bMatch[b] == -1 || dfs(bMatch[b])) {
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			int num;
			cin >> num;
			num--;
			adj[i][num] = 1;
		}
	}
	aMatch = vector<int>(N, -1);
	bMatch = vector<int>(M, -1);
	int size = 0;
	for (int start = 0; start < N; start++) {
		memset(visited, false, sizeof(visited));
		if (dfs(start)) {
			size++;
		}
	}
	cout << size << "\n";
	return 0;
}