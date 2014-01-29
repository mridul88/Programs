#include <iostream>
#include <cstdlib>
using namespace std;
int gopi,n,spno=1;
int count;
int ans[99999][2];

void move(int a,int b)
{
    ans[count][0]=a;
    ans[count][1]=b;
    count++;
}

void hanoi(int source,int dest,int spare,int disks)
{
    if(disks==1)
    {
        move(source,dest);
    }
    else
    {
        hanoi(source,spare,dest,disks-1);
        move(source,dest);
        hanoi(spare,dest,source,disks-1);
    }
}

void krishn(int source,int dest,int spares,int disk)
{
    if(spares==1)
    {
        hanoi(source,dest,spno,disk);
        spno++;
    }
    else
    {
        int i;
        for(i=source+1;i<=spares;i++)
        {
            krishn(i,dest,spares-1,disk-1);
        }
    }
}

int main()
{
    int i,j,c;
    cin >> n >> gopi;

    krishn(0,gopi+1,gopi,n);

    cout << count << "\n";
    for(i=0;i<count;i++)
        cout << ans[i][0] << " " << ans[i][1] << endl;
    cin.clear();
	while (cin.get() != '\n')
		;
	cin.get();
    
    return 0;
}
