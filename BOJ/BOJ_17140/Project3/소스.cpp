#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 100
using namespace std;
int map[MAXN][MAXN];

int r, c, k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c >> k;
	r--;
	c--;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	/*
	if (map[r][c] == k) {
		cout << "0\n";
		return 0;
	}*/
	int time = 0;
	while (1) {
		bool flag = false;
		int max_r = 0;
		int max_c = 0;
		if (map[r][c] == k) {
			cout << time << "\n";
			break;
		}
		if (time >= 100) {
			cout << "-1\n";
			break;
		}
		for (int i = 0; (i < MAXN)&&!flag; i++) {
			for (int j = 0; j < MAXN; j++) {
				if (j == 0 && map[i][j] == 0) {
					flag = true;
					break;
				}
				if (map[i][j] == 0) {
					max_c = max(max_c, j);
					break;
				}
			}
		}
		flag = false;
		for (int j = 0; (j < MAXN) && !flag; j++) {
			for (int i = 0; i < MAXN; i++) {
				if (i == 0 && map[i][j] == 0) {
					flag = true;
					break;
				}
				if (map[i][j] == 0) {
					max_r = max(max_r, i);
					break;
				}
			}
		}
		// R ¿¬»ê
		if (max_r >= max_c) {
			
			for (int i = 0; i < max_r; i++) {
				int max_v = 0;
				int num[MAXN + 1] = { 0, };
				for (int j = 0; j < max_c; j++) {
					
					num[map[i][j]]++;
					max_v = max(max_v, map[i][j]);
					map[i][j] = 0;
				}
				vector<pair<int, int> > v;
				for (int j = 1; j <= max_v; j++) {
					if (num[j] == 0) continue;
					v.push_back({ num[j],j });
				}
				sort(v.begin(), v.end());
				int idx = 0;
				for (int j = 0; j < min((int)v.size(),MAXN/2); j++) {
					map[i][idx++] = v[j].second;
					map[i][idx++] = v[j].first;
				}
			}
		}
		else {
			
			for (int j = 0; j < max_c; j++) {
				int max_v = 0;
				int num[MAXN + 1] = { 0, };
				for (int i = 0; i < max_r; i++) {
					
					num[map[i][j]]++;
					max_v = max(max_v, map[i][j]);
					map[i][j] = 0;
				}
				vector<pair<int, int> > v;
				for (int i = 1; i <= max_v; i++) {
					if (num[i] == 0) continue;
					v.push_back({ num[i],i });
				}
				sort(v.begin(), v.end());
				int idx = 0;
				for (int i = 0; i < min((int)v.size(),MAXN/2); i++) {
					map[idx++][j] = v[i].second;
					map[idx++][j] = v[i].first;
				}
			}
		}
		time++;
	}
	return 0;
}