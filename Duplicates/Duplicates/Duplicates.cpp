#include<stdio.h>

int main()
{
	int a[10] = {3,6,8,8,10,12,15,15,15,20};
	int i, j;
	for (i = 0; i < 9; i++) {
		if (a[i] == a[i + 1]) {
			j = i + 1;
			while (a[i] == a[j])
				j++;
			printf("(%d,%d)", a[i], j - i);
			i = j - 1;
		}
	}
}

