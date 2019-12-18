#include <iostream>
#include <algorithm>
const int MAXN = 1e5;

using namespace std;

pair<int, int> num[MAXN];
int main() {
	int N;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		num[i] = { v1,v2 };
	}
	sort(num, num + N);
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", num[i].first, num[i].second);
	}
	return 0;
}