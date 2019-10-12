#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, S;
vector<int> v;

int main() {
	cin >> N >> S;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int cnt = 1;
	int ans = 0;
	int sum;
	while (cnt <= N){
		vector<int> num(v.size(),0);
		for (int i = 0; i < cnt; i++) {
			num[i] = 1;
		}
		sort(num.begin(), num.end());
		do {
			sum = 0;
			for (int i = 0; i < v.size(); i++) {
				if (num[i]){
					sum += v[i];
				}
			}
			if (sum == S) ans++;
		} while (next_permutation(num.begin(), num.end()));
		cnt++;
	}
	cout << ans << "\n";
	return 0;
}