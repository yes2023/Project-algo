#include<stdio.h>
#include<algorithm>
using namespace std;
int type_of_album = 4,album[] = {12,20,32,10};
int stage[10000],minimum;
void brute(int n,int pic,int amount)
{
    if(n==pic && amount<minimum) //if there are
    {
        minimum=amount;
        for(int i=0;i<amount;i++)
        {
            printf("%d ",stage[i]); //print passed stage
        }
        printf("\n");
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
    minimum = 99999999;
    sort(album,album+type_of_album,compare);
    brute(0,168,0);
}
