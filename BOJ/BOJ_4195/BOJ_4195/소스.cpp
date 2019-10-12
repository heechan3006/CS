#include <iostream>
#include <map>
#define MAXN 200000 + 2

using namespace std;
int parent[MAXN];
int friends[MAXN];
int N;
int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
int Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		parent[b] = a;
		friends[a] += friends[b];
		friends[b] = 1;
	}
	return friends[a];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> N;
		int idx = 1;
		map<string, int> mp;
		for (int i = 1; i <= 2 * N; i++) {
			parent[i] = i;
			friends[i] = 1;
		}
		for (int i = 0; i < N; i++) {
			string a, b;
			cin >> a >> b;
			if (mp.count(a) == 0) {
				mp[a] = idx++;
			}
			if (mp.count(b) == 0) {
				mp[b] = idx++;
			}
			cout << Union(mp[a], mp[b]) << "\n";;
		}
	}
	return 0;
}