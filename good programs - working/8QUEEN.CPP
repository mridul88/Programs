#include <stdio.h>
#include <assert.h>

#define SQUARES 8

void column(int *row, int c, int squares);
int ok(int *row, int c, int r);
void solution(int *row, int squares);

int main(void)
{
int row[SQUARES + 1];

assert(sizeof row / sizeof *row - 1 != 0);
row[0] = 0;
column(row, 1, sizeof row / sizeof *row - 1);
getchar();
return 0;
}

void column(int *row, int c, int squares)
{
int r = squares;

do {
if (ok(row, c, r)) {
row[c] = r;
if (c == squares) {
solution(row, squares);
break;
}
column(row, c + 1, squares);
}
} while (--r != 0);
}

int ok(int *row, int c, int r)
{
const int p = c + r, m = c - r;

do {
--c;
} while (c && r != row[c] && p != c+row[c] && m != c-row[c]);
return c == 0;
}

void solution(int *row, int squares)
{
int c = 1;

++row[0];
printf("\n\n\nSOLUTION # %d\n\n", row[0]);
do {
printf("COLUMN %d, ROW %d\n", c, row[c]);
} while (c++ != squares);
}
