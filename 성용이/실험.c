#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char a[4];
	char b[4];

	char x;
	
	scanf("%s", a);
	scanf("%s", b);

	x = a[0];
	a[0] = a[2];
	a[2] = x;

	x = b[0];
	b[0] = b[2];
	b[2] = x;

	if (a[0] > b[0])
		printf("%s\n", a);
	else if ((a[0] = b[0]) && (a[1] > b[1]))
		printf("%s\n", a);
	else if ((a[0] = b[0]) && (a[1] = b[1]) && (a[2] > b[2]))
		printf("%s\n", a);
	else printf("%s\n", b);

	return 0;
}
