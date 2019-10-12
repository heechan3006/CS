#include <iostream>

using namespace std;

unsigned long long n;

int main() {
	scanf("%11u",&n);
	int check = 0;
	unsigned long long turn = 1;
	unsigned long long mul = 1;
	while (turn < n) {
		if (!check) {
			mul *= 4;
		}
		turn += mul;
		check = !check;
	}
	printf("%s\n", check ? "Alice" : "Bob");
	
}
