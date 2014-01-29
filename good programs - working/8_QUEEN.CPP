#include<stdio.h>
#include<conio.h>
int
is_safe(int rows[8], int x, int y)
{
	 int i;

	 for (i=1; i <= y; ++i) {
		  if (rows[y-i] == x || rows[y-i] == x-i || rows[y-i] == x+i)
				return 0;
	 }

	 return 1;
}

void
putboard(int rows[8])
{
	 static int s = 0;
	 int x, y;

	 printf("\nSolution #%d:\n---------------------------------\n", ++s);
	 for (y=0; y < 8; ++y) {
		  for (x=0; x < 8; ++x)
				printf(x == rows[y] ? "| Q " : "|   ");
		  printf("|\n---------------------------------\n");
	 }
	 getch();
}

void
eight_queens_helper(int rows[8], int y)
{
	 int x;

	 for (x=0; x < 8; ++x) {
		  if (is_safe(rows, x, y)) {
				rows[y] = x;
				if (y == 7)
				  putboard(rows);
				else
				  eight_queens_helper(rows, y+1);
		  }
	 }
}

int
main()
{
	 int rows[8];

	 eight_queens_helper(rows, 0);
	 getch();
	 return 0;
}

