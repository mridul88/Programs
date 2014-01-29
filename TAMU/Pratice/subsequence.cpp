#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    const int NO_OF_SYMBOL = 26; 
    vector<vector<int> > vt(NO_OF_SYMBOL, vector<int>());
    vector<string> sub, ans;
    vector<int>::iterator it;
    string sequence, path, temp;
    ifstream file_in;
    int i, j, curr_index;
    

    getline(cin, path);
    file_in.open((path).c_str(), ifstream::in);
    if(file_in.fail())
    {
        cout << "File doesn't exists";
        return 0;
    }

    if(!file_in.eof())
        getline(file_in, sequence);
    while(getline(file_in, temp))
    {
        sub.push_back(temp);
    }
    file_in.close();
    
    /* Preprocessing*/
    for(i=0; i<sequence.length(); i++)
    {
        vt[sequence[i] - 'a'].push_back(i);
    }

    /* Main Pprogram*/
    for(i=0; i<sub.size(); i++)
    {
        int flag = 0;
        if(vt[sub[i][0]- 'a'].empty())
        {
            continue;
        }
        curr_index = vt[sub[i][0] - 'a'][0];  //first_index
        
        for(j=1; j<sub[i].length(); j++)
        {
             it = lower_bound(vt[sub[i][j]-'a'].begin(), vt[sub[i][j]-'a'].end(), curr_index);
             if( it == vt[sub[i][j] - 'a'].end())
             {
                flag = 1; 
                break;
             }
             else
             {
                int offset = it - vt[sub[i][j]-'a'].begin();
                curr_index = vt[sub[i][j] -'a'][offset];
             }
        }
        if(flag == 0)
        {
            cout << sub[i] << "\n";
        }
    }
    return 0;
}
