#include<stdio.h>
#include<algorithm>
int type_of_album = 4,album[] = {12,20,32,10},limit_add = 4;
int stage[10000],minimum,found,ans[10000];
void copy_arry(int n)
{
    for(int i=0;i<n;i++)
        ans[i]=stage[i];
}

void brute(int n,int pic,int amount)
{
    if(n==pic && amount<minimum) //if there are
    {
        minimum=amount;
        copy_arry(amount);
        found=1;
    }
    if(n<pic)
    {
        for(int i=0; i<type_of_album; i++)
        {
            stage[amount]=album[i]; //include stage
            brute(n+album[i],pic,amount+1); //go to next branch
        }
    }
}
int compare(int a,int b)
{
    return a>b;
}
int main()
{
    int n,min1;
    minimum = 99999999;
    found = 0;
    scanf("%d",&n);
    std::sort(album,album+type_of_album,compare);
    brute(0,n,0);
    if(found==0)
    {
        for(int i=1; i<=limit_add && found==0; i++)
        {
            brute(0,n+i,0);
            min1=minimum;
            brute(0,n-i,0);
            if(min1==minimum && found)
            {
                printf("Add song sai : %d\n",i);
            }
            else if(found)
            {
                printf("Use %d\n",n+i);
            }
        }
        for(int i=limit_add+1;found==0 ; i++)
            {
                brute(0,n+i,0);
                if(found)
                    printf("Use %d\n",n+i);
            }
    }
    if(found==1)
    {
        for(int i=0; i<minimum; i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
}
