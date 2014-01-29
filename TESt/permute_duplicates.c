# include <stdio.h>

 
/* Function to swap values at two pointers */
int swap (char *x, char *y,int i, int j)
{
    char temp;
    if(i==j || (*x!=*y && i!=j) )
    {
         temp = *x;
         *x = *y;
         *y = temp;
         return 1;
    }
    return -1;
}
 
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n)
{
   int j;
   static int count=1;
   if (i == n)
     printf("%4d.  %s\n",count++,a);
   else
   {
        for (j = i; j <= n; j++)
       {
          if(swap((a+i),(a+j),i,j)==1)
          {
                 permute(a, i+1, n);
                 swap((a+i),(a+j),i,j); //backtrack
          }
       }
   }
}
 
/* Driver program to test above functions */
int main()
{
   char a[] = "ABCD";
   permute(a,0,strlen(a)-1);
   getchar();
   return 0;
}
