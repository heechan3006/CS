#include <iostream>
#define MAXN 1000 + 1
#define MAXK 100000

using namespace std;
struct info {
	int J;
	int O;
	int I;
};

info D[MAXN][MAXN];
int N, M,K;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N >> K;
	for (int i = 1; i <= M; i++) {
		string s;
		cin >> s;
		for (int j = 0; j <s.length(); j++) {
			D[i][j+1].J = D[i - 1][j+1].J + D[i][j].J - D[i - 1][j].J;
			D[i][j+1].O = D[i - 1][j+1].O + D[i][j].O - D[i - 1][j].O;
			D[i][j+1].I = D[i - 1][j+1].I + D[i][j].I - D[i - 1][j].I;
			if (s[j] == 'J') D[i][j+1].J++;
			else if (s[j] == 'O') D[i][j+1].O++;
			else D[i][j+1].I++;
		}
	}
	while (K--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int ans_j = D[c][d].J - D[a - 1][d].J - D[c][b - 1].J + D[a - 1][b - 1].J;
		int ans_o = D[c][d].O - D[a - 1][d].O - D[c][b - 1].O + D[a - 1][b - 1].O;
		int ans_i = D[c][d].I - D[a - 1][d].I - D[c][b - 1].I + D[a - 1][b - 1].I;
		cout << ans_j << " " << ans_o << " " << ans_i << "\n";
	}
	return 0;
}

