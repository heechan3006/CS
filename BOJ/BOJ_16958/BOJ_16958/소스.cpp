#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int s;
	int x;
	int y;
};
vector<node> map;
vector<pair<int, int>> tele;
vector<pair<int, int>> near;

int N, T,M;
int main() {
	cin >> N >> T;
	int tmp_s, tmp_x, tmp_y;
	for (int i = 0; i < N; i++) {
		cin >> tmp_s >> tmp_x >> tmp_y;
		map.push_back({ tmp_s,tmp_x,tmp_y });
		if (tmp_s == 1) {
			tele.push_back({ tmp_x,tmp_y });
		}
	}
	near.resize(N+1);
	for (int i = 0; i < N; i++) {
		if (map[i].s == 0) {
			int min = 98765432;
			int coord = 0;
			for (int j = 0; j < tele.size(); j++) {
				int dist = abs(tele[j].first - map[i].x) + abs(tele[j].second - map[i].y);
				if (min > dist) {
					min = dist;
					coord = j;
				}
			}
			near[i] = { tele[coord].first,tele[coord].second };
		}
	}
	cin >> M;
	int a, b;
	vector<int> v;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--;
		b--;
		int dist = 0;
		int no_tele_dist = abs(map[a].x - map[b].x) + abs(map[a].y - map[b].y);
		if (map[a].s == 1 && map[b].s == 1) {
			dist = T;
		}
		else if (map[a].s == 1 && map[b].s == 0) {
			dist = abs(map[b].x - near[b].first) + abs(map[b].y - near[b].second) + T;
		}
		else if (map[a].s == 0 && map[b].s == 1) {
			dist = abs(map[a].x - near[a].first) + abs(map[a].y - near[a].second) + T;
		}
		else if (map[a].s == 0 && map[b].s == 0) {
			int dist_a = abs(map[a].x - near[a].first) + abs(map[a].y - near[a].second);
			int dist_b = abs(map[b].x - near[b].first) + abs(map[b].y - near[b].second);
			dist = dist_a + dist_b + T;
		}
		if (dist == 0) {
			dist = no_tele_dist;
		}
		else {
			dist = min(dist, no_tele_dist);
		}
		v.push_back(dist);
	}
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}
	return 0;
}