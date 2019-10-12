#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool used[20];
char map[20];
int N;
int ans = -987654321;
int calculate(int a, int b, char op) {
	if (op == '+') {
		return a + b;
	}
	else if (op == '-') {
		return a - b;
	}
	else if (op == '*') {
		return a * b;
	}
	return 0;
}
int get_result() {
	vector<string> v;
	string tmp = "";
	for (int i = 0; i < N; i++) {
		if (used[i] && i < N-1) {
			int a = map[i] - '0';
			int b = map[i + 2] - '0';
			char op = map[i + 1];
			v.push_back(to_string(calculate(a, b, op)));
			i += 2;
		}
		else {
			tmp = map[i];
			v.push_back(tmp);
		}
	}
	int res = stoi(v[0]);
	for (int i = 1; i < v.size(); i+=2) {
		if (v[i] == "+") {
			res += stoi(v[i+1]);
		}
		else if (v[i] == "-") {
			res -= stoi(v[i+1]);
		}
		else if (v[i] == "*") {
			res *= stoi(v[i+1]);
		}
	}
	return res;
	
}
void dfs(int idx) {
	ans = max(ans, get_result());
	for (int i = idx; i < N; i += 2) {
		if (!used[i] && !used[i + 2] && i < N-1) {
			used[i] = true;
			used[i + 2] = false;
			dfs(idx + 2);
			used[i] = false;
			used[i + 2] = false;
		}
	}
}
int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	dfs(0);
	printf("%d", ans);
}