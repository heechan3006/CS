#include <iostream>
#include <cstring>

using namespace std;

int D[16][16];
int N, M, K;
int cnt, sx, sy;

int main() {
	cin >> N >> M >> K;
	D[1][1] = 1;
	if (K >= 1) {
		cnt = 0;
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cnt++;
				if (cnt == K) {
					sx = i;
					sy = j;
					break;
				}
			}
			
		}
	}
	else {
		sx = 1;
		sy = 1;
	}
	
	for (int i = 1; i <= sx; i++) {
		for (int j = 1; j <= sy; j++) {
			D[i][j] += D[i - 1][j] + D[i][j - 1];
		}
	}
	int x = D[sx][sy];
	D[sx][sy] = 1;
	for (int i = sx; i <= N; i++) {
		for (int j = sy; j <= M; j++) {
			if (i == sx && j == sy) continue;
			D[i][j] += D[i - 1][j] + D[i][j - 1];
		}
	}
	cout << x * D[N][M] << "\n";
	return 0;
}