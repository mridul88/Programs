#include<cstdio>
#include<cstring>

using namespace std;

class Simple {
public:                            Simple(int    input);
                            ~Simple() {}

    int                     getValue();
    void                    setValue();
    virtual void            resetValue();
private:

    int			      m_value;
};


Simple::Simple(int    input)
:    m_value(input)
{
}


int Simple::getValue()
{
    return m_value;
}


int main(int 	argc,
     char	**argv)
{
    Simple	theVar(10);

    printf("The value is ‘%d’\n", theVar.getValue());

    return 0;
}


typedef struct node
{
    char *p;
    struct node *next;
}list;

int compare (list *head1, list *head2)
{
    int k;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->p!=NULL && head2->p!=NULL &&((k = strcmp(head1->p, head2->p))==0))
        {
            head1 = head1->next; /* if same then only  move to next*/
            head2 = head2->next;
        }
        else if(head1->p!=NULL && head2->p!=NULL)
            return k;
        else if(head1->p!=NULL && head2->p == NULL)
            return head1->p[0];
        else if(head1->p == NULL && head2->p!=NULL)
            return -(head2->p[0]);
        else
            return 0;
    }
    if(head1==NULL && head2!=NULL && head2->p!=NULL)
        return -(head2->p[0]);
    else if(head1!=NULL && head2==NULL && head1->p!=NULL)
        return (head1->p[0]);

    return 0;
}
