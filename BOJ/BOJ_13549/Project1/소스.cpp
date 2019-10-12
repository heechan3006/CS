#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

#define MAXN 200000

int N, K;

bool check[MAXN];
int dist[MAXN];

int main() {
	cin >> N >> K;
	deque<int> q;
	q.push_back(N);
	dist[N] = 0;
	check[N] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop_front();
		if (now * 2 < MAXN) {
			if (check[now * 2] == false) {
				dist[now * 2] = dist[now];
				check[now * 2] = true;
				q.push_front(now * 2);
			}
		}
		if (now - 1 >= 0) {
			if (check[now - 1] == false) {
				dist[now - 1] = dist[now] + 1;
				check[now - 1] = true;
				q.push_back(now - 1);
			}
		}

		if (now + 1 < MAXN) {
			if (check[now + 1] == false) {
				dist[now + 1] = dist[now] + 1;
				check[now + 1] = true;
				q.push_back(now + 1);
			}
		}
	}
	printf("%d", dist[K]);
	return 0;
}
