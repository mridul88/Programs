/* generate random number*/

#include <cstdlib>
#include <cstdio>
#include <ctime>

int main(void)
{
   int i,j;

      for(j=0;j<150;j++)
      {
     // randomize();
      for(i=0;i<200;i++)
      printf("%d\n", rand()%200);
      getchar();
      }
   return 0;
}
