#include<stdio.h>
#include<math.h>

/*float round4(float n)
{
      int y;
      float x;
      y=n*100000;
      printf("\ny=%d n=%f",y,n);
      if(y%10>=5)
         y+= 10-(y%10);
      else
         y-= y%10;
      x=y/100000;
      return x;
}*/
         
int main()
{
     int n,i,j,tstcase;
     float *a,t,dist_moved,ans=0,diff,f_move,l_move=0;
     scanf("%d",&tstcase);
     while(tstcase--)
     {
      ans=0;
      l_move=0;               
     scanf("%d %f",&n,&t);
     a=(float *)malloc(sizeof(float)*n);
     for(i=0;i<n;i++)
           scanf("%f",&a[i]);
     
     for(i=0,j=n-1;n>1 && j-i>=0;i++,j--)//in case if only 1 person is there  
     {       
             diff= ( (n-1)-(2*i) )*t -(a[j]-a[i]);
             
             f_move=a[0];
             if(i>0)
                    f_move=a[i]-a[i-1]-t;
             if(j<n-1)
                    l_move=a[j+1]-a[j]-t;
          //   printf("diff=%f,fmove=%f,lmove=%f i=%d j=%d",diff,f_move,l_move,i,j);
             
             if(diff>0 )  
             {     
                               if( diff/2<=f_move && (diff/2<=l_move || j==n-1) )
                               {
                                          a[i]=a[i]-diff/2;
                                          a[j]=a[j]+diff/2;
                                          dist_moved=diff/2;
                                       
                     //              printf("-----|-|----\n");
                               }
                               else if(diff/2>=f_move) //forward man can move upto only f_move distance
                               {   
                                          a[i]=a[i]-f_move;
                                          a[j]=a[j]-(f_move - diff);
                                          dist_moved=(f_move> fabs(f_move - diff) ? f_move : fabs(f_move - diff) );
                                   
                   //                 printf("-|-|-------\n");
                               }
                               else if(j!=n && diff/2>=l_move)// rear man can mov only upto l_move distance
                               {
                                          a[i]=a[i]-(diff - l_move);
                                          a[j]=a[j]+l_move;
                                          dist_moved=(l_move> fabs(diff - l_move) ? l_move : fabs(diff - l_move) );
                                          
                 //                    printf("--------|-|-\n");
                               }
                               if(ans<dist_moved)
                                           ans=dist_moved;
                  
             }
             else 
             {
                               if(i>0 && a[i]-a[i-1]<t)
                               {
                                      dist_moved=t-(a[i]-a[i-1]);
                                      a[i]=a[i]+dist_moved;
                                      if(ans<dist_moved)
                                           ans=dist_moved;
               //                       printf("--|--------\n");
                               }
                               if(j<n-1 && a[j+1]-a[j]<t )
                               {
                                      dist_moved=t-(a[j+1]-a[j]);
                                      a[j]=a[j]-dist_moved;
                                      if(ans<dist_moved)
                                              ans=dist_moved;
             //                          printf("---------|-\n");
                               }
             }     
           //  printf("ans=%f\n",ans);
     }
     printf("%.4f\n",ans);
     }
     //printf("%f %f %f %f",round4(2.34657),round4(2.3),round4(2.34651),round4(4.0));
     getchar();
     getchar();
     return 0;
}        
