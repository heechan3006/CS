#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define MAXN 5000

using namespace std;

vector<long long> v;
int N;
long long min_v = LLONG_MAX;
int a, b, c;
void check(int now) {
	int j = now + 1;
	int k = N - 1;
	while (j < k) {
		long long sum = v[now] + v[j] + v[k];
		if (llabs(sum) < min_v) {
			min_v = llabs(sum);
			a = now;
			b = j;
			c = k;
		}
		if (sum < 0) j++;
		else k--;
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		check(i);
	}
	cout << v[a] << " "<<v[b] << " "<< v[c];
	return 0;
}
