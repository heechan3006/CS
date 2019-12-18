#include <iostream>
#include <algorithm>
const int MAXN = 1001;

using namespace std;

int arr[MAXN];
int D[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		D[i] = arr[i];
		int sum = 0;
		for (int j = 1; j <= i; j++) {
			if (arr[i] > arr[j]) {
				sum = max(sum, D[j]);
			}
		}
		D[i] = sum + arr[i];
		ans = max(ans, D[i]);
	}
	cout << ans << "\n";
	return 0;
}