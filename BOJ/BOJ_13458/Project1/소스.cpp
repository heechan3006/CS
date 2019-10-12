#include <iostream>
#include <algorithm>
#include <math.h>
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
		int remain = A[i] - B;
		ans++;
		if (remain>0){
		ans += (int)(ceil(double(remain) / double(C)));
		}

	}
	cout << ans << "\n";
	return 0;
}