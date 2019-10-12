#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[16][15];
int copy_map[16][15];
int N, M, D;
int kill_point ;
int ans = 0;
queue<pair<int, int>> q;
struct node {
	int d;
	int y;
	int x;
};

bool compare(node a, node b) {
	if (a.d <= b.d) {
		if (a.d == b.d) {
			if (a.y < b.y) {
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}
int check(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

void attack(int idx, int cnt, vector<node> v[]) {
	int bow_x = N;
	int bow_y = idx;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copy_map[i][j] == 1){
				int dist = check(i, j, bow_x, bow_y);
				if (dist <= D) {
					v[cnt].push_back({ dist,j,i });
				}
			}
		}
	}
}
void solve(vector<int> bow) {
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy_map[i][j] = map[i][j];
	
		}
	}
	
	vector<int> v1;
	for (int i = 0; i < M; i++) {
		if (bow[i]) {
			v1.push_back(i);
		}
	}
	
	while (1){
		vector<node> v[4];
		//find
		int cnt = 0;
		for (int i = 0; i < v1.size(); i++) {
			attack(v1[i], cnt,v);
			cnt++;
		}
		//kill
		for (int i = 0; i < 3; i++) {
			sort(v[i].begin(), v[i].end(), compare);
			if (v[i].size() > 0){
				if (copy_map[v[i][0].x][v[i][0].y] == 1){
					copy_map[v[i][0].x][v[i][0].y] = 0;
					kill_point++;
				}
			}
		}
		//move
		int count = 0;
		for (int j = 0; j < M; j++) {
			for (int i = N - 1; i > 0; i--) {
				copy_map[i][j] = copy_map[i - 1][j];
				if (copy_map[i][j] == 1) { count++; }
			}
			copy_map[0][j] = 0;
		}
		if (!count) break;
	}
	
	
	
}
int main() {
	cin >> N >> M >> D;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				
			}
		}
	}
	vector<int> bow(M);
	for (int i = 0; i < 3; i++) {
		bow[i] = 1;
	}
	sort(bow.begin(), bow.end());

	do {
		kill_point = 0;
		solve(bow);
		if (ans < kill_point) ans = kill_point;
	} while (next_permutation(bow.begin(), bow.end()));
	printf("%d", ans);
}