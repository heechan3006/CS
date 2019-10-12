#include <iostream>

using namespace std;

int D[101];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> N;
		for (int i = 1; i <= N; i++) {
			D[i] = 1;
		}
		for (int i = 2; i <= N; i++) {
			for (int j = i; j <= N; j+=i) {
				D[j] = 1 - D[j];
			}
		}
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (D[i] == 1) ans++;
		}
		cout << ans << "\n";
	}
}