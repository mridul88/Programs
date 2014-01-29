#include<cstdio>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

int max(int ans[1001][1001], int row, int col, int n)
{
    int a,b,c,d;
    a=b=c=d=0;

    if( (row-2) >=0 && (col+1) < n) 
        a = ans[row-2][col+1];
    if( (row-1) >=0 && (col+2) < n) 
        b = ans[row-1][col+2];
    if( (row+1) <n && (col+2) < n) 
        c = ans[row+1][col+2];
    if( (row+2) <n && (col+1) < n) 
        d = ans[row+2][col+1];

    if(a<b)
        a=b;
    if(c<d)
        c=d;
    if(a<c)
        a=c;

    return a;
}

int main()
{
    int t, i,j, k_x, k_y;
    cin >> t;
    while(t--)
    {
        int n;
        char c;
        cin >>n;
        char board[1001][1001];
        int ans[1001][1001];
        /*vector<vector<char> > board(n);
        vector<vector<int> >ans(n);

        for(i=0;i<n;i++)
        {
            board[i].resize(n);
            ans[i].resize(n);
        }*/

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin >> c;
                if(c=='.')
                    board[i][j]=0;
                else if(c == 'K')
                {
                    k_x = i;
                    k_y = j;
                    board[i][j]=0;
                }
                else if(c == 'P')
                {
                    board[i][j]= 1;
                }
            }
        }
        /*Moving from right to left*/
        for(i=0;i<n;i++)
            ans[i][n-1] = board[i][n-1];

        for(i=n-2; i>k_y; i--)
        {
            for(j=0;j<n; j++)
            {
                ans[j][i] = board[j][i] + max(ans,j,i,n);
            }
        }
        cout << max(ans,k_x,k_y,n) << endl;
    }
    return 0;
}

