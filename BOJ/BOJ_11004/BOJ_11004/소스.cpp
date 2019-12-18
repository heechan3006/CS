#include <iostream>
#include <algorithm>
const int MAXN = 5e6;
using namespace std;
int num[MAXN];
int N, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	cout << num[K - 1] << "\n";
	return 0;
}