#include <cstdlib>
#include <iostream>
#include<cstdio>

using namespace std;

int main(int argc, char *argv[])
{
    int i;
    scanf("&d",&argc);
    for(int i=0;i<argc;i++)
    {       
            scanf("%s",&argv[i]);
            printf("%s",argv[i]);
            }    
    system("PAUSE");
    return EXIT_SUCCESS;
}
