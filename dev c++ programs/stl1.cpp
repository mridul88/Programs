#include<cstdio>
#include<iostream>
#include<new>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,k,l,r,c,w,n;   
    vector<int> a(4);
    vector<int> :: iterator p;
    cout<<"enter the no. of nodes";
    cin>>n;
    p=a.begin();
    for(i=0;i<n*n;i++)
    {                a.push_back(1);
                     cout<<a[i];
    }
    cout<<"size : " <<(a).size();    
    cin.clear();
    while(cin.get()!='\n');
    cin.get();                                                                  
    return 0; 
}
