#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 200000

int N, K;

bool check[MAXN];
int dist[MAXN];

int main() {
	cin >> N >> K;
	queue<int> q;
	queue<int> next_queue;
	q.push(N);
	dist[N] = 0;
	check[N] = true;
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now * 2 < MAXN) {
			if (check[now * 2] == false) {
				dist[now * 2] = dist[now];
				check[now * 2] = true;
				q.push(now * 2);
			}
		}
		if (now - 1 >= 0) {
			if (check[now - 1] == false) {
				dist[now - 1] = dist[now] + 1;
				check[now - 1] = true;
				next_queue.push(now - 1);
			}
		}

		if (now + 1 < MAXN) {
			if (check[now + 1] == false) {
				dist[now + 1] = dist[now] + 1;
				check[now + 1] = true;
				next_queue.push(now + 1);
			}
		}
		if (q.empty()) {
			q = next_queue;
			next_queue = queue<int> ();
		}

		
	}
	printf("%d", dist[K]);
}
