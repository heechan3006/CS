// 정점의 개수 N(1<= N <= 1,000), 간선의 개수 M( 1 <= M <= 10,000), 탐색을 시작할 정점의 번호 V, 간선은 양방향
// 첫째 줄 DFS, 둘째 줄 BFS 결과 V부터 방문된 점을 순서대로 출력
/*
입력 1

4 5 1
1 2
1 3
1 4
2 4
3 4

출력 1

1 2 4 3
1 2 3 4

입력 2

5 5 3
5 4
5 2
1 2
3 4
3 1

출력 2

3 1 2 5 4
3 1 4 2 5

입력 3

1000 1 1000
999 1000

출력 3 

1000 999
1000 999
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stdio.h>


using namespace std;

void bfs(int start, vector<int> graph[], bool check[]) {
	queue<int> q;
	
	q.push(start);
	check[start] = true;
	
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		cout << tmp << ' ';
		for (int i = 0; i < graph[tmp].size(); i++) {
			if (check[graph[tmp][i]] == false) {
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = true;
			}
		}
	}
}
int main() {
	int n, m, start;
	cin >> n >> m >> start;
	
	vector<int> graph[11];
	bool check[11];
	fill(check, check + n + 1, false);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);

	}
	for (int i = 0; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	
	bfs(start, graph, check);
	cout << endl;
	return 0;
}