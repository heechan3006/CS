#include <iostream>
using namespace std;

int N, A, B;

int main() {
	cin >> N >> A >> B;
	int cnt = 0;
	while (A != B) {
		if (A % 2 == 0) {
			A /= 2;
		}
		else if (A % 2 == 1) {
			A++;
			A /= 2;
		}
		if (B % 2 == 0) {
			B /= 2;
		}
		else if (B % 2 == 1) {
			B++;
			B /= 2;
		}
		cnt++;
	}
	cout << cnt << "\n";
	return 0;
}