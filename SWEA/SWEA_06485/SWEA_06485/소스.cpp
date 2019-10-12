#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N,P;

int node[5000];
int C[5000];
vector<int> v;
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case=1; test_case<=t; test_case++){
		scanf("%d", &N);
		int a, b,c;
		memset(node, 0, sizeof(node));
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &a, &b);
			for (int j = a; j < b+1; j++) {
				node[j-1]++;
			}
		}
		scanf("%d", &P);
		for (int i = 0; i < P; i++) {
			scanf(" %d", &c);
			v.push_back(node[c-1]);
		}
		printf("#%d ", test_case);
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
		
		v.clear();
	}
	return 0;
}