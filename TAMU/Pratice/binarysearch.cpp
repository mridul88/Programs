/* Input - Enter the size of array n and range of the numbers.
  Ouput - Print the array in sorted manner
  Input - Enter the number
  Output - Print the index if found
         - lower bound - gives the min index if found otherwise largest index of the number smaller than key
*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

vector<int> ans;

int binary_search(const vector<int>& a, const int left, const int right, const int key)
{
    static int index = -1, mid;
   
    if(left > right || (right - left+1) > (signed)a.size() || left < 0 || right >= (signed)a.size()) // Error case
         return index;    

    mid = left + (right - left)/2;

    if(a[mid] == key)
        index = mid;
    else if(key < a[mid])
        binary_search(a,left,mid-1,key);
    else
        binary_search(a,mid+1,right, key);
    
    return index;
}

int lowerbound(const vector<int>&a, const int n, const int key)
{
    int low =0, high = n-1, mid, flag =0;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(key < a[mid])
            high = mid-1;
        else if(key > a[mid])
            low = mid+1;
        else
        {
            flag = 1;
            break;
        }
    }
    
    if(key > a[n-1])   // key > a[n-1]
        return n;
    else if(key< a[0]) // key < a[0]
        return 0;
    else if(low == high)  // key is unique
        return low;
    else if(flag ==1) // key found but not unique
    {
        low = 0; high = mid;
        while(low < high)
        {
            mid = low +(high-low)/2;
       //     printf("loop - low = %d, mid = %d high = %d\n", low, mid, high);
            if(a[mid] == key)
                high = mid;
            else
                low = mid+1; 
        }
        return low;
    }
    else
    {
        return high;
    }
    return -1;
}

vector<int> searchRange(const vector<int>& a, const int n, const int key)
{
    int low =0, high = n-1, mid, flag =0, temp;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(key < a[mid])
            high = mid-1;
        else if(key > a[mid])
            low = mid+1;
        else
        {
            flag = 1;
            temp = mid;
            break;
        }
    }
    if(flag ==1) 
    {
        low = 0; high = temp;    // finding lower bound
        while(low < high)
        {
            mid = low +(high-low)/2;
            if(a[mid] == key)
                high = mid;
            else
                low = mid +1;
        }
        ans.push_back(low);
        
        low = temp; high = n-1;  //finding upper bound
        while(low < high)
        {
            mid = low + (high-low)/2;
            //printf("loop - low = %d, mid = %d high = %d\n", low, mid, high);
            if(a[mid] == key)
                low = mid+1;
            else
                high = mid;
        }
        if(a[low] == key)
            ans.push_back(low);
        else
            ans.push_back(low-1);
    }
    else //Key not found
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    
    return ans;
}

int FindPivot(vector<int>& a, int size)
{
    int low =1, high= size-1, mid;
    /*for(int i=0;i<size;i++)
    {
        printf("%d at %d\n", a[i],i);
    }*/
    if(size ==1)
        return 0;
    while(low < high)
    {
        mid = low +(high-low)/2;
        //printf("%d %d %d ->", low, mid, high);
        if( a[mid-1] <= a[mid] && a[mid] <= a[mid +1]) //in ascending order
            low = mid +1;
        else if(a[mid-1] >= a[mid] && a[mid] >= a[mid+1])
            high = mid -1;
        else if(a[mid] > a[mid-1] && a[mid] > a[mid+1])
        {
         //   printf("leaving at %d -- %d %d %d  ", a[mid], low, mid, high);
            break;
        }
       // printf("%d %d %d\n",low,mid,high);
    }
    if(high ==0)
        low = high;
    return low;
}

int SearchRotated(vector<int>& a, int n, int key)
{
    int pivot = FindPivot(a,n);
    if(key == a[pivot])
        return pivot;
    int index = binary_search(a,0,pivot-1,key);
    if(index !=-1)
        return index;
    return binary_search(a,pivot+1,n-1,key);
}
    
int main()
{
    int i,size,n;
    vector<int> a;
    cin >> size >>n;
    for(i=0; i<size; i++)
        a.push_back(rand()%n);

    sort(a.begin(), a.end());
    for(i=0;i<size;i++)
    {
        cout << a[i];
        if(i+1 != size)
            cout <<",";
        else
            cout <<endl;
    }
    cin >> n;
    cerr << "Found at= " << binary_search(a,0,size-1,n);
    cerr << "lower bound at= " << lowerbound(a,size,n);
    searchRange(a,size,n);
    cout << "Range is= ["<< ans[0] <<"," <<ans[1] <<"]\n";
    cout << "Enter array- ";
    for(i=0;i<size;i++)
    {
        cin >> a[i];
    }
    cout <<"Enter key- ";
    cin >>n;
    cout << SearchRotated(a,size,n);
    return 0;
}
