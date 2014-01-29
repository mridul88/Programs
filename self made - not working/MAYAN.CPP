/* this is a question to implement Mayan claender, questioin of BIO-2004 ,questioin no. 1*/
// Needs improvement for accepting 1 1 1 1 1.
#include<cstdio>
#include<cstdlib>

using namespace std;

int month(long int x,long int y,long int *m)
{
	  if(x>31)
	  {   *m=1;
			x=x-31;
			if(x>28+(y%4==0?1:0))
			{
				x=x-(28+(y%4==0?1:0));
				*m=2;
				for(int i=0;i<2;i++)
				{
					if(x>31)
					{
						x=x-31;
						*m++;
						if(x>30)
						{
							x=x-30;
							*m++;
						}
						else
						 {*m=*m+1;	return(x);   }
					 }
					  else
						 {++*m;	return(x); }
				}
			}
			else
			  {  ++*m;	return(x); }
	}
	else
		return(x);
  if(x>31)
  {
		*m=7;
		x=x-31;
		for(int i=0;i<2;i++)
		{
			if(x>31)
			{	*m++;
				x=x-31;
				if(x>30)
				{
					x=x-30;
					*m++;
				}
				else
				  { *m=*m+1;	return(x); }
			}
			else
			 {++*m;	return(x);}
		 }
  }
  else
  { *m=7;	return(x);}
  *m=12;
  return(x-31);
}
int main()
{
	  long int x,b,k,kin,u,t,y=2000,d=0,m=1;
	  printf("enter the value of kin, uinal,tun,katun,baktun respectively");
	  scanf("%ld %ld %ld %ld %ld",&b,&k,&t,&u,&kin);
	  x=((((((((b*20)+k)*20)+t)*18)+u)*20)+kin)-2018842;  // subtraced to work as per output.
	  while(x>365+(y%4==0?1:0))
		{
			x=x-(365+(y%4==0?1:0));
			y++;
		}
	  d = month(x,y,&m);
	  int w=x%7;
	   printf("\ndate: %ld\\%ld\\%ld",d,m,y);
	  switch(w)
	  {
		case 1: printf("\t Saturday");
				break;
		case 2: printf("\t Sunday"); break;
		case 3: printf("\t Monday"); break;
		case 4: printf("\t Tuesday");break;
		case 5: printf("\t Wednesday");break;
		case 6: printf("\t Thrusday");break;
		case 0: printf("\t Friday"); break;
  }
  	while(getchar()!='\n');
	getchar();
   return 0;
}
