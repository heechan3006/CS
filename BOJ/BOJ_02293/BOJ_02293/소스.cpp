#include <iostream>

using namespace std;

int n, k;
int a[101];
int dist[10001];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	dist[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j - a[i] >= 0) dist[j] += dist[j - a[i]];
		}
	}
	cout << dist[k] << '\n';
	return 0;
}