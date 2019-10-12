#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int A, B, C;
bool visited[200][200][200];

int main() {
	cin >> A >> B >> C;
	int cap[] = { A,B,C };
	queue<tuple<int,int,int>> q;
	vector<int> result;
	q.push(make_tuple( 0,0,C ));
	
	while (!q.empty()) {
		int a, b, c;
		tie(a, b, c) = q.front();
		q.pop();
		if (visited[a][b][c]) continue;
		visited[a][b][c] = true;
		if (a == 0) result.push_back(c);
		
		
		// a->b
		if (a + b > B) {
			q.push({ a + b - B,B,c });
		}
		else {
			q.push({ 0,a + b,c });
		}
		// a->c
		if (a + c > C) {
			q.push({ a + c - C,b,C });
		}
		else {
			q.push({ 0,b,a + c });
		}
		// b->a
		if (b + a > A) {
			q.push({ A,a + b - A,c });
		}
		else {
			q.push({ a + b, 0, c });
		}
		// b->c
		if (b + c > C) {
			q.push({ a,b + c - C,C });
		}
		else {
			q.push({ a,0,b + c });
		}
		//c->a
		if (c + a > A) {
			q.push({ A,b,c + a - A });
		}
		else {
			q.push({ c + a,b,0 });
		}
		// c->b
		if (c + b > B) {
			q.push({ a, B, c + b - B });
		}
		else {
			q.push({ a,c + b,0 });
		}
		
	}
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}
}