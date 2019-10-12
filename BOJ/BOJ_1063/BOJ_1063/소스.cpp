#include <iostream>

using namespace std;
int king_sx, king_sy, rock_sx, rock_sy;
bool is_range(int x, int y) {
	if (x < 1 || y < 0 || x > 8 || y > 7) return false;
	return true;
}
char alpha[] = { 'A','B','C','D','E','F','G','H' };
int main() {
	string s1, s2;
	int N;
	cin >> s1 >> s2 >> N;
	king_sx = (int)(s1[1] - '0');
	king_sy = (int)(s1[0] - 'A');
	rock_sx = (int)(s2[1] - '0');
	rock_sy = (int)(s2[0] - 'A');
	int nx, ny,rock_nx,rock_ny;

	while (N--) {
		string order;
		cin >> order;
		nx = king_sx;
		ny = king_sy;
		rock_nx = rock_sx;
		rock_ny = rock_sy;
		for (int i = 0; i <(int)(order.length()); i++){
			if (order[i] == 'R') {
				ny +=  1;
				rock_ny +=  1;
			}
			else if (order[i] == 'L') {
				ny -= 1;
				rock_ny -= 1;
			}
			else if (order[i] == 'B') {
				nx -= 1;
				rock_nx -= 1;
			}
			else if (order[i] == 'T') {
				nx += 1;
				rock_nx += 1;
			}
		}
		if (!is_range(nx, ny)) continue;
		if (nx == rock_sx && ny == rock_sy && is_range(rock_nx, rock_ny) ) {
			rock_sx = rock_nx;
			rock_sy = rock_ny;
			king_sx = nx;
			king_sy = ny;
		}
		else if (nx != rock_sx || ny != rock_sy) {
			king_sx = nx;
			king_sy = ny;
		}
	}
	cout << alpha[king_sy] << king_sx << "\n";
	cout << alpha[rock_sy] << rock_sx << "\n";
	return 0;
}