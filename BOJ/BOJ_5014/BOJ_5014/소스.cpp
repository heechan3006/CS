#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1000001
using namespace std;

int map[MAX];
int dist[MAX];
int F, S, G, U, D;

int bfs() {
	queue<int> q;
	q.push(S);
	dist[S] = 1;
	while (!q.empty()) {
		int cur = q.front();
		if (cur == G) return dist[cur] -1;
		q.pop();
		int arr[] = { cur + U,cur - D };
		for (int i = 0; i < 2; i++) {
			int next = arr[i];
			if (next <= 0 || next > F) continue;
			if (!dist[next]) {
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}
	return -1;
}
int main() {
	cin >> F >> S >> G >> U >> D;
	memset(dist, 0, sizeof(dist));
	int ans = bfs();
	if (ans == -1) {
		printf("use the stairs");
	}
	else{
		printf("%d", ans);
	}
}