#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int W[10][10];
int ans = 10e9;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}
	vector<int> v;
	for (int i = 0; i < N; i++) {
		v.push_back(i);
	}
	
	
	do {
		int sum = 0;
		v.insert(v.begin() + N, v[0]);
		bool flag = true;
		for (int i = 0; i < v.size()-1 ; i++) {
			if (!W[v[i]][v[i + 1]]) {
				flag = false;
			}
			sum += W[v[i]][v[i + 1]];
		}
		v.erase(v.begin() + N);
		if (flag){
			if (ans > sum) ans = sum;
		}
	} while (next_permutation(v.begin(), v.end()));
	printf("%d\n", ans);
}