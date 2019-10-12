/* 첫번째줄
   지도의 크기 N (5 <= N <= 25)
   그다음 N줄에 각각 N개의 자료(0 or 1)가 입력됨
   총 단지 수 출력.
   각 단지 내 집의 수를 오름차순으로 정렬하여 한줄에 하나씩 출력.
   7
   0110100
   0110101
   1110101
   0000111
   0100000
   0111110
   
   3
   7
   8
   9
   */
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N;
int map[26][26];
int group[26][26];
char num[26];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans[25*25];
int count_tmp;
void bfs(int i, int j, int cnt) {
	
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	group[i][j] = cnt;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < N) {
				if (map[nx][ny] == 1 && group[nx][ny] == 0) {
					q.push(pair<int, int>(nx, ny));
					group[nx][ny] = cnt;
				}
			}
		
		}
	}
	
}

int main() {
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {	
		cin >> num;	
		for (int j = 0; j < N; j++) {
			map[i][j] = (int)(num[j] - '0');
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && group[i][j] == 0) {
				bfs(i, j, ++cnt);
				
			}
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans[group[i][j]] += 1;
		}
	}
	sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		//cout << ans[i] << '\n';
		printf("%d\n", ans[i]);
	}
	return 0;
}