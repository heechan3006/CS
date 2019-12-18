#include <iostream>
#include <algorithm>
const int MAXN = 1001;
using namespace std;

int arr[MAXN];
int D1[MAXN];
int D2[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		int sum1 = 0;
		for (int j = 1; j <= i; j++) {
			if (arr[i] > arr[j]) {
				sum1 = max(sum1, D1[j]);
			}
		}
		D1[i] = sum1 + 1;
	}
	for (int i = N; i >= 1; i--) {
		int sum2 = 0;
		for (int j = N; j >= i; j--) {
			if (arr[i] > arr[j]) {
				sum2 = max(sum2, D2[j]);
			}
		}
		D2[i] = sum2 + 1;
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, D1[i] + D2[i] - 1);
	}
	cout << ans << "\n";
	return 0;
}