#include<iostream>
#include<conio.h>
using namespace std;
class A
{
public:
       static  int i;
       static void print()
       {
           cout<< i << endl ;
       }
};
int A::i=10;
int main()
{
A a;
a.print();

getch();
}
