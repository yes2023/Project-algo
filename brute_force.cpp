#include<stdio.h>
#include<algorithm>
#include<array>
int type_of_album = 4,album[] = {12,20,32,10},limit_add = 4;
int stage[10000],minimum,found = 0,ans[10000];
void brute(int n,int pic,int amount)
{
    if(n==pic && amount<minimum) //if there are
    {
        minimum=amount;
        std::copy(std::begin(stage),std::end(stage),std::begin(ans));
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
    int n;
    minimum = 99999999;
    scanf("%d",&n);
    std::sort(album,album+type_of_album,compare);
    brute(0,n,0);
    if(found==0)
    {
        for(int i=1; i<=limit_add; i++)
        {
            brute(0,n,0)
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
