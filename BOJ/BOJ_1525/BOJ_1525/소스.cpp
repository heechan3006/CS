#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;
map<int, int> visited;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	int num;
	int start = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> num;
			if (num == 0) num = 9;
			start = start * 10 + num;
		}
	}
	int purpose = 123456789;
	queue<int> q;
	q.push(start);
	visited[start] = 0;
	while (!q.empty()) {
		int cur = q.front();
		if (cur == purpose) {
			break;
		}
		string s = to_string(cur);
		int z = s.find('9');
		int x = z / 3;
		int y = z % 3;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
			string tmp = s;
			swap(tmp[nx * 3 + ny], tmp[x * 3 + y]);
			int next = stoi(tmp);
			if (!visited.count(next)) {
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}
	if (visited.count(purpose)) {
		printf("%d\n", visited[purpose]);
	}
	else {
		printf("-1\n");
	}
}