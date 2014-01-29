#include <iostream>
using namespace std;

class node
{
public:
    node()
    {
       printf("created\n");   
        x=new int[0];
        next=NULL;
    }
    ~node()
    {
       printf("delete\n");    
        delete x;
    }

    int* x;
    node* next;
};

class LinkedQ
{
    node* last;
    node* start;

public:
    LinkedQ()
    {
        start=NULL;
        last=NULL;
    }
    void insert(int x)
    {
        if (start==NULL)
        {
            start=last=new node();
        }
        else
        {
            last->next=new node();
            last=last->next;
        }
        *(last->x)=x;
        //printf("%d\n",*(last->x));
    }
    void insert(node x)
    {
        if (start==NULL)
        {
            start=last=new node();
        }
        else
        {
            last->next=new node();
            last=last->next;
        }
        *(last->x)=*(x.x);
       // printf("%d\n",*(last->x));
    }
    int remove()
    {
        if (start==NULL)
            return 0;
        int ret=*start->x;
        start=start->next;
        return ret;
    }
    void display()
    {
        if (start==NULL)
        {
            cout<<"\nEmpty Queue\n";
            return;
        }
        cout<<"\nQueue:\n";
        for (node* temp=start;temp!=NULL;temp=temp->next)
            cout<<*temp->x<<" ";
        cout<<"\n";
    }
};

int main()
{
    //int i=5;
    LinkedQ l;
    l.insert(1);
    node a;
    *(a.x)=5;
    printf("--%d--\n",*(a.x));
    l.insert(a);
    printf("...............\n");
    //(a.x)=&i;
    //printf("--%d--\n",*(a.x));
    l.insert(*(a.x));
    l.insert(2);
    l.display();
    getchar();
    getchar();
    return 0;
}
