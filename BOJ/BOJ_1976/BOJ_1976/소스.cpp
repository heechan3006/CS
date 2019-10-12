#include <iostream>
#include <vector>
#define MAXN 200 + 1
using namespace std;

int N, M;
int graph[MAXN];
int Find(int a) {
	if (graph[a] == a) return a;
	return graph[a] = Find(graph[a]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	graph[b] = a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		graph[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;
			if (tmp==1) {
				if (Find(i) != Find(j)) {
					Union(i, j);
				}
			}
		}
	}
	int tmp;


	cin >> tmp;
	int target = Find(tmp);
	for (int i = 1; i < M; i++) {
		int tmp;
		cin >> tmp;
		if (target != Find(tmp)) {
			cout << "NO\n";
			return 0;
		}
	}
	
	cout << "YES\n";
	return 0;
}