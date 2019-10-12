#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 98765432
using namespace std;

int N;
int T[20];
int P[20];
int D[20];

int dp(int day) {
	if (day == N + 1) { return 0; }
	if (day > N + 1) return -INF;
	int& result = D[day];
	if (result != -1) {
		return result;
	}
	result = 0;
	result += max(P[day] + dp(day + T[day]), dp(day + 1));
	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	memset(D, -1, sizeof(D));
	cout <<dp(1)<<"\n";
	
}