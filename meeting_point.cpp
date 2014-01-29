#include<iostream>
#include<vector>

using namespace std;

class Point
{
    private:
     long long int x,y;

     public:
      Point(long long int x,long long int y);
      long long int distance(Point p1, Point p2);
      long long int get_x(Point p1)
      {
          return this.x;
      }
      long long int get_y(Point p1)
      {
          return this.y;
      }
};

Point::Point(long long int x,long long int y)
{
    this.x = x;
    this.y = y;
}

inline long long int Point::distance(Point p1, Point p2)
{
    return(fabs(p1.x - p2.x) + fabs(p1.y-p2.y));
}

int main()
{
    int i,n;
    long long int x,y,mean_x=0,mean_y=0;
    scanf("%d",&n);
    vector<Point> grid(n);
    for(i=0;i<n;i++)
    {
        cin << x << y;
        grid[i](x,y);
        mean_x += x;
        mean_y += y;
    }

    Point mean_point(mean_x/n,mean_y/n);

}
