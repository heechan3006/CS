#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#define MAXN 501
using namespace std;
struct node {
	int num;
	int idx;
};
struct info {
	int x;
	int y;
	string s;
};
node map[MAXN][2 * MAXN];
int dist[MAXN][2 * MAXN];
int N;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

pair<int, string> bfs() {
	queue<info> q;
	q.push({ 1,1,"1 "});
	q.push({ 1,2,"1 " });
	dist[1][1] = 1;
	dist[1][2] = 1;
	int max_dist = 1;
	int max_idx = 1;
	string result_s;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		string s = q.front().s;
		
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx <= 0 || ny <= 0 || nx > N || ny > 2 * N) continue;
			if (map[nx][ny].num == 0) continue;
			if (dist[nx][ny] == -1) {
				if (map[nx][ny].idx != map[x][y].idx) {
					
					if (map[nx][ny].num == map[x][y].num) {
						dist[nx][ny] = dist[x][y] + 1;
						q.push({ nx,ny,s+to_string(map[nx][ny].idx)+" "});
						if (map[nx][ny].idx > max_idx) {
							max_dist = dist[nx][ny];
							max_idx = map[nx][ny].idx;
							result_s = s + to_string(map[nx][ny].idx) + " ";
						}
					}
					if (map[nx][ny - 1].idx == map[nx][ny].idx) {
						dist[nx][ny - 1] = dist[nx][ny];
						q.push({ nx,ny - 1,s + to_string(map[nx][ny].idx) + " " });
					}
					else if (map[nx][ny + 1].idx == map[nx][ny].idx) {
						dist[nx][ny + 1] = dist[nx][ny];
						q.push({ nx,ny + 1,s + to_string(map[nx][ny].idx) + " " });
					}
					
				}
				
			}
		}
	}
	
	return { max_dist,result_s };
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int idx = 1;
	int r = 1;
	int c = 1;
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < N * N - N / 2; i++) {
		int tile1, tile2;
		cin >> tile1 >> tile2;
		map[r][c++] = { tile1,idx};
		map[r][c++] = { tile2,idx++};
		if (r % 2 == 1 && c > 2*N) {
			r++;
			c = 2;
		}
		else if (r % 2 == 0 && c > 2*N - 1) {
			r++;
			c = 1;
		}
	}
	pair<int,string> result = bfs();
	cout << result.first << "\n";
	cout << result.second << "\n";
	return 0;
}