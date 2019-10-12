#include <iostream>
#include <tuple>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;
int N;
long long coord[2][1000];
int connect[1001];
long long find_connect(long long a) {
	if (a == connect[a]) return a;
	return connect[a] = find_connect(connect[a]);
}
void Union(long long a, long long b) {
	a = find_connect(a);
	b = find_connect(b);
	if (a == b) return;
	connect[b] = a;
}
long long dist(long long x1, long long y1, long long x2, long long y2) {
	long long d;
	d = ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return d;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++){
		memset(connect, 0, sizeof(connect));
		memset(coord, 0, sizeof(coord));
		scanf("%d", &N);
		for (int i = 0; i < 2; i++){
			for (int j = 0 ; j < N; j++){
				scanf("%llu", &coord[i][j]);
				connect[j] = j;
			}
		}
		double e;
		scanf("%lf", &e);
		vector< tuple<long long, long long, long long>> v;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				v.push_back(make_tuple(dist(coord[0][i], coord[1][i], coord[0][j], coord[1][j]), (long long) i, (long long) j));
			}
		}
		sort(v.begin(), v.end());
		long long ans = 0;
		for (auto it = v.begin(); it != v.end(); it++) {
			long long x = get<1>((*it));
			long long y = get<2>((*it));
			if (find_connect(x) == find_connect(y)) {
				continue;
			}
			ans += get<0>((*it));
			Union(x, y);
		}
		e = ans * e;
		printf("#%d %.0f\n",test_case, e);
	}
}