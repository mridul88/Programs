#include<cstdio>

using namespace std;

typedef struct list
{
	int c,px,py,pz;
	struct list * next;
}node;
node *start=NULL;
int insert()
{
	node *extra,*ptr;
	extra=new(node);
	printf("enter the coff,power of x,y, z respectively");
	scanf("%d %d %d %d",&extra->c,&extra->px,&extra->py,&extra->pz);
	extra->next=NULL;
	if(start==NULL)
	{
		extra->next=start;
		start=extra;
		return 0;
	}
	ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=extra;
	return 0;
}
void print(node *ptr)
{
   while(ptr!=NULL)
   {
		printf("%dx^%dy^%dz^%d + ",ptr->c,ptr->px,ptr->py,ptr->pz);
		ptr=ptr->next;
   }
}
node *search()
{
	node *loc,*ptr;
	int c,px,py,pz;
	printf("enter the no.with coff,power of x,y,z resp. ");
	scanf("%d %d %d %d",c,px,py,pz);
	if(start==NULL)
	{
	   loc=NULL;
	   return(loc);
	}
	loc=start;
	ptr=loc->next;
	while(ptr!=NULL)
	{
		if(ptr->c==c&&ptr->px==px&&ptr->py==py&&ptr->pz==pz)
			return(loc);
		loc=ptr;
		ptr=ptr->next;
	}
	return(loc);
}
void deletion()
{
	node*loc,*temp;
	loc=search();
	temp=loc->next;
	loc->next=loc->next->next;
	delete(temp);
}
int main()
{   
	int i=0;
	while(i!=3)
	{
		print (start);
		printf("\n\n1.insert\n2.delete\n3.exit\n");
		printf("enter ur choice");
		scanf("%d",&i);
		switch(i)
		{
			case 1: insert();
						break;
			case 2: deletion();
						break;
			default : printf("enter valid option");
		}
  }
  return 0;
}

