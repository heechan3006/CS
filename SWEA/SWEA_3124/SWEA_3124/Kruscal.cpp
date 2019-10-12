#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
int parent[100001];
struct Edge {
	int v;
	int e;
	int weight;
	
	Edge() {}
	Edge(int _v, int _e, int _weight) : v(_v), e(_e),weight(_weight) {}
};
vector<Edge> edge;
bool compare_weight(const Edge& x, const Edge& y) {
	return x.weight < y.weight;
}
int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}
bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	parent[v] = u;
	return true;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case=1; test_case<=t; test_case++){

		scanf("%d%d", &V, &E);
		int tmp_v, tmp_e, tmp_weight;
	
		for (int i = 1; i <= V; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < E; i++) {
			scanf("%d%d%d", &tmp_v, &tmp_e, &tmp_weight);
			edge.push_back(Edge(tmp_v,tmp_e, tmp_weight));
		}
		// 가중치 기준으로 정렬
		long long k = 0LL;
		sort(edge.begin(), edge.end(),compare_weight);
		for (int i = 0; i < E; i++) {
			// cycle 체크
			if (merge(edge[i].v, edge[i].e)) {
				// 최소 가중치 더함.
				k += edge[i].weight;
			}
		}
	
		printf("#%d %lld\n",test_case, k);
		edge.clear();
	}
	return 0;
}