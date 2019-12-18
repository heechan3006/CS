#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n = 12;
vector<int> weak = { 1,5,6,10 };
vector<int> dist = { 1,2,3,4 };
vector<bool> used;
int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 0;
		
	do {
		vector<int> tmp_weak = weak;
		for (int i = 0; i < tmp_weak.size()-1; i++) {
			if (tmp_weak[i] > tmp_weak[i + 1]) {
				tmp_weak[i + 1] += n;
			}
			for (int i = 1; i <= dist.size(); i++) {
				dfs(0, 0,i);
			}
			
		 
	} while (next_permutation(weak.begin(), weak.end()));
	retur  answer;
}

int main() {
	solution(n, weak, dist);
}