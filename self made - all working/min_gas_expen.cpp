/* this program inplement question 11.6.8 of good programing challenge*/
#include<cstdio>

using namespace std;

struct pair
{
      int distance,price;
}pump[100];

int t_cost[100],tank[100];// t_cost store total cost of gas upto ith node, tank contains amount of petrol in the tank on reaching ith petrol pump. 

int get_min(int c_pump)
{
       int minimum=c_pump-1; 
       for(int i=c_pump-1;i>0 && (pump[c_pump].distance - pump[i].distance)<=200;i--)
       {
               if(pump[i].price < pump[minimum].price)
                         minimum=i;
       }
       return minimum;
}
 
int min_cost(int s,int size) // use dynamic pogramming
{
        int c_pump=1; // current pump, c_min = current min pump
        for(c_pump=1;c_pump<=size;c_pump++)  // increament total cost till ith node
        {
                   int c_min=get_min(c_pump);   //select min price petrol pump within 200 km
                   printf("for node %d c_min :%d\n",c_pump,c_min);
                   if(c_min==0 || pump[c_min].price < pump[c_min-1].price)   // if minprice < previous pump
                   {
                            printf("AQWZ\n");
                            int temp_d=pump[c_pump].distance - pump[c_min].distance - tank[c_min];
                            tank[c_pump]=(temp_d>0?0:-(temp_d));
                            if(temp_d <=0)
                                    temp_d=0;             
                            t_cost[c_pump]=t_cost[c_min] + pump[c_min].price*temp_d;
                            
                   }
                   else // if minprice >previous min pump
                   {  //  fill tank fully (as max needed) on prev pump & fill the empty part at thus pump
                          printf("OMFGF\n");    
                          int max=pump[c_pump-1].distance-pump[c_min-1].distance;
                          if(max>200)
                                max=200;
                          int petrol_fill =max-tank[c_min-1];
                          printf("petrol_fill :%d\n",petrol_fill);  
                          if(petrol_fill<0)
                                    petrol_fill=0;   
                          t_cost[c_min]=pump[c_min-1].price*petrol_fill + t_cost[c_min-1];
                          tank[c_min]=tank[c_min-1]+petrol_fill-(pump[c_min].distance-pump[c_min-1].distance);
                          if(tank[c_min]<=0)
                                    tank[c_min]= -tank[c_min];
                          int temp_d=pump[c_pump].distance - pump[c_min].distance - tank[c_min];
                           tank[c_pump]=(temp_d>0?0:-(temp_d));
                          if(temp_d <=0)
                                    temp_d=0;
                          t_cost[c_pump]=t_cost[c_min]+pump[c_min].price * temp_d;  
                                                     
                   }
                   for(int i=1;i<=size;i++)
                   printf("total cost till node %d = %d\n tank[%d]=%d\n",i,t_cost[i],i,tank[i]);
        }
        return 0;
}
      
int main()
{
       int s,p,d,i=0,n=0,flag=0;
       pump[i].price=0;             // intialization
       pump[i].distance=0;   // add node before ist petrol pump
       tank[i]=100;
       t_cost[i]=0;
       scanf("%d%d%d",&s,&d,&p);
       if(d>100)                     // to check fpr impossible
             flag=1;
       i++;
       while(d!=s)
       {
               pump[i].price=p;
               pump[i].distance=d;
               scanf("%d%d",&d,&p);
               if(d-pump[i].distance>200)
                      flag=1;
               i++;
       }
       pump[i].distance=d;
       pump[i].price=p;
       i++;
       if(flag==1)
       {
               printf("Impossible");
               getchar();
               getchar();
               return 0;
       }
       pump[i].distance=s+100;// add last node after last pump as we need to have 100 l petrol in the tank.
       pump[i].price=2000;
       n=i;
              
       min_cost(s,n);
       getchar();
       getchar();
       getchar();
       return 0;
}
       
