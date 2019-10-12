#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N, M;


int main() {
	int t;
	scanf("%d", &t);
	while (t--){
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			q.push({ tmp,i });
			pq.push(tmp);
		}
		int cnt = 1;
		while (!pq.empty()) {
			pair<int,int> n1 = q.front();
			int n2 = pq.top();
			if (n1.first == n2) {
				if (n1.second == M) {
					printf("%d\n", cnt);
					break;
				}
				pq.pop();
				cnt++;
			}
			else {
				q.push(n1);
			}
			q.pop();
		
		}
	}
}