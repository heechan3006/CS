#include <iostream>
#include <algorithm>
using namespace std;
int L,N;
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> L >> N;
		int ant;
		int value_min = 0;
		int value_max = 0;
		for (int i = 0; i < N; i++) {
			cin >> ant;
			int ant_min = min(ant, L - ant);
			int ant_max = max(ant, L - ant);
			value_min = max(value_min, ant_min);
			value_max = max(value_max, ant_max);
		}
		printf("%d %d\n", value_min, value_max);
	}
	return 0;
}