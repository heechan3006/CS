#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int map[20][20];
int n;
int main() {
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	//up
	if (s == "up"){
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n - 1 ; i++) {
				int curr = map[i][j];
				int cnt = 0;
			
				while (curr == 0) {
					cnt++;
					if (i + cnt >= n) break;
					curr = map[i + cnt][j];
				}
				int next = map[i + cnt + 1][j];
				int next_cnt = 0;
				while (next == 0) {
					next_cnt++;
					if (i + cnt + next_cnt + 1 >= n) break;
					next = map[i + cnt + next_cnt + 1][j];
				}
				if (curr == next) {
					if (next == 0) break;
					map[i][j] = curr * 2;
					map[i + 1][j] = 0;
					if (cnt != 0) {
						map[i + cnt][j] = 0;
						map[i + cnt + next_cnt + 1][j] = 0;
					}
					if (next_cnt != 0) map[i + cnt + next_cnt + 1][j] = 0;
				}
				else {
					map[i][j] = curr;
					map[i + 1][j] = next;
					if (cnt != 0) map[i + cnt][j] = 0;
					if (next_cnt != 0) map[i + cnt + next_cnt + 1][j] = 0;
					if (next == 0) break;
				
				
				}
			}
		}
	}
	//down
	else if (s == "down") {
		for (int j = 0; j < n; j++) {
			for (int i = n-1; i >= 1; i--) {
				int curr = map[i][j];
				int cnt = 0;

				while (curr == 0) {
					cnt++;
					if (i - cnt < 0) break;
					curr = map[i - cnt][j];
				}
				int next = map[i - cnt - 1][j];
				int next_cnt = 0;
				while (next == 0) {
					next_cnt++;
					if (i - cnt - next_cnt - 1 < 0) break;
					next = map[i - cnt - next_cnt - 1][j];
				}
				if (curr == next) {
					if (next == 0) break;
					map[i][j] = curr * 2;
					map[i - 1][j] = 0;
					if (cnt != 0) {
						map[i - cnt][j] = 0;
						map[i - cnt - next_cnt - 1][j] = 0;
					}
					if (next_cnt != 0) map[i - cnt - next_cnt - 1][j] = 0;
				}
				else {
					map[i][j] = curr;
					if (cnt != 0) map[i - cnt][j] = 0;
					map[i - 1][j] = next;
					if (next_cnt != 0) map[i - cnt - next_cnt - 1][j] = 0;
					if (next == 0) break;
				}
			}
		}
	}
	//left
	if (s == "left") {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				int curr = map[i][j];
				int cnt = 0;

				while (curr == 0) {
					cnt++;
					if (j + cnt >= n) break;
					curr = map[i][j+cnt];
				}
				int next = map[i][j + cnt + 1];
				int next_cnt = 0;
				while (next == 0) {
					next_cnt++;
					if (j + cnt + next_cnt + 1 >= n) break;
					next = map[i][j + cnt + next_cnt + 1];
				}
				if (curr == next) {
					if (next == 0) break;
					map[i][j] = curr * 2;
					map[i][j+1] = 0;
					if (cnt != 0) {
						map[i][j + cnt] = 0;
						map[i][j + cnt + next_cnt + 1] = 0;
					}
					if (next_cnt != 0) map[i + cnt + next_cnt + 1][j] = 0;
				}
				else {
					map[i][j] = curr;
					map[i][j + 1] = next;
					if (cnt != 0) map[i][j + cnt] = 0;
					if (next_cnt != 0) map[i][j + cnt + next_cnt + 1] = 0;
					if (next == 0) break;

				}
			}
		}
	}
	//right
	else if (s == "right") {
		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 1; j--) {
				int curr = map[i][j];
				int cnt = 0;

				while (curr == 0) {
					cnt++;
					if (i + cnt >= n) break;
					curr = map[i][j - cnt];
				}
				int next = map[i][j - cnt - 1];
				int next_cnt = 0;
				while (next == 0) {
					next_cnt++;
					if (j - cnt - next_cnt - 1 < 0) break;
					next = map[i][j - cnt - next_cnt - 1];
				}
				if (curr == next) {
					if (next == 0) break;
					map[i][j] = curr * 2;
					map[i][j-1] = 0;
					if (cnt != 0) {
						map[i][j- cnt] = 0;
						map[i][j -cnt - next_cnt - 1] = 0;
					}
					if (next_cnt != 0) map[i][j - cnt - next_cnt - 1] = 0;
				}
				else {
					map[i][j] = curr;
					map[i][j - 1] = next;
					if (cnt != 0) map[i][j - cnt] = 0;
					if (next_cnt != 0) map[i][j - cnt - next_cnt - 1] = 0;
					if (next == 0) break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	
}