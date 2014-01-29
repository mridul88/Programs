#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<fstream>
#include<queue>
#include<stack>

using namespace std;

/* True - if the edit distance = = 1*/
bool Is_edge(string source, string target)
{
    int count = 0;
    for(int i=0; i<source.length(); i++)
    {
        if(source[i]!= target[i])
            count++;
    }
    return (count ==1 ? true: false);
}

int main()
{
       string path, word, source, target;
       queue<string> q;
       stack<string> ans;

       map<string, string> dict;
       map<string, string>::iterator it; 

       ifstream in_file;
       int len = 0, i;

       getline(cin, path);
       in_file.open(path.c_str(), ifstream::in);
       if(in_file.fail())  // or diretly use if(!in_file)
       {
            cout << "File path Invalid\n";   // Checking Error
            return 0;
       }
       while(!in_file.eof()) 
       {
           getline(in_file, word);
           dict[word] = "";  //parent is NULL
       }
       in_file.close();

       cin >> source;
       cin >> target;
        
       /*Source and target must be in the dict*/
       if( dict.find(source) == dict.end() || dict.find(target) == dict.end() )
        {
            cout << "The Words does not exist in the dictionary\n";
            return 0;
        }

       q.push(source);
       dict.find(source)->second = source;   //parent of source is source itself
       while( !q.empty())
       {
            string curr = q.front();
            q.pop();
            for(it = dict.begin(); it != dict.end(); it++)
            {
                if(it->second == "" && Is_edge(curr, it->first))
                {
                    if(it->first == target) /* Print the path */
                    {                       
                        cout<< len << endl;
                        ans.push(target);
                        it = dict.find(curr);  
                        while( it->first != source)
                        {
                            ans.push(it->first);
                            it = dict.find(it->second);  //Moving up to the parent
                        }
                        ans.push(source);

                        while(!ans.empty())
                        {
                            cout << ans.top();
                            if(ans.size() >1)
                                cout << " -> ";
                            ans.pop();
                        }
                        return 0;

                    }
                    else
                    {
                        q.push(it->first);
                        it->second = curr;  // Save parent of this node
                    }

                }
            }
            len++;
       }
       cout <<"Impossible\n";
       return 0;
}
