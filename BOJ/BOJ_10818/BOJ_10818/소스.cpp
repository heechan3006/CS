#include <iostream>
#define MAXN 1000000
using namespace std;
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int min_v = MAXN;
	int max_v = -MAXN;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (min_v > tmp) min_v = tmp;
		if (max_v < tmp) max_v = tmp;
	}
	cout << min_v << " " << max_v << "\n";
	return 0;
}