#include <iostream>

using namespace std;

int N, m, M, T, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> m >> M >> T >> R;
	
	int cnt = 0;
	int time = 0;
	int start = m;
	while (cnt < N) {
		time++;
		if (start + T <= M) {
			start += T;
			cnt++;
			
		}
		else {
			start -= R;
			if (start < m) start = m;
			
		}
		if (start + T > M && start == m) {
			cout << -1 << "\n";
			return 0;
		}
	}
	cout << time << "\n";
	return 0;
}