#include <iostream>

using namespace std;
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	if (90 <= N && N <= 100) cout << "A" << "\n";
	else if (80 <= N && N < 90) cout << "B" << "\n";
	else if (70 <= N && N < 80) cout << "C" << "\n";
	else if (60 <= N && N < 70) cout << "D" << "\n";
	else cout << "F" << "\n";
	return 0;
}