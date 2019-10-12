#include <iostream>
#include <vector>

using namespace std;

int N;

int go(vector<int> &w) {
	int n = w.size();
	if (n == 2) return 0;
	int ans = 0;
	for (int i = 1; i < n - 1; i++) {
		int energy = w[i - 1] * w[i + 1];
		vector<int> b(w);
		b.erase(b.begin() + i);
		energy += go(b);
		if (ans < energy) ans = energy;
	}
	return ans;
}

int main() {
	cin >> N;
	vector<int> W(N);
	for (int i = 0; i < N; i++) {
		cin >> W[i];
	}
	
	cout << go(W) << '\n';
	return 0;
}