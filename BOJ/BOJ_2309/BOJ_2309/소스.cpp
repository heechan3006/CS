#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<int> num(9,0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 9; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 7; i++) {
		num[i] = 1;
	}
	sort(num.begin(), num.end());
	int sum;
	
	do {
		sum = 0;
		for (int i = 0; i < v.size(); i++) {
			if (num[i]) {
				sum += v[i];
			}
		}
		if (sum == 100) break;
	} while (next_permutation(num.begin(), num.end()));
	
	for (int i = 0; i < v.size(); i++) {
		if (num[i]) {
			cout << v[i] << "\n";
		}
	}
	return 0;
}
