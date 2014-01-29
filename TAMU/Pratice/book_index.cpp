#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

int main()
{
    int n_pages, i, j, flag_white = 0, start;
    string page, curr_word;
    vector<string> book;
    vector<int> temp;
    map<string, vector<int> > index;
    map<string, vector<int> > ::iterator it;
    
    scanf("%d\n",&n_pages);

    for(i=0; i<n_pages; i++)
    {
        getline(cin, page);
        page.append("\n");
        book.push_back(page);
    }
    
    /* Make a vector of words*/
    for(i=0; i<n_pages; i++)
    {
        flag_white = 1;
        for(j= 0; j<book[i].length(); j++)
        {
            if(book[i][j] == ' ' || book[i][j] == '\n')
            {
                //cout <<"in white space\n";
                if(flag_white == 0)
                {
                    curr_word = book[i].substr(start, j-start); 
                    if (index.find(curr_word) == index.end())
                    {
                         vector<int> page_list;
                         page_list.push_back(i);  // Insert the page no.
                         index.insert(make_pair(curr_word,page_list)); // make a new entry in the index
                    }
                    else  // Add the page no. to the list if not present already
                    {
                        temp = index.find(curr_word)->second;
                        if( find(temp.begin(), temp.end(), i) == temp.end())
                            {
                                index.find(curr_word)->second.push_back(i);
                            }
                    }

                }
                flag_white =1;
            }
            else if( (book[i][j] >= 'a' && book[i][j]<= 'z') || (book[i][j] >= '0' && book[i][j] <= '9') )
            {
                //cout  << "in word\n";
                if(flag_white == 1)
                {
                    start = j;
                }
                flag_white = 0;
            }
        }
    }

    for(it =index.begin(); it != index.end(); ++it)
    {
        cout<< it->first << " ";
        temp = it->second;
        for(j=0;j<temp.size();j++)
        {
            cout<< temp[j];
            if(j+1 != temp.size())
                cout << ",";
        }
        if(++it != index.end())
            cout << "\n";
        it--;
    }

    /*for(i=0; i< words.size(); i++)
    {
        cout << words[i]  << "\n";
    }
    

    for(i=0; i<n_pages; i++)
    {
        cout << "book--\n" << book[i];
    }*/
    return 0;
}

