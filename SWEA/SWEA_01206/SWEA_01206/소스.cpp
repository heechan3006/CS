#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;
vector<int> input;
/*
int input[] = { 0, 0, 225, 214, 82, 73, 241,
				233, 179, 219, 135, 62, 36,
				13, 6, 71, 179, 77, 67, 139,
				31, 90, 9, 37, 93, 203, 150,
				69, 19, 137, 28, 174, 32, 80,
				64, 54, 18, 0, 158, 73, 173, 20,
				0, 102, 107, 48, 50, 161, 246, 145,
				225, 31, 0, 153, 185, 157, 44, 126,
				153, 233, 0, 201, 83, 103, 191, 0,
				45, 0, 131, 87, 97, 105, 97, 209, 157,
				22, 0, 29, 132, 74, 2, 232, 44, 203, 0,
				51, 0, 244, 212, 212, 89, 53, 50, 244,
				207, 144, 72, 143, 0, 0 };
*/
int map[1001][1001];
int dist[1001][1001];
void calc(int x, int y) {
	dist[x][y] = map[x][y - 2] + map[x][y - 1] + map[x][y] + map[x][y + 1] + map[x][y + 2];
}
int main() {
	int t = 10;
	int n ;
	int tmp;
	for (int test_case = 1; test_case <= t; test_case++){
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			input.push_back(tmp);
		
		}
		for (int j = 0; j < n; j++) {
			int i = 255;
			while (input[j]--) {
				i--;
				map[i][j] = 1;
			}
		}
		int ans = 0;
		for (int i = 0; i < 255; i++) {
			for (int j = 2; j < n - 2; j++) {
				if (map[i][j] == 1){
					calc(i, j);
					if (dist[i][j] == 1) ans++;
				}
			}
		}
	
		printf("#%d %d\n", test_case, ans);
		memset(dist, 0, sizeof(dist));
		memset(map, 0, sizeof(map));
		input.clear();
	}
	return 0;
}