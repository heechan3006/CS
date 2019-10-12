#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#define MAXN 100 + 1
using namespace std;
int arr[MAXN][MAXN];
bool used[MAXN];
map<string, int> mp;
vector<int> A, B;
int idx;
bool flag;
void dfs(int now) {
	if (flag) return;
	if (now == idx) {
		if (A.size() + B.size() == idx && B.size() != 0) {
			flag = true;
		}
		return;
	}
	if (used[now]) return;
	bool possible = false;
	for (int j = 0; j < A.size(); j++) {
		if (arr[now][A[j]] || A[j] == now) {
			possible = true;
			break;
		}
	}
	if (!possible) {
		used[now] = true;
		A.push_back(now);
		dfs(now + 1);
		used[now] = false;
		A.pop_back();
	}

	possible = false;
	for (int j = 0; j < B.size(); j++) {
		if (arr[now][B[j]] || B[j] == now) {
			possible = true;
			break;
		}
	}
	if (!possible) {
		used[now] = true;
		B.push_back(now);
		dfs(now + 1);
		used[now] = false;
		B.pop_back();
	}
}

int K;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test_case=1; test_case<=t; test_case++){
		flag = false;
		mp.clear();
		A.clear();
		B.clear();
		for (int i = 0; i < MAXN; i++) {
			for (int j = 0; j < MAXN; j++) {
				arr[i][j] = 0;
			}
		}
		memset(used, false, sizeof(used));
		cin >> K;
		idx = 0;
		for (int i = 0; i < K; i++) {
			string a, b;
			cin >> a >> b;
			if (mp.count(a) == 0) {
				mp[a] = idx++;
			}
			if (mp.count(b) == 0) {
				mp[b] = idx++;
			}
			arr[mp[a]][mp[b]] = 1;
			arr[mp[b]][mp[a]] = 1;
		}
		cout << "#" << test_case << " ";
		dfs(0);
		if (flag) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
	
}