#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int A[11];
int ans_min,ans_max;
vector<int> v;
int calculate(int a, int op, int b) {
	if (op == 1) {
		return a + b;
	}
	else if (op == 2) {
		return a - b;
	}
	else if (op == 3) {
		return a * b;
	}
	else {
		return a / b;
	}
	return -1;
}
void solve() {
	int sum = A[0];
	for (int i = 0; i < N-1; i++) {
		sum = calculate(sum, v[i], A[i+1]);
	}
	
	if (ans_min > sum) ans_min = sum;
	if (ans_max < sum) ans_max = sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		
	}
	
	for (int i = 1; i <= 4; i++) {
		cin >> tmp;
		while (tmp--) {
			v.push_back(i);
		}
	}
	ans_min = 1e10;
	ans_max = -1e10;
	sort(v.begin(), v.end());
	do {
		solve();
		
	} while (next_permutation(v.begin(), v.end()));
	cout << ans_max << "\n";
	cout << ans_min << "\n";
}