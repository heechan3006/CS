#include <iostream>
#define MAXN 1000000 + 1

using namespace std;
int parent[MAXN];
int N, M;

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) parent[b] = a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int x, a, b;
		cin >> x >> a >> b;
		if (x == 0) {
			Union(a, b);
		}
		else {
			if (find(a) != find(b)) cout << "NO\n";
			else cout << "YES\n";
		}
	}
	return 0;
}