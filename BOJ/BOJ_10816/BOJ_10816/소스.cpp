#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define MAX_N 500000

using namespace std;

int N, M;
int card_1[MAX_N];

map<int, int>::iterator iter;
map<int, int> idx;
vector<int> card;
int main() {
	scanf("%d", &N);
	int tmp;
	int high_max = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		iter = idx.find(tmp);
		if (iter == idx.end()) {
			idx[tmp] = 1;
			card.push_back(tmp);
			high_max++;
		}
		else {
			idx[tmp] += 1;
		}
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &card_1[i]);
		
	}
	sort(card.begin(), card.end());
	for (int i = 0; i < M; i++) {
		int row = 0;
		int high = high_max-1;
		int ans = 0;
		while (row <= high) {
			int mid = (row + high) / 2;
			if (card[mid] <= card_1[i]) {
				if (card[mid] == card_1[i]) {
					iter = idx.find(card[mid]);
					ans = (*iter).second;
					break;
				}
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