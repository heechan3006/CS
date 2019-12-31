#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	int N, M;
	while (t--) {
		cin >> N >> M;
		if (N < 12 || M < 4) {
			printf("-1\n");
			continue;
		}
		printf("%d\n", 11 * M + 4);
	}
	return 0;
}