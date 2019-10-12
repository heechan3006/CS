#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int D[1001][31][2];
int num[1001];

int T, W;
int dp(int now, int move, int idx) {
	if (now == T) return 0;
	
	
	int& result = D[now][move][idx];
	if (result != -1) return result;
	if (num[now] == idx){
		if (move < W){
			result = max(dp(now + 1, move + 1, 1-idx), 1+dp(now + 1, move, idx));
		}
		else {
			result = dp(now + 1, move, idx)+1;
		}
	}
	else{
		if (move < W) {
			result = max(1+dp(now + 1, move + 1, 1 - idx), dp(now + 1, move, idx));
		}
		else {
			result = dp(now + 1, move, idx) ;
		}
	}
	return result;
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T >> W;
	for (int i = 0; i < T; i++) {
		cin >> num[i];
		num[i]--;
	}
	memset(D, -1, sizeof(D));
	int ans = dp(0, 0, 0);
	cout << ans << "\n";
}