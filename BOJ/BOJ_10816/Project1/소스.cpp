#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 500000

using namespace std;
int N, M;
int card_1[MAX_N];

vector<int> card;
int main() {
	scanf("%d", &N);
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		card.push_back(tmp);
	}
	sort(card.begin(), card.end());
	vector<pair<int, int>> idx;
	idx.push_back({ card[0],1 });
	int ind = 0;
	for (int i = 1; i < N; i++) {
		if (card[i] == idx[ind].first) {
			idx[ind].second++;
		}
		else {
			idx.push_back({ card[i],1 });
			ind++;
		}
	}
	sort(idx.begin(), idx.end());
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &card_1[i]);
	}
	for (int i = 0; i < M; i++) {
		int row = 0;
		int high = idx.size()-1;
		int ans = 0;
		while (row <= high) {
			int mid = (row + high) / 2;
			if (idx[mid].first == card_1[i]) {
				ans = idx[mid].second;
				break;
			}
			else if (idx[mid].first < card_1[i]) {
				row = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		printf("%d ", ans);
	}
	return 0;
}