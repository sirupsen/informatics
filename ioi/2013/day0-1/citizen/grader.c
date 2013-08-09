#include <stdio.h>
#include <stdlib.h>
#include "citizen.h"

#define fail(s, x...) do { \
		fprintf(stderr, s "\n", ## x); \
		exit(1); \
	} while(0)

#define MAX_N 100000

int P[MAX_N];
int Q[MAX_N];

int main() {
	int N, i;
	int res;

	FILE *f = fopen("citizen.in", "r");
	if (!f)
		fail("Failed to open input file.");

	res = fscanf(f, "%d", &N);
	if (res != 1)
		fail("Failed to read N from input file.");

	if (N < 1 || N > MAX_N)
		fail("N is out of bounds.");

	for (i = 0; i < N; i++) {
		res = fscanf(f, "%d%d", &P[i], &Q[i]);
		if (res != 2)
			fail("Failed to read data from input file.");
	}
	fclose(f);

	int answer = countries(N, P, Q);

	printf("%d\n", answer);

	return 0;
}
