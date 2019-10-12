#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
int N;
int map[50][10];
int score[50][10];

using namespace std;
vector<int>::iterator it;

int simulate(vector<int>& v,int score[][10]) {
	int player_idx = 0;
	int out_count = 0;
	int total_score = 0;
	int inning = 0;
	int start_point = 0;
	while (inning < N){
		if (player_idx > 8) player_idx = 0;
		int hit = map[inning][v[player_idx]];
		score[inning][v[player_idx]] = 0;
		if (hit == 0) {
			int tmp = player_idx;
			int sum = 0;
			out_count++;
			if (out_count == 3) {
				out_count--;
				while (1) {
					if (out_count == 0 && tmp == start_point) break;
					tmp--;
					if (tmp < 0) tmp = 8;
					if (out_count != 0 && map[inning][v[tmp]] == 0) out_count--;
					//if (map[inning][v[tmp]] == 0) break;
					if (map[inning][v[tmp]] != 0) {
						sum += map[inning][v[tmp]];
						score[inning][v[tmp]] += sum;
						if (score[inning][v[tmp]] >= 4) {
							total_score++;
						}
					}
					
				}
				inning++;
				start_point = player_idx + 1;
				if (start_point > 8) start_point = 0;
			}
		}
		player_idx++;
	
	}
	return total_score;
}
int main() {
	vector<int> v;
	scanf("%d", &N);
	for (int i = 0; i < 9; i++) {
		if (i == 0) continue;
		v.push_back(i);

	}
	memset(score, 0, sizeof(score));
	memset(map, 0, sizeof(map));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	int ans = 0;
	do {
		v.insert(v.begin() + 3, 0);
		int total = simulate(v,score);
		v.erase(v.begin() + 3);
		if (ans < total) {
			ans = total;
		
		}
		
	} while (next_permutation(v.begin(), v.end()));
	printf("%d\n", ans);

}