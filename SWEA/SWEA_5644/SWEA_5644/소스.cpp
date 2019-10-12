#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
	int x;
	int y;
	int c;
	int p;
};
int M, A;
node AP[8];

int info_a[101];
int info_b[101];
int dx[] = { 0,0,1,0,-1 };
int dy[] = { 0,-1,0,1,0 };
bool dist(int x, int y, node ap) {
	if (abs(x - ap.x) + abs(y - ap.y) <= ap.c) return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		cin >> M >> A;
		for (int i = 1; i <= M; i++) {
			cin >> info_a[i];
		}
		for (int i = 1; i <= M; i++) {
			cin >> info_b[i];
		}
		int ans = 0;
		int x_a = 1;
		int y_a = 1;
		int x_b = 10;
		int y_b = 10;
		//c : 거리제한, p: 충전량
		for (int i = 0; i < A; i++) {
			cin >> AP[i].x >> AP[i].y >> AP[i].c >> AP[i].p;
		}
		for (int i = 0; i <= M; i++) {
			bool possible_a[8] = { false, };
			bool possible_b[8] = { false, };
			x_a += dx[info_a[i]];
			y_a += dy[info_a[i]];
			x_b += dx[info_b[i]];
			y_b += dy[info_b[i]];
			for (int x1 = 0; x1 < A; x1++) {
				if (dist(x_a, y_a, AP[x1])) possible_a[x1] = true;
				if (dist(x_b, y_b, AP[x1])) possible_b[x1] = true;
			}
			int max_v = 0;
		
			for (int j = 0; j < A; j++) {
				
				for (int k = 0; k < A; k++) {
					int sum = 0;
					if (possible_a[j]) {
						if (possible_b[k]) {
							if (j == k) {
								sum = AP[j].p;
							}
							else {
								sum = AP[j].p + AP[k].p;
							}
						}
						else {
							sum = AP[j].p;
						}
					}
					else {
						if (possible_b[k]) {
							sum = AP[k].p;
						}
					}
					
					if (max_v < sum) max_v = sum;
				}
			}
			ans += max_v;
		}
		cout << "#" << test_case<<" "<<ans << "\n";
	}
	return 0;
}
