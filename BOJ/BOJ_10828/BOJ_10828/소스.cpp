#include <iostream>
using namespace std;
const int MAXN = 1e4;
int Stack[MAXN];
int idx = -1;
void Push(int a) {
	Stack[++idx] = a;
}
void Pop() {
	if (idx == -1) cout << "-1\n";
	else cout << Stack[idx--] << "\n";
}
void Size() {
	cout << idx+1 <<"\n";
}
void Empty() {
	if (idx == -1) cout << "1\n";
	else cout << "0\n";
}
void Top() {
	if (idx == -1) cout << "-1\n";
	else cout << Stack[idx] << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	while (N--) {
		string s;
		int tmp;
		cin >> s;
		if (s == "push") {
			cin >> tmp;
			Push(tmp);
		}
		else if (s == "pop") Pop();
		else if (s == "size") Size();
		else if (s == "empty") Empty();
		else if (s == "top") Top();
	}
}