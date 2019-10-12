#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX_N 100001
using namespace std;

int parent[MAX_N];
bool visited[MAX_N];
int N;
vector<int> node[MAX_N];
void dfs(int now) {
	visited[now] = true;
	for (int i = 0; i < node[now].size(); i++) {
		int next = node[now][i];
		if (!visited[next]){
			parent[next] = now;
			dfs(next);
		}
		
	}
}
int main() {
	scanf("%d", &N);
	int u, v;
	
	for (int i = 0; i < N-1; i++) {
		scanf("%d%d", &u, &v);
		node[u].push_back(v);
		node[v].push_back(u);
	}
	dfs(1);
	for (int i = 2; i <= N; i++) {
		printf("%d\n", parent[i]);
	}
	return 0;

}