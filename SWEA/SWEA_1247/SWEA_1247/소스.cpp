#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
bool visited[12];
vector<pair<int, int>> v;
vector<pair<int, int>>::iterator iter ;
int main() {
	scanf("%d", &N);
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N + 2; i++) {
		int tmp_x, tmp_y;
		scanf("%d %d", &tmp_x, &tmp_y);
		v.push_back({ tmp_x,tmp_y });
	}
	
	pair<int,int> tmp;
	tmp = v[1];
	iter = v.begin();
	v.erase(iter+1,iter+2);
	v.push_back(tmp);
	int dist_sum = 0;
	int tmp_idx = 0;
	for (int i = 0; i< N; i++){
		int cx = v[tmp_idx].first;
		int cy = v[tmp_idx].second;
		int dist = 200;
		for (int j = 1; j < v.size()-1; j++) {
			if (visited[j]) continue;
			if (tmp_idx == j) continue;
			int nx = v[j].first;
			int ny = v[j].second;
			int tmp_dist = abs(cx - nx) + abs(cy - ny);
			if (dist > tmp_dist) {
				dist = tmp_dist;
				tmp_idx = j;
			}
		}
		visited[tmp_idx] = true;
		dist_sum += dist;
	}
	int dist = abs(v[tmp_idx].first - v[N + 1].first) + abs(v[tmp_idx].second - v[N + 1].second);
	dist_sum += dist;
	printf("%d\n", dist_sum);
}