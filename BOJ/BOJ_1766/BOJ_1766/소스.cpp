#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
vector<int> inorder;
int N, M;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	adj = vector<vector<int> >(N + 1);
	inorder = vector<int>(N + 1,0);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		inorder[v]++;
	}
	priority_queue<int> pq;
	for (int i = 1; i <= N; i++) {
		if (!inorder[i]) pq.push(-i);
	}
	while (pq.size()) {
		int here = -pq.top();
		pq.pop();
		cout << here << " ";
		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];
			inorder[next]--;
			if (!inorder[next]) {
				pq.push(-next);
			}
		}
	}
	
	return 0;
}