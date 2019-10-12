#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int x;
	int y;
	int num;
	int dir;
};
bool compare(node a, node b) {
	if (a.num > b.num) return true;
	return false;
}
int N, M, K;
int map[101][101];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int test_case=1; test_case<=t; test_case++){
		cin >> N >> M >> K;
		queue<node> q;
		vector<node> v[101][101];
		for (int i = 0; i < K; i++) {
			int tmp_x, tmp_y, tmp_num, tmp_dir;
			cin >> tmp_x >> tmp_y >> tmp_num >> tmp_dir;
			tmp_dir--;
			q.push({ tmp_x,tmp_y,tmp_num,tmp_dir });
		}
		while (M--) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					v[i][j].clear();
				}
			}
			int q_size = q.size();
			while (q_size--) {
				int x = q.front().x;
				int y = q.front().y;
				int cur_dir = q.front().dir;
				int cur_num = q.front().num;
				q.pop();
				int nx = x + dx[cur_dir];
				int ny = y + dy[cur_dir];
				if (nx == 0 || ny == 0 || nx == N - 1 || ny == N - 1) {
					if (cur_num/2 > 0){
						if (cur_dir == 2) cur_dir++;
						else if (cur_dir == 3) cur_dir--;
						else if (cur_dir == 1) cur_dir--;
						else cur_dir++;
					
						v[nx][ny].push_back({ nx,ny,cur_num / 2,cur_dir });
					}
				
				}
				else {
					v[nx][ny].push_back({ nx,ny,cur_num,cur_dir });
				}
			
			}
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (v[i][j].size() == 0) continue;
				
					else if (v[i][j].size() == 1) {
						q.push(v[i][j][0]);
					}
					else if (v[i][j].size() > 1) {
						sort(v[i][j].begin(), v[i][j].end(),compare);
						int d = v[i][j][0].dir;
						int len = v[i][j].size();
						int num = 0;
						for (int k =0 ;k < len; k++){
							num += v[i][j][k].num;
						}
						q.push({ i,j,num,d });
					}
				}
			}
		}
		int ans = 0;
		while (!q.empty()) {
			ans += q.front().num;
			q.pop();
		}
		cout << "#"<<test_case<<" "<<ans << "\n";
	}
	return 0;
}