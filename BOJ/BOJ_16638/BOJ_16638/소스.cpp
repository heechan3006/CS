#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#define MAXN 20
#define INF 987654321
using namespace std;

int N;
string map;
bool used[MAXN];
int ans;
int calculate(int a, int b, char op) {
	if (op == '+') return a+b;
	else if (op == '-') return a-b;
	else if (op == '*') return a*b;
}
int get_result() {
	vector<string> v;
	string tmp ="";
	int i = 0;
	while (i <= N){
		if (used[i]) {
			int a = map[i] -'0';
			int b = map[i + 2] -'0';
			char op = map[i + 1];
			v.push_back(to_string(calculate(a, b, op)));
			i += 3;
		}
		
		else {
			tmp = map[i];
			v.push_back(tmp);
			i++;
		}
	}
	vector<string> v1;
	
	i = 0;
	while (i < v.size()){
		if (v[i] == "*") {
			int a = stoi(v1[v1.size() - 1]);
			int b = stoi(v[i + 1]);
			char op = v[i][0];
			v1.pop_back();
			v1.push_back(to_string(calculate(a, b, op)));
			i+=2;

		}
		else {
			v1.push_back(v[i]);
			i++;
		}
	}
	int res = stoi(v1[0]);
	for (int i = 1; i < v1.size(); i+=2) {
		if (v1[i] == "+") {
			res += stoi(v1[i+1]);
		}
		else if (v1[i] == "-") {
			res -= stoi(v1[i+1]);
		}
	}
	return res;
}
void dfs(int now) {
	ans = max(ans, get_result());
	for (int i = now; i < N; i += 2) {

		if (!used[i] && !used[i + 2]&& i < N-1) {
			used[i] = true;
			used[i + 2] = false;
			dfs(now + 2);
			used[i] = false;
			used[i + 2] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	cin >> map;
	ans = -INF;
	dfs(0);
	cout << ans << "\n";
	return 0;
}