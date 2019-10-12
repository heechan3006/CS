#include <iostream>
#include <cstring>
#include <algorithm>

#define MAXN 5000
using namespace std;

int num_count[10000];
int arr[MAXN];
int N;
int idx;

void check(int cnt) {
	if (cnt == idx) return;
	if (num_count[arr[cnt]] == 0) {
		check(cnt + 1);
		return;
	}
	if (arr[cnt]+1 == arr[cnt+1] && num_count[arr[cnt+1]] != 0) {
		if (cnt + 2 >= idx) {
			for (int i = 0; i < num_count[arr[cnt+1]]; i++) {
				cout << arr[cnt+1] << " "; 
			}
			num_count[arr[cnt+1]] = 0;
		}
		for (int i = 0; i < num_count[arr[cnt]]; i++) {
			cout << arr[cnt] << " ";
		}
		num_count[arr[cnt]] = 0;
		if (cnt+2 < idx){
			cout << arr[cnt+2] << " ";
			num_count[arr[cnt+2]]--;
		}
	}
	else{
		for (int i = 0; i < num_count[arr[cnt]]; i++) {
			cout << arr[cnt] << " ";
		}
		num_count[arr[cnt]] = 0;
	}
	check(cnt + 1);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int test_case=1; test_case<=t; test_case++){
		cin >> N;
		idx = 0;
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			if (num_count[tmp] == 0) {
				num_count[tmp]++;
				arr[idx] = tmp;
				idx++;
			}
			else {
				num_count[tmp]++;
			}
		}
		sort(arr, arr + idx);
		cout << "#" << test_case << " ";
		check(0);
		cout << "\n";
	}
}