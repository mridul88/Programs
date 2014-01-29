#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>


#define MAX_LENGHT 50
#define MAX_WORDS 20
#define IN 0
#define BEFORE 1
#define AFTER 2

using namespace std;

class file_read
{
    private: FILE *fp;
    public:
    file_read(char *name)
    {
        fp = fopen(name,"r");
        //fseek(fp,0,SEEK_SET);
        //int c;
        //while((c=fgetc(fp))!=EOF)
        //    putchar(c);
    }

    void write2file(char *name)
    {
            FILE *fp;
            fp= fopen(name,"w");
    }
    int getword(char **a,int j)
    {
        int c,state,i=0;
        char *p,str[MAX_LENGHT];
        state = BEFORE;
        while(state!= AFTER && (c=fgetc(fp))!=EOF && i<MAX_LENGHT)
        {
            //printf("%c__",c);
            if(isspace(c))
            {
                if(state == IN)
                    state = AFTER;
                else
                    state = BEFORE;
            }
            else if(state!=AFTER)
            {
                str[i++]=c;
          //      printf("%c",c);
                state = IN;
            }

        }
        str[i]='\0';
        //printf("%s %d\n",str, i);
        p = new char[i];
        strcpy(p,str);
        a[j]= p;
        //printf("%s",a[j]);
        return 0;
    }

    ~file_read()
    {
        fclose(fp);
    }

};

int str_cmp (const void * a, const void * b)
{
    char *at,*bt;
    int an, bn;
    at = (char *)a;
    bt = (char *)b;
    printf("%s_",at);
    for( ;*at == *bt; at++, bt++)
    {
        printf("%c..",*at);
        if(*at=='\0')  //equal string test
            return 0;
    }
    an = *at;
    bn = *bt;
    printf("%c",*at);
    printf("%d",an-bn);
    return (an-bn);
}


int main()
{
    int i,k=0;
    char *a[MAX_WORDS];
    file_read* obj = new file_read("test_file.txt");

    for(i=0;i<MAX_WORDS;i++)
    {
        obj->getword(a,i);
        printf("%s\n",a[i]);
    }
    qsort(a,i,sizeof(int *),(int(*)(const void *, const void *))(strcmp));

    for(k=0;k<i;k++)
    {
        printf("%s\n",a[k]);
    }

    for(k=0;k<=i;k++)
    {
        delete(a[k]);
        a[k] = NULL;
    }
    delete(obj);
    obj = NULL;
    return 0;
}
