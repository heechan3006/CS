#include <iostream>
#include <queue>


#define MAXN 1000
using namespace std;
int N, M;
char map[MAXN][MAXN];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


queue<pair<int,int>> q;
queue<pair<int,int>> q1;
int bfs() {
	int res = 0;
	int q_size;
	int q1_size;
	int ans = -1;
	while (!q.empty()&&ans==-1) {
		
		q1_size = q1.size();
		while (q1_size--) {
			int x = q1.front().first;
			int y = q1.front().second;
			
			q1.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] != '#' && map[nx][ny]!='*') {
					q1.push({ nx,ny });
					map[nx][ny] = '*';
				}
				
			}
		}
		q_size = q.size();
		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			if (x == 0 || y == 0 || x == N - 1 || y == M - 1) {
				ans = res + 1;
				break;
			}
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == '.') {
					q.push({ nx,ny });
					map[nx][ny] = '@';
				}
			
			}
		}
		res++;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		while (!q.empty()) q.pop();
		while (!q1.empty()) q1.pop();
		cin >> M >> N;
		
		for (int i = 0; i < N; i++) {
			cin >> map[i];
			for (int j = 0; j < M; j++) {
				
				if (map[i][j] == '*') {
					
					q1.push(make_pair( i,j ));
				}
				else if (map[i][j] == '@') {
					
					q.push(make_pair( i,j ));
					
				}
			}
		}

		int ans = bfs();
		if (ans == -1) {
			cout <<"IMPOSSIBLE\n";
		}
		else {
			cout << ans<<"\n";
		}
	}
	return 0;
}