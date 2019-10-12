#include <iostream>
#include <algorithm>
using namespace std;

int turncount[3];
int winnercount[3];
bool pattern_used[11];
int turn[3][20];
int pattern[10][10];
int N, K;
bool ret = false;
int go(int pattern_1, int pattern_2, int user_1, int user_2) {
	if (pattern_1 != pattern_2) {
		if (pattern[pattern_1][pattern_2] == 2) {
			return user_1;
		}
		else if (pattern[pattern_1][pattern_2] == 0) {
			return user_2;
		}
	}
	else {
		return max(user_1, user_2);
	}
	return -1;
}
void solve(int user1, int user2) {
	if (winnercount[0] == K) {
		ret = true;
		return;
	}
	else if (winnercount[1] == K || winnercount[2] == K) {
		return;
	}
	int user_next = 3 - user1 - user2;
	if (user1 == 0) {
		for (int i = 1; i <= N; i++) {
			if (!pattern_used[i]) {
				int winner = go(i,turn[user2][turncount[user2]], 0,user2);
				winnercount[winner]++;
				turncount[user2]++;
				pattern_used[i] = true;
				solve(winner, user_next);
				winnercount[winner]--;
				turncount[user2]--;
				pattern_used[i] = false;
			}
		}
	}
	else if (user2 == 0) {
		for (int i = 1; i <= N; i++) {
			if (!pattern_used[i]) {
				int winner = go(turn[user1][turncount[user1]], i,user1, 0);
				winnercount[winner]++;
				turncount[user1]++;
				pattern_used[i] = true;
				solve(winner, user_next);
				winnercount[winner]--;
				turncount[user1]--;
				pattern_used[i] = false;
			}
		}
	}
	else {
		int winner = go(turn[user1][turncount[user1]], turn[user2][turncount[user2]], user1, user2);
		winnercount[winner]++;
		turncount[user1]++;
		turncount[user2]++;
		
		solve(winner, user_next);
		
		winnercount[winner]--;
		turncount[user1]--;
		turncount[user2]--;
		
	}
}
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> pattern[i][j];
		}
	}
	for (int i = 1; i < 3; i++) {
		for (int j = 0; j < 20; j++) {
			cin >> turn[i][j];
		}
	}
	solve(0, 1);
	if (ret) printf("1");
	else printf("0");

}