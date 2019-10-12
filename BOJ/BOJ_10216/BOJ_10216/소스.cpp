#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAXN 3001

using namespace std;

int N;

struct node {
	pair<int, int> coord;
	int r;
};
node map[MAXN];
int parent[MAXN];
int ans;
int dist(pair<int, int> a, pair<int, int> b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
int find(int x) {
	if (parent[x] == -1) return x;
	return parent[x] = find(parent[x]);
}
void merge(int i, int j) {
	i = find(i);
	j = find(j);
	if (i == j) return;
	parent[i] = j;
}
int main() {
	
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &N);
		memset(parent, -1, sizeof(parent));
		for (int i = 0; i < N; i++) {
			scanf("%d%d%d", &map[i].coord.first, &map[i].coord.second, &map[i].r);
		}
		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				int d = dist(map[i].coord, map[j].coord);
				if (d <= (map[i].r + map[j].r)*(map[i].r+map[j].r)) {
					merge(i, j);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (parent[i] == -1) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}