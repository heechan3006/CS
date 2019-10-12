#include <iostream>
#define MAXN 1000000
using namespace std;

int N;
int A[MAXN];
int B, C;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];	
	}
	cin >> B >> C;
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		ans++;
		if (A[i] > 0) {
			if (A[i] % C == 0) {
				ans += A[i] / C;
			}
			else {
				ans += A[i] / C + 1;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}