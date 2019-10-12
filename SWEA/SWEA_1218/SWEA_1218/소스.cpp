#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int N;
int map[1000];
bool possible = false;
char word[][4] = { {'{','(','<','['},{'}',')','>',']'}};

int main() {
	
	for (int test_case=1; test_case<=10; test_case++){
		memset(map, 0, sizeof(map));
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			char tmp_word;
			scanf(" %c", &tmp_word);
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 4; k++) {
					if (word[j][k] == tmp_word) {
						map[i] = 10 * j + k;
					}
				}
			}
		}
		stack<int> s;
		int check = 0;
		for (int i = 0; i < N; i++) {
			if (check) break;
			if (map[i] / 10 == 0) s.push(map[i]);
			else {
				int value = s.top();
				s.pop();
				if (map[i] % 10 - value == 0) check = 0;
				else check = 1;
			}
		}
		printf("#%d %d\n", test_case,!check);
	}
	return 0;
}