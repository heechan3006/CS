#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(int start, vector<int> graph[], bool check[]) {
	stack<int> s;
	s.push(start);
	check[start] = true;
	cout << start << ' ';
	while (!s.empty()) {
		int current_node = s.top();
		s.pop();
		for (int i = 0; i < graph[current_node].size(); i++) {
			int next_node = graph[current_node][i];
			
			if (check[next_node] == false) {
				cout << next_node << ' ';
				check[next_node] = true;
				s.push(current_node);
				s.push(next_node);
				break;
			}
		}

	}
}

int main() {
	int n, m, start;
	cin >> n >> m >> start;
	
	vector<int> graph[1001];
	bool check[1001];
	
	fill(check, check + n + 1, false);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
		
	}
	for (int i = 1; i < n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	
	dfs(start, graph, check);
	return 0;
}