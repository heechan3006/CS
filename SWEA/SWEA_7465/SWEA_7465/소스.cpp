#include <iostream>
#include <cstring>
#define MAXN 101
using namespace std;

int map[MAXN];

int N, M;
int find(int n) {
	if (map[n] < 0) return n;
	return map[n] = find(map[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	map[b] = a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int test_case=1; test_case<=t; test_case++){
		memset(map, -1, sizeof(map));
		
		cin >> N >> M;
		int tmp_1, tmp_2;
		for (int i = 0; i < M; i++) {
			cin >> tmp_1 >> tmp_2;
			merge(tmp_1 - 1, tmp_2 - 1);
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (map[i] < 0) ans++;
		}
		cout << "#" << test_case<<" " <<ans << "\n";
	}
	return 0;
}