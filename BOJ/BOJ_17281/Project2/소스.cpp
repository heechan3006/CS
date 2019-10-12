#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 50
using namespace std;

int inning[MAXN][9];
vector<int> member;
int N;
int simulate() {
	
	int now_member = 0;
	int out_count = 0;
	int base[4] = { 0, };
	int now_inning = 0;
	int score = 0;
	while (now_inning < N) {
		int hit = inning[now_inning][member[now_member]];
		if (hit == 4) {
			score++;
		}
		if (hit != 0) {
			for (int k = 3; k > 0; k--) {
				if (base[k]) {
					if (k + hit >= 4) {
						score++;
						base[k] = 0;
					}
					else {
						base[k + hit] = 1;
						base[k] = 0;
					}
				}
			}
			if (hit < 4) {
				base[hit] = 1;
			}
		}
		else{
			out_count++;
			if (out_count >= 3) {
				out_count = 0;
				now_inning++;
				base[0] = base[1] = base[2] = base[3] = 0;
			}
		}
		now_member = (now_member+1)%9;
	}
	return score;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &inning[i][j]);
		}
	}
	for (int i = 1; i <= 8; i++) {
		member.push_back(i);
	}
	int ans = 0;
	do {
		member.insert(member.begin() + 3, 0);
		int sum = simulate();
		member.erase(member.begin() + 3);
		if (ans < sum) ans = sum;
	} while (next_permutation(member.begin(), member.end()));
	printf("%d\n", ans);
	return 0;
}