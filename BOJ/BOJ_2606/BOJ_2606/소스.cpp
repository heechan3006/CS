#include <iostream>

using namespace std;

int group[101];
int N, M;
int find(int x) {
	if (group[x] == x) return x;
	return group[x] = find(group[x]);
}
void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) group[b] = a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		group[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		Union(u, v);
	}
	int ans = 0;
	for (int i = 2; i <= N; i++) {
		if (find(1) == find(i)) ans++;
	}
	cout << ans << "\n";
	return 0;
}