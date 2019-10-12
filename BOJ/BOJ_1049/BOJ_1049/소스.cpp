#include <iostream>
#include <algorithm>
#define INF 98765432
using namespace std;
int N, M;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int min_pac = INF;
	int min_one = INF;
	int ans;
	for (int i = 0; i < M; i++) {
		int pac, one;
		cin >> pac >> one;
		min_pac = min(min_pac, pac);
		min_one = min(min_one, one);
	}
	// �����θ� ��°��
	if (min_pac >= min_one * 6) {
		cout << min_one * N << "\n";
		return 0;
	}
	// ��, ���� ���ΰ��
	else {
		ans = (N/6)*min_pac;
		// �����θ� ��� ���
		if ((N % 6) * min_one >= min_pac) {
			ans += min_pac;
		}
		// ������ ����
		else {
			ans += min_one * (N % 6);
		}
	}
	cout << ans << "\n";
	return 0;
}