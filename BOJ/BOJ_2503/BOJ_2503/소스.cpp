#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

bool used[10];
struct node {
	string question;
	int s;
	int b;
};
vector<node> v;
vector<int> baseball;
int N;
int ans = 0;
void dfs(int cnt) {
	if (cnt == 3) {
		bool flag = false;
		for (int i = 0; i < v.size(); i++) {
			string q = v[i].question;
			int s = v[i].s;
			int b = v[i].b;
			int tmp_s = 0;
			int tmp_b = 0;
			for (int j = 0; j < q.length(); j++) {
				int target = q[j] - '0';
				for (int k = 0; k < 3; k++) {
					// strike
					if (baseball[k] == target && j == k) {
						tmp_s++;
						break;
					}
					else if (baseball[k] == target && j != k) {
						tmp_b++;
						break;
					}
				}
			}
			if (tmp_s != s || tmp_b != b) {
				flag = true;
				break;
			}
		}
		if (!flag) ans++;
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (!used[i]) {
			used[i] = true;
			baseball.push_back(i);
			dfs(cnt + 1);
			used[i] = false;
			baseball.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp_q;
		int tmp_s, tmp_b;
		cin >> tmp_q >> tmp_s >> tmp_b;
		v.push_back({ tmp_q,tmp_s,tmp_b });
	}
	dfs(0);
	cout << ans << "\n";
	return 0;
}