#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define MAXN 200000

using namespace std;

int cache[MAXN];
int path[MAXN];
int N, K;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> N >> K;
	priority_queue<pair<pair<int, int>,int> > pq;
	pq.push({ { 0,N },-1 });
	while (!pq.empty()) {
		int cur = pq.top().first.second;
		int cost = -pq.top().first.first;
		int idx = pq.top().second;
		pq.pop();
		
		if (cache[cur] != -1) continue;
		cache[cur] = cost;
		path[cur] = idx;
		if (cur == K) break;
		if (cur - 1 < MAXN && cache[cur - 1] == -1) {
			pq.push({ { -(cost + 1),cur - 1 },cur });
		}
		if (cur + 1 < MAXN && cache[cur + 1] == -1) {
			pq.push({ {-(cost + 1), cur + 1 },cur });
		}
		if (2 * cur < MAXN && cache[2 * cur] == -1) {
			pq.push({ { -(cost + 1), 2 * cur },cur });
		}
		
	}
	int v = K;
	vector<int> tmp;
	while (v != -1) {
		tmp.push_back(v);
		v = path[v];
	}
	cout << cache[K] << "\n";
	for (int i = 0; i < tmp.size(); i++) {
		cout << tmp[tmp.size() - i - 1] << " ";
	}
	
	return 0;
}