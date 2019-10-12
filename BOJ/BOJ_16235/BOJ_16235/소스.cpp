#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
struct Tree {
	int x;
	int y;
	int old;
};
deque<int> tree[11][11];
int nutrient[11][11];
int A[11][11];

int N, M, K;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cin >> A[i][j];
			nutrient[i][j] = 5;
		}
	}
	int tmp_x, tmp_y, tmp_z;
	
	int ans = 0;

	for (int i = 0; i < M; i++) {
		cin >> tmp_x >> tmp_y >> tmp_z;
		tree[tmp_x-1][tmp_y-1].push_back(tmp_z);
		ans++;
	}
	
	while (K--) {
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!tree[i][j].size()) continue;
				sort(tree[i][j].begin(), tree[i][j].end());
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (tree[i][j][k] > nutrient[i][j]) {
						while (k < tree[i][j].size()) {
							nutrient[i][j] += tree[i][j].back() / 2;
							tree[i][j].pop_back();
							ans -= 1;
						}
						break;
					}
					else {
						nutrient[i][j] -= tree[i][j][k];
						tree[i][j][k]++;
					}
				}
			}
		}
		
		//°¡À»
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (tree[i][j][k] % 5 == 0) {
						for (int z = 0; z < 8; z++) {
							int nx = i + dx[z];
							int ny = j + dy[z];
							if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
							tree[nx][ny].push_front(1);
							ans++;
						}
					}
				}
				nutrient[i][j] += A[i][j];
			}
		}
		
	}
	
	printf("%d\n", ans);
	return 0;
}