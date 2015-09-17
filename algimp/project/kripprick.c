#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <ctype.h>

static unsigned long long	fm_count;
static volatile bool		proceed = false;

static void done(int unused)
{
	proceed = false;
	unused = unused;
}
	
unsigned long long kripprick(char* aname, char* cname, int seconds)
{
	FILE*		afile = fopen(aname, "r");
	FILE*		cfile = fopen(cname, "r");

	fm_count = 0;

	if (afile == NULL) {
		fprintf(stderr, "could not open file A\n");
		exit(1);
	}

	if (cfile == NULL) {
		fprintf(stderr, "could not open file c\n");
		exit(1);
	}

	/* read A and c files. */

	int rows;
	int cols;
	fscanf(afile, "%d", &rows);
	fscanf(afile, "%d", &cols);

	int i;
	int j;
	int a[rows][cols];
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			int number;
			fscanf(afile, "%d", &number);
			a[i][j] = number;
		}				
	}

	int c_rows;
	fscanf(cfile, "%d", &c_rows);
	int c[c_rows];

	for (i = 0; i < c_rows; i++) {
		int number;
		fscanf(cfile, "%d", &number);
		c[i] = number;
	}

	fclose(afile);
	fclose(cfile);

	if (seconds == 0) {
		/* Just run once for validation. */
			
		// Uncomment when your function and variables exist...
		return fm_elim(rows, cols, a, c);
		//return 1; // return one, i.e. has a solution for now...
	}

	/* Tell operating system to call function DONE when an ALARM comes. */
	signal(SIGALRM, done);
	alarm(seconds);

	/* Now loop until the alarm comes... */
	proceed = true;
	while (proceed) {
		// Uncomment when your function and variables exist...
		fm_elim(rows, cols, a, c);

		fm_count++;
	}

	return fm_count;
}

int fm_elim(int rows, int cols, int a[rows][cols], int* c) {
	while(1) {
		int n1 = 0;
		int n2 = 0;
		int n3 = 0;
		int j;
		int i;
		
		int pos[rows][cols];
		int neg[rows][cols];
		int zero[rows][cols];		
 
		for (j = 0; j < rows; j++) {
			int number = a[j][cols - 1];
			printf("Number %d\n", number);
			if (number > 0) {
				for (i = 0; i < cols; i++)
					pos[n1][i] = a[j][i];
				n1++;
			}
			else if (number < 0) {
				for (i = 0; i < cols; i++)
					neg[n1][i] = a[j][i];
				n2++;
			} else { 
				for (i = 0; i < cols; i++)
					zero[n1][i] = a[j][i];
				n3++;
			}
		}
		
		int sorted[rows][cols];
		n2 = n2 + n1;
		
		for (i = 0; i < rows; i++) {
			for (j = 0; j < cols; j++) {
				if (i < n1) 
					sorted[i][j] = pos[i][j];
				else if (i >= n1 && i < n2)
					sorted[i][j] = neg[i - n1][j - n1];
				else 
					sorted[i][j] = zero[i - n2][j - n2];
			}
		}
		printf("Sorted\n");
		for (j = 0; j < rows; j++) {
			for (i = 0; i < cols; i++) {
				printf("%d ", sorted[j][i]);
			}
		printf("\n");
		}

	}
}