#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
struct node {
	char name[55];
	int length;
};
node book[20010];
void quicksort(int L, int R)
{
	int i = L, j = R;
	node pivot = book[(L + R) / 2];

	while (i <= j)
	{
		while (book[i].length < pivot.length || (book[i].length == pivot.length && strcmp(book[i].name, pivot.name) < 0))
			i++;

		while (book[j].length > pivot.length || (book[j].length == pivot.length && strcmp(book[j].name, pivot.name) > 0))
			j--;

		if (i <= j)
		{
			node tmp;
			tmp = book[i], book[i] = book[j], book[j] = tmp;
			i++, j--;
		}
	}
	if (L < j)
		quicksort(L, j);
	if (i < R)
		quicksort(i, R);
}

int main() {
	
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++){
		scanf("%d",&N);
		
		for (int i = 1; i <= N; i++) {
			
			scanf(" %s", book[i].name);
			book[i].length = strlen(book[i].name);
		}
		quicksort(1, N);
		printf("#%d\n",test_case);
		for (int i = 1; i <= N; i++) {
			if (book[i].length == book[i - 1].length) {
				if (strcmp(book[i].name, book[i - 1].name) != 0) {
					printf("%s\n", book[i].name);
				}
			}
			else {
				printf("%s\n", book[i].name);
			}
		}
	}
	return 0;
}