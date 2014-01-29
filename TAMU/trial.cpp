#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        if(s.length() <= 2)
            cout << "Bad\n";
        else
        {
           int num =  4*s[0] + 2*s[1] + s[2];
           if(num == 2 || num == 5)
            {
                  cout << "Good\n";
                  break;
            }
           for(int i=3; i<s.length(); i++)
            {
                num = (num - 4*s[i-3])*2 + s[i];
                if(num == 2 || num == 5)
                {
                    cout << "Good\n";
                    break;
                }
            }
        }
        s.erase(s.begin());
    }
    return 0;
}


