typedef struct
{
    int a[5];
} foo;

int main()
{
    printf("%d", ((foo*)0)+5);
    return 0;
}
