#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int A[10][10];
int nutrient[10][10];
vector<int> tree[10][10];
int N,M,K;

int dx[] = { -1,-1, -1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			nutrient[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, old;
		cin >> x >> y >> old;
		x--;
		y--;
		tree[x][y].push_back(old);
	}
	
	while (K--) {
		// 봄,여름
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (tree[i][j].size() == 0) continue;
				sort(tree[i][j].begin(), tree[i][j].end());
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (nutrient[i][j] < tree[i][j][k]) {

						for (int kk = k; kk < tree[i][j].size(); kk++) {
							nutrient[i][j] += tree[i][j][kk] / 2;
						}
						tree[i][j].erase(tree[i][j].begin() + k, tree[i][j].end());
						break;
					}
					else {
						nutrient[i][j] -= tree[i][j][k];
						tree[i][j][k] += 1;
					}
				}
			}
		}
		// 가을,겨울
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (tree[i][j][k] % 5 == 0) {
						for (int kk = 0; kk < 8; kk++) {
							int nx = i + dx[kk];
							int ny = j + dy[kk];
							if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
							tree[nx][ny].push_back(1);
						}
					}
				}
				nutrient[i][j] += A[i][j];
			}
		}
		
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += tree[i][j].size();
		}
	}
	cout << ans << "\n";
	return 0;
}