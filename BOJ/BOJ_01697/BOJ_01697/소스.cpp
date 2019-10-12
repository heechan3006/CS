#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 200000
int N, K;
bool check[MAXN];
int dist[MAXN];

int main() {
	cin >> N >> K;
	queue<int> q;
	q.push(N);
	dist[N] = 0;
	check[N] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now - 1 >= 0) {
			if (check[now - 1] == false) {
				check[now - 1] = true;
				dist[now - 1] = dist[now] + 1;
				q.push(now - 1);
			}
		}

		if (now + 1 < MAXN) {
			if (check[now + 1] == false) {
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
				q.push(now + 1);
			}
		}

		if (now * 2 < MAXN) {
			if (check[now * 2] == false) {
				check[now * 2] = true;
				dist[now * 2] = dist[now] + 1;
				q.push(now * 2);
			}
		}
	}
	printf("%d", dist[K]);

}