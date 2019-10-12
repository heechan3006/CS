#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int T;
	int N ;
	cin >> T;
	vector<string> cards;
	for (int t_case = 0; t_case < T; t_case++) {
		cin >> N;
		
		cout << "#" << t_case + 1;

		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			cards.push_back(s);
		}

		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) {
				cout << " " << cards[i / 2];
			}
			else if (N % 2 == 0) {
				cout << " " << cards[N / 2 + i / 2];
			}
			else {
				cout << " " << cards[N / 2 + 1 + i / 2];
			}
		}

		cout << "\n";
		cards.clear();
	}

	return 0;
}