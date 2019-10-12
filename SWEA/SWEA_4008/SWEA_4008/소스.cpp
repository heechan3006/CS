#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int N;
int op[4];
int number[12];
int min_v;
int max_v;
vector<int> v;
int calc(int a, int b, int op) {
	if (op == 1) return a + b;
	else if (op == 2) return a - b;
	else if (op == 3) return a * b;
	else return a / b;
}
int get_result() {
	int sum = number[0];
	int sum_1 = 0;
	for (int i = 0; i < N - 1; i++) {
		sum_1 = calc(sum, number[i + 1], v[i]);
		sum = sum_1;
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int test_case=1; test_case<=t; test_case++){
		v.clear();
		cin >> N;
		for (int i = 0; i < 4; i++) {
			cin >> op[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> number[i];
		}
	
		for (int i = 0; i < 4; i++) {
			while (op[i]--) {
				v.push_back(i + 1);
			}
		}
		min_v = INF;
		max_v = -INF;
		sort(v.begin(), v.end());
		do {
			int sum = get_result();
			if (min_v > sum) min_v = sum;
			if (max_v < sum) max_v = sum;
		} while (next_permutation(v.begin(), v.end()));
		cout << "#" << test_case << " "<< max_v - min_v << "\n";
	}
	return 0;
}