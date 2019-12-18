#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100;
const long long NEGINF = numeric_limits<long long>::min();
int A[MAXN];
int B[MAXN];
int N, M;
int cache[MAXN+1][MAXN+1];
int jlis(int indexA, int indexB) {
	int& ret = cache[indexA+1][indexB+1];
	if (ret != -1) return ret;
	ret = 2;
	long long a = ((indexA == -1) ? NEGINF : A[indexA]);
	long long b = ((indexB == -1) ? NEGINF : B[indexB]);
	long long maxValue = max(a, b);
	
	for (int nextA = indexA + 1; nextA < N; nextA++) {
		if (maxValue < A[nextA]) {
			ret = max(ret, jlis(nextA,indexB) + 1);
		}
	}
	for (int nextB = indexB + 1; nextB < M; nextB++) {
		if (maxValue < B[nextB]) {
			ret = max(ret, jlis(indexA, nextB) + 1);
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> B[i];
		}
		cout << jlis(-1, -1) - 2 <<"\n";
	}
	return 0;
}