#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <queue>
#include <deque>

using namespace std;

int K;
int idx, dir;

int main() {
	int tmp;
	deque<int> dq[5];
	for (int i = 1; i < 5; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			dq[i].push_back(s[j] - '0');
		}
	}
	scanf("%d", &K);
	int ans = 0;
	while (K--) {
		scanf("%d%d", &idx, &dir);
		queue<pair<int, int>> q;
		int tmp_idx = idx;
		int tmp_dir = dir;
		q.push({ idx,dir });
		while (1) {
			if (idx == 4) break;
			idx++;
			dir *= -1;
			if (dq[idx - 1][2] != dq[idx][6]) q.push({ idx,dir });
			else break;
		}
		idx = tmp_idx;
		dir = tmp_dir;
		while (1) {
			if (idx == 1) break;
			idx--;
			dir *= -1;
			if (dq[idx + 1][6] != dq[idx][2]) q.push({ idx,dir });
			else break;
		}
		while (!q.empty()) {
			int cur = q.front().first;
			int rotate = q.front().second;
			q.pop();
			if (rotate == 1) {
				int temp = dq[cur].back();
				dq[cur].pop_back();
				dq[cur].push_front(temp);
			}
			else {
				int temp = dq[cur].front();
				dq[cur].pop_front();
				dq[cur].push_back(temp);
			}
		}
	}
	int result = 0;
	for (int i = 1; i < 5; i++) {
		if (dq[i].front() == 1) result += (int)(pow(2, i - 1));
	}
	printf("%d\n", result);
	return 0;
	
}