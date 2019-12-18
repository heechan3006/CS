#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int> > v[4];
vector<pair<int, int> > path[3] = { {{21,13},{22,16},{23,19},{24,25},{30,30},{31,35},{20,40}},
									{{28,22},{29,24},{24,25},{30,30},{31,35},{20,40}},
									{{27,28},{26,27},{25,26},{24,25},{30,30},{31,35},{20,40}} } ;
bool used[33];
struct node {
	int cur_idx;
	int cur_num;
	int path_idx;
};
int dice[10];
node arr[4];
int ans = 0;
void dfs(int now, int score) {
	if (now == 10) {
		if (ans < score) ans = score;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int cur_idx = arr[i].cur_idx;
		int cur_num = arr[i].cur_num;
		int path_idx = arr[i].path_idx;
		if (cur_num == 32) continue;
		int next_idx = cur_idx + dice[now];
		if (next_idx >= v[path_idx].size()) next_idx = v[path_idx].size() - 1;
		int next_num = v[path_idx][next_idx].first;
		int next_score = v[path_idx][next_idx].second;
		if (next_num!= 32 && used[next_num]) continue;
		used[next_num] = true;
		used[cur_num] = false;
		int next_path;
		if (next_num == 5) next_path = 1;
		else if (next_num == 10) next_path = 2;
		else if (next_num == 15) next_path = 3;
		else next_path = path_idx;
		node tmp = arr[i];
		arr[i] = { next_idx,next_num,next_path };
		dfs(now + 1, score + next_score);
		arr[i] = tmp;
		used[next_num] = false;
		used[cur_num] = true;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}
	for (int i = 0; i <= 20; i++) {
		v[0].push_back({ i,2 * i });
		if (i <= 15) {
			v[3].push_back({ i,2 * i});
		}
		if (i <= 10) {
			v[2].push_back({ i,2 * i });
		}
		if (i <= 5) {
			v[1].push_back({ i,2 * i });
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < path[i].size(); j++) {
			v[i + 1].push_back(path[i][j]);
		}
	}
	for (int i = 0; i < 4; i++) {
		v[i].push_back({ 32,0 });
	}
	dfs(0,0);
	cout << ans << "\n";
	return 0;
}