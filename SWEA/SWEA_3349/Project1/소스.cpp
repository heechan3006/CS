#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int W, H, N;

int dx[] = { 0,0,1,-1,-1,1 };
int dy[] = { 1,-1,0,0,-1,1 };
vector<pair<int, int>> v;
int ans = 10e6;
void go(int x, int y, int diff_x, int diff_y, int cnt) {
	int diff = abs(diff_x) + abs(diff_y);
	if (diff == 0){
		if (ans > cnt) ans = cnt;
		return;
	}
	for (int k = 0; k < 6; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 1 || nx > H || ny < 1 || ny > W) continue;
		if (diff <= abs(diff_x - dx[k]) + abs(diff_y - dy[k])) continue;
		go(nx, ny, diff_x - dx[k], diff_y - dy[k],cnt+1);
	}
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {
		scanf("%d %d %d", &W, &H, &N);
		for (int i = 0; i < N; i++) {
			int tmp_x, tmp_y;
			scanf("%d %d", &tmp_y, &tmp_x);
			v.push_back({ tmp_x,tmp_y });
		}
		int sum = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			ans = 10e6;
			//int diff = abs(v[i + 1].first - v[i].first) + abs(v[i + 1].second - v[i].second);
			int diff_x = v[i + 1].first - v[i].first;
			int diff_y = v[i + 1].second - v[i].second;
			go(v[i].first, v[i].second,diff_x,diff_y,0);
			sum += ans;
		}
		printf("#%d %d\n", test_case, sum);
	}
	return 0;
}