#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define MAX_N 100001
using namespace std;
int V, E;

typedef pair<int, int> pii;

bool visited[MAX_N];
long long ans = 0LL;
vector<vector<pii>> v;

priority_queue<pii, vector<pii>, greater<pii>> pq;
void prim(int start) {
	visited[start] = true;

	for (auto u: v[start]) {
		if (!visited[u.second])
		pq.push(pii(u.first, u.second));

	}
	while (!pq.empty()) {
		auto w = pq.top();
		pq.pop();
		if (!visited[w.second]) {
			ans += w.first;
			prim(w.second);
			return;
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case=1; test_case <= t; test_case++){
		memset(visited, false, sizeof(visited));
		scanf("%d%d", &V, &E);
		
		v.resize(V + 1);
		int tmp_v1, tmp_v2, tmp_weight;
		for (int i = 0; i < E; i++) {
			scanf("%d%d%d", &tmp_v1, &tmp_v2, &tmp_weight);
			v[tmp_v1].push_back(pii(tmp_weight,tmp_v2));
			v[tmp_v2].push_back(pii(tmp_weight, tmp_v1));
		}
		ans = 0;
		prim(1);
		printf("#%d %lld\n", test_case,ans);
		v.clear();
	}
	return 0;
}