#include "fog.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Bounds for N (length of the shoreline) */
#define MIN_N 1
#define MAX_N 100000

/* Maximum number of calls to 'crossings'. */
#define MAX_CALLS 250000

/* Filenames */
#define INPUT_FILE  "fog.in"

/* Local storage */
static int N;
static int B;
static int num_calls;

/* Exit the program with an error message. */
#define fail(s, x...) \
	do { \
		fprintf(stderr, "Error: "s"\n", ##x); \
		fflush(stderr); \
		_exit(0); \
	} while(0)


/* Exit the program after a module error with an error message. */
#define failModule(s, x...) \
	do { \
		fprintf(stderr, "Module error: "s"\n", ##x); \
		fflush(stderr); \
		_exit(1); \
	} while(0)

#ifdef __cplusplus
extern "C" {
#endif
void _(int,int);void __(int,int);int ___(int,int);
#ifdef __cplusplus
};
#endif

/*
 * Initialise 
 */
int init(void)
{
	int side;
	int top_pos;
	int bottom_pos;
	int i;
	int B;
	FILE *in;

	/* Open input file */
	in = fopen(INPUT_FILE, "r");
	if (!in)
		failModule("Couldn't read input file '" INPUT_FILE "'.");

	/* Read N, B */
	if (fscanf(in, "%d", &N) != 1)
		failModule("Could not read N from " INPUT_FILE ".");
	if (fscanf(in, "%d", &B) != 1)
		failModule("Could not read B from " INPUT_FILE ".");

	/* 
	 * Validate N:
	 */
	if (N < MIN_N || N > MAX_N)
		failModule("Value of N is out of range.");

	_(N, B);

	/* Read bridges */
	top_pos = 0;
	bottom_pos = 0;
	for (i = 0; i < B; i++)
	{
		int a, b;
		if (fscanf(in, "%d%d", &a, &b) != 2)
			failModule("Could not read in bridge number %d from " INPUT_FILE ".", i + 1);

		/* Validate bridge */
		if (a < 1 || a > N)
			failModule("First position of bridge %d is invalid.", i + 1);
		if (b < 1 || b > N)
			failModule("Second position of bridge %d is invalid.", i + 1);

		/* Make sure bridges are being given left-to-right */
		if (a < top_pos && b < bottom_pos)
			failModule("Bridge %d is not in the correct order from left to right.", i + 1);
		if (a < top_pos || b < bottom_pos)
			failModule("Bridge %d overlaps a previous bridge.", i + 1);
		if (a == top_pos && b == bottom_pos)
			failModule("Bridge %d is a duplicate bridge.", i + 1);

		__(a, b);

		top_pos = a;
		bottom_pos = b;
	}

	if (fscanf(in, "%d", &i) == 1)
		failModule("Input file contains extra data.");

	/* Clean up */
	fclose(in);

	num_calls = 0;

	/* Give the value N back to the user */
	return N;
}

int row(int top, int bottom)
{
	/* Are they allowed to call us any more? */
	if (num_calls >= MAX_CALLS)
	{
		fail("You have exceeded the limit of %d calls to row.", MAX_CALLS);
	}
	num_calls++;

	/* Ensure the input is valid */
	if (top < 1 || top > N)
		fail("Invalid value '%d' for first parameter of row.", top);
	if (bottom < 1 || bottom > N)
		fail("Invalid value '%d' for second parameter of row.", bottom);

    return ___(top, bottom);
}

/*
 * Called to report the location of a bridge.
 */
void foundBridge(int top, int bottom)
{
	fprintf(stdout, "%d %d\n", top, bottom);
}
