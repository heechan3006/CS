#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int s[20][20];
int n;
int ans = 987654321;
vector<int> first, second;
int dfs(int index) {
	if (index >= n) {
		if (first.size() == second.size()) {
			int t1 = 0;
			int t2 = 0;
			for (int i = 0; i < first.size(); i++) {
				for (int j = i + 1; j < first.size(); j++) {
					t1 += s[first[i]][first[j]] + s[first[j]][first[i]];
				}
			}
			for (int i = 0; i < second.size(); i++) {
				for (int j = i + 1; j < second.size(); j++) {
					t2 += s[second[i]][second[j]] + s[second[j]][second[i]];
				}
			}
			ans = min(ans, abs(t1 - t2));
		}
		return 0;
	}

	first.push_back(index);
	dfs(index + 1);
	first.pop_back();

	second.push_back(index);
	dfs(index + 1);
	second.pop_back();
	return 0;
}
int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	
	dfs(0);
	cout << ans << '\n';
}