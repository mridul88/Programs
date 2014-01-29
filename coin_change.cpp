#include <cstdio>

using namespace std;

int main()
{

    int a[3]={1,3,5},b[14];
    int i=0, j=0, s= 13,min,temp,flag;
    b[0]=0;

    for(j=1;j<=s;j++)
    {
        min = 999999;
        flag =0;
        for(i=0;i<3;i++)
        {
              if(a[i]<= j)
              {
                  if( (1 + b[j - a[i]]) < min)
                  {
                      min = 1 + b[j - a[i]];
                      //coin = i;
                  }
              }
          /*   if(b[j] == -1 && j>= a[j])
                temp = b[j-a[i]];
             else
                break;
             if(temp < min )
             {
                min = temp;
                flag =1;
             }*/
        }
        b[i] = min;
    }
    printf("%d",b[12]);
}
