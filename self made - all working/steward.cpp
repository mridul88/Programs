#include<stdio.h>


int main()
{
	int a[100000],r,disorder=0,d[100000],large,j,i;
	scanf("%d",&r);
	for(i=0;i<r;i++)
	{
         scanf("%d",&a[i]);	
		d[i]=0;
    }
   
	for(int i=1;i<r;i++)
    {
            large=0;          // its n^2, but its order will decrease if the string is nearly sorted
            int flag=0;        // and contain all numbers within a range.
            for(j=i-1;j>=0;j--)
            {
                      if(a[j]< a[i] && d[j]==0)
                      {
                               d[i]=large;
                               flag=1;
                               break;
                      }
                      else if(a[j]==a[i]+1)
                      {
                              d[i]=d[j]+large+1;
                              flag=1;
                              break;
                      }
                      else if(a[j]>a[i]+1)
                      {
                              large++;
                      }
            }
            if(flag==0)
                 d[i]=large;
            disorder=disorder+d[i];     
    }                              
	printf("%d",disorder);
	return 0;
}
