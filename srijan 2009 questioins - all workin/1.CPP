/* To get the kth maximun value from a list of n numbers
   using STL algorithms */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long>* a;
vector<long> result;
vector<long> list;

long j,n;

int main()
{
  cout<<"enter the NO. of numbers to be entered";
  cin >> j;
  a=new vector<long>[j+1];
  long i,val;
  list.push_back(1);
  for(i=0;i<j;i++)
    {
      cin >> val;
      a[0].push_back(val);
      list.push_back(val);  
}     
  sort(a[0].begin(),a[0].end());
  sort(list.begin(),list.end());
  cout<<"enter the kth number to find kth maximum among n numbers";
  cin >>n;
  long min,minlist;
  long count=0;
  while(count<n)
    {
      min=-1; 
      for(i=0;i<j+1;i++)
	{
	  if(a[i].size()>0 && (a[i][0]*list[i]<min || min==-1))
	    {
	      min=a[i][0]*list[i]; 
       }
	}
      for(i=0;i<j+1;i++)
	{
	  if(a[i].size()>0 && a[i][0]*list[i]==min)
	    {
	      a[i].erase(a[i].begin());	      
	    }
	}
      result.push_back(min);
       count++;
      for(i=1;i<j+1;i++)
	{
	  a[i].push_back(min);
	  	  
	} 
    }
  cout << min;     
 
    cin.clear();
	while (cin.get() != '\n')
		;
	cin.get();
}























