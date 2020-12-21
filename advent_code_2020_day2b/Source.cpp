#include <cstdio>
#include <cstring>

char passbuf[256];
int main()
{
	FILE *fin = fopen("input.txt", "r");

	if (!fin) {
		fprintf(stderr, "Unable to open input file\n");
		return 1;
	}

	int res = 0;

	int lo, hi;
	char c;
	char *s = passbuf - 1; //1-indexed passbuf
	while (fscanf(fin, "%d-%d %c: %s", &lo, &hi, &c, passbuf) == 4) {
		int count = 0;

		int len = strlen(passbuf);
		if (lo == hi)
			printf("What now?\n");
		if (lo <= len && s[lo] == c)
			count++;
		if (hi <= len && s[hi] == c)
			count++;

		if (count == 1)
			res++;
	}

	fclose(fin);
	printf("%d\n", res);

	return 0;
}