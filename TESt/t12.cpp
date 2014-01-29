#include<cstdio>

using namespace std;

class Room;
class Room
    {
          int w,h;
          static int count ;
          
          public:
          Room()
          {
                w=3;
                h=6;
          }      
          Room(int wi,int ht)
          {
              w=wi;
              h=ht;
          }
          void static setcount()
          {
                 count++;
          }
          
          int display()
          {
              printf("%d %d\n",count);
          }
};

int Room::count =10;

int area()
{
    int w,h;
    Room r;
    r.setcount();
    //r.display();
}

int main()
{
    Room r;
    r.setcount();
    r.display();
    getchar();
    return 0;
}
              
                 
