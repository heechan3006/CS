#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define MAXN 100000
using namespace std;


class Stack {
public:
	int S[MAXN] = { 0, };
	int idx = 0;
	void pop() {
		idx--;
	}
	int top() {
		return S[idx - 1];
	}
	void push(int x) {
		S[idx++] = x;
	}
	int size() {
		return idx;
	}
};
int arr[MAXN];
vector<char> ans;
int main() {
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	Stack S;

	int num = 0;
	
	for (int i = 1; i <= n; i++) {
		S.push(i);
		ans.push_back('+');
		while (S.size() && S.top() == arr[num]) {
			num++;
			S.pop();
			ans.push_back('-');
		}
	}
	if (S.size()) printf("NO\n");
	else {
		for (int i = 0; i < ans.size(); i++) {
			printf("%c\n", ans[i]);
		}
	}
	return 0;
}


