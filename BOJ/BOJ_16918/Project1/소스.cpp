#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<tuple>
#include<utility>
using namespace std;

#define MAX_NM 200
#define DEBUG 0
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int N, M, TIME;
char board[MAX_NM][MAX_NM];
queue<tuple<int, int, int> >q;
int main() {
	/* 1. Get input & push to the queue */
	scanf("%d %d %d", &N, &M, &TIME);
	for (int i = 0; i < N; i++)for (int k = 0; k < M; k++) {
		scanf(" %c", &board[i][k]);
		if (board[i][k] == 'O')
			q.push({ i,k,0 });
	}

	/* 2. Go BFS */
	int timeSpend = 2;
	while (1) {
		
		if (timeSpend == TIME +1) break;
		if (timeSpend % 2 == 0) { // put bombs in every single cell
			for (int i = 0; i < N; i++)for (int k = 0; k < M; k++) if (board[i][k] == '.') {
				q.push({ i,k,timeSpend });
				board[i][k] = 'O';
			}
		}
		else { // make it fire
			long long int qPrev = q.size();
			for (long long int i = 0; i < qPrev; i++) {
				/* 2-1. Pop */
				int popX = get<0>(q.front());
				int popY = get<1>(q.front());
				int popT = get<2>(q.front());				
				if (popT + 3 != timeSpend) break;
				q.pop();
				
				for (int j = 0; j < 4; j++) {
					int nextX = popX + dir[j][0];
					int nextY = popY + dir[j][1];
					if (nextX<0 || nextY<0 || nextX > N - 1 || nextY > M - 1) continue;
					if (board[nextX][nextY] == 'O') board[nextX][nextY] = '.';
				}
				
				
			}// for(int i=0
			/* '.' should not be included */
			long long int prev = q.size();
			for (long long int i = 0; i < prev; i++) {
				if (board[get<0>(q.front())][get<1>(q.front())] == 'O')
					q.push({ get<0>(q.front()),get<1>(q.front()),get<2>(q.front()) });
				q.pop();
			}
		}// else // make it fire
		timeSpend++;
	}// while !q.empty()

	/* 3. print out board[][] */
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			printf("%c", board[i][k]);
		}printf("\n");
	}
	return 0;
}