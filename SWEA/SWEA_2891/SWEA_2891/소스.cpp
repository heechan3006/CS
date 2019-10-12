#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

struct Node {
	int x;
	int y;
	int p;
	Node() {}
	Node(int _x, int _y, int _p) : x(_x), y(_y), p(_p) {}
};

struct Num {
	int top;
	int bottom;
	Num() {}
	Num(int _top, int _bottom) : top(_top), bottom(_bottom) {}
};

int N;
vector<Node> v;
Num map[6][6];

void printSudoku() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j].bottom == 10) {
				printf("%d ", map[i][j].top);
			}
			else {
				printf("%d/%d ", map[i][j].top, map[i][j].bottom);
			}
		}
		printf("\n");
	}
}
int getRow(int i) {
	if (i == 0 || i == 1) {
		return 0;
	}
	else if (i == 2 || i == 3) {
		return 2;
	}
	else return 4;
}

int getCol(int j) {
	if (j == 0 || j == 1 || j == 2) {
		return 0;
	}
	else  return 3;
}
bool chkSudoku(int r, int c, int p, int number) {
	bool row = true;
	bool col = true;
	bool box = true;
	bool dist = true;

	// 가로열
	for (int i = 0; i < 6; i++) {
		if (map[i][c].top == number || map[i][c].bottom == number) {
			row = false;
			break;
		}
	}
	// 새로행
	for (int j = 0; j < 6; j++) {
		if (map[r][j].top == number || map[r][j].bottom == number) {
			col = false;
			break;
		}
	}
	// 3x2 확인
	int rr = getRow(r);
	int cc = getCol(c);
	for (int i = rr; i <= rr + 1; i++) {
		for (int j = cc; j <= cc + 2; j++) {
			if (map[i][j].top == number || map[i][j].bottom == number) {
				box = false;
				break;
			}
		}
		if (!box) break;
	}
	// 분자 분모 크기 확인
	if (p == 0 && map[r][c].bottom != 0) {
		if (number > map[r][c].bottom) dist = false;
	}
	if (p == 1) {
		if (map[r][c].top > number) dist = false;
	}
	if (row && col && box && dist) return true;
	else return false;

}
void dfs(int ind, int cnt) {
	if (cnt == v.size()) {
		printSudoku();
		return;
	}
	int x = v[ind].x;
	int y = v[ind].y;
	int p = v[ind].p;
	
	for (int k = 1; k <= 9; k++) {
		if (p == 1 && k == 1) continue;
		if (chkSudoku(x, y, p, k)) {
			if (p == 0) map[x][y].top = k;
			else map[x][y].bottom = k;
			dfs(ind + 1, cnt + 1);
			if (p == 0) map[x][y].top = 0;
			else map[x][y].bottom = 0;
		}

	}
}
int main() {
	for (int i = 0 ; i < 6 ; i++){
		for (int j = 0; j < 6; j++){
			string str;
			cin >> str;
			
			if (str.size() > 1) {
				int num_t,num_b;
				if (str[0] == '-') {
					v.push_back(Node(i,j,0));
				}
				else {
					num_t = str[0] - '0';
				}
				if (str[2] == '-') {
					v.push_back(Node(i, j, 1));
				}
				else {
					num_b = str[2] - '0';
				}
				map[i][j] = Num(num_t, num_b);
			}
			else {
				if (str == "-") {
					map[i][j] = Num(0, 10);
					v.push_back(Node(i, j, 0));
				}
				else {
					map[i][j] = Num(stoi(str), 10);
				}
			}
		}
	}
	dfs(0, 0);
}