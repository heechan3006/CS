#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

struct tile {
	int left;
	int right;
	int num;
	tile() {}
	tile(int _left,int _right,int _num) : left(_left), right(_right), num(_num) {}
};
int N;
tile map[500][500];

int main() {
	scanf("%d", &N);
	int tmp_a, tmp_b;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++){
			cin >> map[i][j].left;
			cin >> map[i][j].right;
		}
		if (i % 2 == 0) {
			cin >> map[i][N-1].left;
			cin >> map[i][N-1].right;
		}
	}

}
