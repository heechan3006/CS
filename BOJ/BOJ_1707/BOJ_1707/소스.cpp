#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int color = -1;
	vector<int> node;
};

int V, E;
string res;
void dfs(int now, int color, Node check[]) {
	check[now].color = color;
	
	for (int i = 0; i < check[now].node.size(); i++) {
		int next = check[now].node[i];
		if (check[next].color == -1) {
			dfs(next, (color + 1) % 2,check);
		}
		if (check[next].color == color) {
			res = "NO";
			return;
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--){
		res = "YES";
		cin >> V >> E;
		int v_1, v_2;
		Node check[20001];
		for (int i = 0; i < E; i++) {
			cin >> v_1 >> v_2;
			check[v_1].node.push_back(v_2);
			check[v_2].node.push_back(v_1);	
		}
	
		for (int i = 1; i <= V; i++) {
			if (check[i].color == -1) {
				dfs(i, 0,check);
			}
		}
		cout << res << "\n";
	}
}