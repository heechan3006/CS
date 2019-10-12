#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 100000 + 1
using namespace std;


vector<pair<int, int>> graph[MAXN];
bool visited[MAXN];
int N, M;
long long C;
int A, B;
int S, D;
bool bfs(long long limit) {
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(S);
	visited[S] = true;
	while (!q.empty()) {
		int cur = q.front();
		if (cur == D) return true;
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			long long weight = graph[cur][i].second;
			if (visited[next]) continue;
			if (weight >= limit) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d%lld", &A, &B, &C);
		graph[A].push_back({ B,C });
		graph[B].push_back({ A, C });
	}
	cin >> S >> D;
	long long low = 0;
	long long high = 1e10;
	long long ans = 1e10;
	long long mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (bfs(mid)) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	printf("%lld", high);
	return 0;
}