#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
struct node {
	int x;
	int y;
	int parent_x;
	int parent_y;
};
node map[37];
bool visited[6][6];
int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { -1,1,-2,2,-2,2,-1,1 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int sx, sy;
	int x, y;
	for (int i = 0; i < 36; i++) {
		string s;
		cin >> s;
		if (i ==0){
			sx = 6 - (s[1] - '0');
			sy = s[0] - 'A';
			x = sx;
			y = sy;
			visited[sx][sy] = true;
			continue;
		}
		int target_x = 6 - (s[1] - '0');
		int target_y = s[0] - 'A';
		if (visited[target_x][target_y]) {
			cout << "Invalid\n";
			return 0;
		}
		bool flag = false;
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx == target_x && ny == target_y) {
				visited[nx][ny] = true;
				flag = true;
				break;
			}
		}
		if (flag) {
			x = target_x;
			y = target_y;
		}
		else {
			cout << "Invalid\n";
			return 0;
		}
	}
	for (int k = 0; k < 8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx == sx && ny == sy) {
			cout << "Valid\n";
			return 0;
		}
	}
	cout << "Invalid\n";
	return 0;
}
