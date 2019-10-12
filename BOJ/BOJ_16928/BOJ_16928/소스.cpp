#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 101
int N, M;
int ladder[MAXN];
int dist[MAXN];

int main() {
	cin >> N >> M;
	
	for (int i = 1; i < MAXN; i++) {
		dist[i] = 98765432;
	}
	int tmp_x, tmp_y;
	for (int i = 0; i < N; i++) {
		cin >> tmp_x >> tmp_y;
		ladder[tmp_x] = tmp_y;
	}
	int tmp_u, tmp_v;
	for (int i = 0; i < M; i++) {
		cin >> tmp_u >> tmp_v;
		ladder[tmp_u] = tmp_v;
	}
	queue<pair<int,int>> q;
	q.push({ 1 ,0});
	dist[1] = 0;
	while (!q.empty()) {
		int curr = q.front().first;
		int cnt = q.front().second;
		
		q.pop();
		if (ladder[curr] != 0) {
			int next = ladder[curr];
			q.push({ next,cnt });
			continue;
		}
		for (int k = 1; k <= 6; k++) {
			int next = curr + k;
			int next_cnt = cnt + 1;
			if (next > MAXN-1) continue;
			if (next_cnt < dist[next]) {
				dist[next] = next_cnt;
				q.push({ next,next_cnt });
			}
			
		}
	}
	printf("%d\n", dist[MAXN - 1]);
}
