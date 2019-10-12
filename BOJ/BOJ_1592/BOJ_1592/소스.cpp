#include <iostream>
#include <cstring>
#define MAXN 1000
using namespace std;
int map[MAXN];
int num[MAXN];

int N, M, L;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> L;
	int idx = 0;
	int ans = 0;
	num[0] = 1;
	while (1) {
		if (num[idx] == M) break;
		if (num[idx] % 2 == 0) {
			idx = (N + (idx - L)) % N;
		}
		else {
			idx = (idx + L) % N;	
		}
		num[idx]++;
		ans++;
	}
	cout << ans << "\n";
	return 0;
}