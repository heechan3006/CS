#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N, M, H;
int map[100][100];

int start(int j) {
	int i = 1;
	while (i <= H) {
		if (map[i][j] == 1) {
			j++;
		}
		else if (map[i][j] == 2) {
			j--;
		}
		i++;
	}
	return j;
}
bool check() {
	for (int i = 1; i <= N; i++) {
		int res = start(i);
		if (res != i) return false;
	}
	return true;
}
int main() {
	scanf("%d%d%d", &N, &M, &H);
	int tmp_a, tmp_b;
	for (int i = 0; i < M; i++) {
		
		scanf("%d%d", &tmp_a, &tmp_b);
		map[tmp_a][tmp_b] = 1;
		map[tmp_a][tmp_b + 1] = 2;
	}
	vector<pair<int, int>> v;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] != 0) continue;
			if (map[i][j + 1] != 0) continue;
			v.push_back({ i,j });
		}
	}
	int ans = -1;
	int len = v.size();
	if (check()) {
		printf("0\n");
		return 0;
	}
	for (int l1 = 0; l1 < len; l1++) {
		if (map[v[l1].first][v[l1].second] != 0) continue;
		if (map[v[l1].first][v[l1].second+1] != 0) continue;
		map[v[l1].first][v[l1].second] = 1;
		map[v[l1].first][v[l1].second + 1] = 2;
		if (check()) {
			if (ans == -1 || ans >1) ans = 1;
		}
		for (int l2 = l1 + 1; l2 < len; l2++) {
			if (map[v[l2].first][v[l2].second] != 0) continue;
			if (map[v[l2].first][v[l2].second + 1] != 0) continue;
			map[v[l2].first][v[l2].second] = 1;
			map[v[l2].first][v[l2].second+1] = 2;
			if (check()) {
				if (ans == -1 || ans > 2) ans = 2;
			}
			for (int l3 = l2 + 1; l3 < len; l3++) {
				if (map[v[l3].first][v[l3].second] != 0) continue;
				if (map[v[l3].first][v[l3].second + 1] != 0) continue;
				map[v[l3].first][v[l3].second] = 1;
				map[v[l3].first][v[l3].second + 1] = 2;
				if (check()) {
					if (ans == -1 || ans > 3) ans = 3;
					
				}
				map[v[l3].first][v[l3].second] = 0;
				map[v[l3].first][v[l3].second + 1] = 0;
			}
			map[v[l2].first][v[l2].second] = 0;
			map[v[l2].first][v[l2].second + 1] = 0;
		}
		map[v[l1].first][v[l1].second] = 0;
		map[v[l1].first][v[l1].second + 1] = 0;
	}
	if (ans > 3) {
		printf("-1\n");
	}
	else{
		printf("%d\n", ans);
	}
	return 0;
}