#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct person {
	int first;
	int second;
};
struct vec {
	int x;
	
};
int map[10][10];
int N;
int select[10];
int idx;
person P[10];
vector<pair<pair<int, int>,int>> stair;
int ans;
int calc(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
int get_time(vector<vec> &vv, int stair_time) {
	//sort(v.begin(), v.end());
	int used[3] = { 0, };
	int time = vv[0].x;
	while (1) {
		for (int i = 0; i < vv.size(); i++) {
			if (vv[i].x == 0) continue;
			if (vv[i].x <= time){
				for (int j = 0; j < 3; j++) {
					if (used[j] <= 0) {
						used[j] = stair_time;
						vv[i].x = 0;
					}
					if (i == vv.size() - 1) {
						return time + stair_time + 1;
					}

				}
			}
		}
		for (int i = 0; i < 3; i++) {
			used[i]--;
		}
		time++;
	}
}
void dfs(int ind, int cnt) {
	if (ind == idx) {
		vector<vec> A;
		vector<vec> B;
		for (int i = 0; i < idx; i++) {
			if (select[i] == 1) {
				A.push_back({ P[i].first });
			}
			else {
				B.push_back({ P[i].second });
			}
		}
		ans = min(ans,max(get_time(A,stair[0].second), get_time(B,stair[1].second)));
		return;
	}
	select[ind] = 1;
	dfs(ind + 1, cnt + 1);
	select[ind] = 2;
	dfs(ind + 1, cnt + 1);
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] > 1) {
				stair.push_back({ {i,j},map[i][j] });
			}
		}
	}
	idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				int first_d = calc(i, j, stair[0].first.first, stair[0].first.second);
				int second_d = calc(i, j, stair[1].first.first, stair[1].first.second);
				P[idx++] = { first_d,second_d };
			}
		}
	}
	ans = 98765432;
	dfs(0, 0);
	cout << ans << "\n";
}