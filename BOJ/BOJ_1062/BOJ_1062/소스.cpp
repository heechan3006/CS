#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool visited[26];
vector<string> v;
int N, K;
char alpha[] = {'a','c','t','n','i'};
int ans = 0;

void go(int now, int cnt) {
	if (cnt == K) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			bool flag = false;
			for (int j = 0; j < v[i].size(); j++) {
				if (!visited[v[i][j]-'a']) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				sum++;
			}
		}
		if (ans < sum) ans = sum;
		return;
	}
	for (int i = now; i < 26; i++) {
		if (!visited[i]){
			visited[i] = true;
			go(i, cnt + 1);
			visited[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		v[i].erase(v[i].begin(), v[i].begin() + 4);
		v[i].erase(v[i].end()-4, v[i].end());
	}
	for (int i = 0; i < 5; i++) {
		visited[alpha[i] - 'a'] = true;
	}
	K -= 5;
	go(0, 0);
	cout << ans << "\n";
}