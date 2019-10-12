#include <iostream>
#include <algorithm>

using namespace std;

int N;
int person[1000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> person[i];
	}
	sort(person, person + N);
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += person[i];
		ans += sum;
	}
	printf("%d\n", ans);
	return 0;
}