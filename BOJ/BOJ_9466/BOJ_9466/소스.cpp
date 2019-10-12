#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int N;
bool visited[100001];
bool done[100001];
int node[100001];
int cnt;
void dfs(int now) {
	visited[now] = true;
	int next = node[now];
	if (!visited[next]) {
		dfs(next);
	}
	else if (!done[next]) {
		for (int i = next; i != now; i = node[i]) {
			cnt++;
		}
		cnt++;
	}
	done[now] = true;
}
int main() {
	int t;
	cin >> t;
	while (t--){
		cin >> N;
		memset(visited, false, sizeof(visited));
		memset(done, false, sizeof(done));
		for (int i = 1; i <= N; i++) {
			cin >> node[i];
		}
		cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]){
		
			dfs(i);
			}
		
		}
		printf("%d\n", N-cnt);
	}
	return 0;
}