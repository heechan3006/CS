//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 100
using namespace std;

int r, c, k;
int map[MAXN][MAXN];
int num[MAXN+1];
int copy_map[MAXN][MAXN];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> r >> c >> k;
	r--;
	c--;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	if (map[r][c] == k) {
		cout << 0 << "\n";
		return 0;
	}
	int ans = 0;
	while (1) {
		vector<pair<int, int>> v;
		if (ans > 100) {
			cout << -1 << "\n";
			return 0;
		}
		if (map[r][c] == k) {
			cout << ans << "\n";
			return 0;
		}
		int len_r = 0;
		int len_c = 0;
		int cnt = 0;
		bool flag = false;
		for (int i = 0; i < MAXN; i++) {
			cnt = 0;
			for (int j = 0; j < MAXN; j++) {
				if (j == 0 && map[i][j] == 0) {
					flag = true;
					break;
				}
				if (map[i][j] == 0) break;
				cnt++;
			}
			if (flag) break;
			if (len_c < cnt) len_c = cnt;
		}
		flag = false;
		for (int j = 0; j < MAXN; j++) {
			cnt = 0;
			for (int i = 0; i < MAXN; i++) {
				if (i == 0 && map[i][j] == 0) {
					flag = true;
					break;
				}
				if (map[i][j] == 0) break;
				cnt++;
			}
			if (flag) break;
			if (len_r < cnt) len_r = cnt;
		}
		if (len_r >= len_c) {
			for (int i = 0; i < len_r; i++) {
				memset(num, 0, sizeof(num));
				v.clear();
				for (int j = 0; j < len_c; j++) {
					if (map[i][j] == 0) continue;
					
					num[map[i][j]]++;
					map[i][j] = 0;
				}
				for (int j = 1; j <= MAXN; j++) {
					if (num[j] > 0) {
						v.push_back({ num[j],j });
					}
				}
				sort(v.begin(), v.end());
				int idx = 0;
				for (int j = 0; j < min((int)v.size(),MAXN/2); j++) {
					map[i][idx] = v[j].second;
					map[i][idx + 1] = v[j].first;
					idx += 2;
				}
			}
			
		}
		else {
			for (int j = 0; j < len_c; j++) {
				memset(num, 0, sizeof(num));
				v.clear();
				for (int i = 0; i < len_r; i++) {
					if (map[i][j] == 0) continue;
					
					num[map[i][j]]++;
					map[i][j] = 0;
				}
				for (int i = 1; i <= MAXN; i++) {
					if (num[i] > 0) {
						v.push_back({ num[i],i });
					}
				}
				sort(v.begin(), v.end());
				int idx = 0;
				for (int i = 0; i < min((int)v.size(),MAXN/2); i ++) {
					map[idx][j] = v[i].second;
					map[idx+1][j] = v[i].first;
					idx += 2;
				}
			}
		}
		ans++;
	}

}