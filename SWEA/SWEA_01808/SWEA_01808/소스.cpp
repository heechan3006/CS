#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

int n,answer;
int number[10];
int datas[1000001];

int k;
int len;

void calc() {
	int num = k;
	int push_cnt = 0;
	for (int i = k; i > 1; i--) {
		while (datas[i] > 0) {
			if (num % i == 0) {
				push_cnt += 1 + datas[i];
				num /= i;
			}
			else {
				break;
			}
		}
		if (num == 1) {
			answer = push_cnt;
			return;
		}
	}
	answer = -1;
}
void create_num(int num,int cnt) {
	if (cnt > len) return;
	if (num > k) return;
	if (cnt > 0) {
		datas[num] = cnt;
	}
	for (int i = 0; i < 10; i++) {
		if (number[i] == 1){
			create_num(num * 10 + i, cnt + 1);
		}
	}
}
int main() {
	memset(number, 0, sizeof(number));
	memset(datas, 0, sizeof(datas));
	for (int i = 0; i < 10; i++) {
		cin >> number[i];
	}
	cin >> k;
	int temp = k;
	len = 0;
	while (temp > 0) {
		len += 1;
		temp /= 10;
	}
	
	if (k == 1 && number[1] == 1) {
		answer = 2;
		
	}
	else {
		create_num(0, 0);
		calc();
	}
	
	printf("%d\n", answer);
	return 0;
}