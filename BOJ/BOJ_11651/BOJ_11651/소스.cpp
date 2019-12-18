#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 1e6;
pair<int, int> num[MAXN];
int main() {
	int N;
	int x, y;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		num[i] = { y,x };
	}

	sort(num, num + N);
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", num[i].second, num[i].first);
	}
	return 0;
}