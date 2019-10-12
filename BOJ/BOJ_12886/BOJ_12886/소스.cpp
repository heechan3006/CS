#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int A, B, C;
set<string> visited;
int main() {
	scanf("%d%d%d", &A, &B, &C);
	vector<int> rock = { A,B,C };
	vector<int> tmp_v(3,0);
	vector<int> v(3,0);
	sort(rock.begin(), rock.end());
	
	queue<vector<int>> q;

	q.push({ rock });
	while (!q.empty()) {

		v = q.front();
		q.pop();
		if (v[0] == v[1] && v[1] == v[2] && v[0] == v[2]) {
			printf("1");
			return 0;
		}
		string s = "";
		for (int i = 0; i < 3; i++) {
			s += to_string(v[i]);
		}
		visited.insert(s);
		for (int i = 1; i < 3; i++) {
			string tmp_s = "";
			for (int k = 0; k < 3; k++) {
				tmp_v[k] = v[k];
			}
			int tmp = tmp_v[0];
			tmp_v[0] *= 2;
			tmp_v[i] -= tmp;
			sort(tmp_v.begin(), tmp_v.end());
			for (int j = 0; j < 3; j++) {
				tmp_s += to_string(tmp_v[j]) ;
			}
			if (!visited.count(tmp_s)) {
				visited.insert(tmp_s);
				q.push(tmp_v);
			}
		}
	}
	printf("0");
}
