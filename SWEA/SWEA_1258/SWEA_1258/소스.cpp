#include <iostream>
#include <memory.h>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int N;
int map[101][101];
bool visited[101][101];
vector<tuple<int,int,int>> v;
int end_x, end_y;


void dfs(int x, int y) {

	if (x >= N || y >= N) return;
	if (map[x][y] == 0) {
		return;
	}
	if (end_x < x) end_x = x;
	if (end_y < y) end_y = y;
	if (!visited[x][y]){
		visited[x][y] = true;
		dfs(x, y + 1) ;
		dfs(x + 1, y) ;
	}
	
}
int main() {
	freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	for (int test_case =1; test_case <= t; test_case++){
		scanf("%d", &N);
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		v.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		int sx, sy;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//int x, y;
				if (visited[i][j]) continue;
				if (map[i][j] == 0) continue;
				sx = i;
				sy = j;
				end_x = i;
				end_y = j;
				dfs(i, j);
				v.push_back(make_tuple(((end_x-sx+1)*(end_y-sy+1)),end_x-sx+1,end_y-sy+1));
			}
		}
		sort(v.begin(),v.end());
		printf("#%d %d ", test_case,v.size());
		for (auto it = v.begin(); it != v.end(); it++) {
			printf("%d %d ",get<1>((*it)),get<2>((*it)));
		}
		printf("\n");
	}
	return 0;
}