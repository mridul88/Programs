#include<stdio.h>

struct question_node
{
        int question;
        int no_incorrect;
        struct question_node * next;
};

struct team_node
{
        int team,correct,time;
        struct question_node *incorrect;
        struct team_node *next;
}*start=NULL;
struct team_node *last= NULL;

struct question_node * search_incorrect(struct question_node **start, int question)
{
       return NULL;
} 

int insert_incorrect(struct question_node **start, int question)
{
    return 0;
}

struct team_node  * search_team(int n)
{
           struct team_node *temp; 
           if(start==NULL)
                  return NULL;

            temp=start;
            while(temp!=NULL)
            {
                    if(temp->team==n)
                             return temp;
            }
            return NULL;
}                       
                                                
int insert(int team,int question,int time,int status)
{
         struct team_node* temp,*r;         
         temp=search_team(team);
         if(temp==NULL)
         {
                  r=malloc(sizeof(struct team_node));
                  r->team=team;
                  r->incorrect=NULL;
                  r->time=0;
                  r->correct=0;
                  if(status=='I')
                                 insert_incorrect(&r->incorrect,question);
                  else if(status =='C')
                  {
                              r->correct=1;
                              r->time=time;
                  }
                  last->next=r;
                  r->next=NULL;
                  last=last->next;
         }
         else
         {
                  if(status=='I')
                  {
                                 struct question_node *q;
                                 q=search_incorrect(&temp->incorrect,question);
                                 if(q==NULL)  
                                              insert_incorrect(&r->incorrect,question);
                                 else
                                               q->no_incorrect++;
                  }                         
                  else if(status =='C')
                  {
                              struct question_node *q;  
                              q=search_incorrect(&temp->incorrect,question);
                              if(q==NULL)  
                                           r->time=time;
                              else
                                           r->time=r->time + 20 * q->question;
                              r->correct++;
                  }
         }
         return 0;
}    
             
                                                                                                                       
int main()
{
    
    printf("manu");
}          
        
               
        
        
        
