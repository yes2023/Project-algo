#include<stdio.h>
#include<algorithm>
using namespace std;
int type_of_album = 3,album[] = {12,20,32};
struct dp
{
    int contain[100]; //contain how much each album use
    int amount;
} dp[100000];
void dynamic(int n)
{
    int temp_album;
    for(int i=0; i<n; i++)
    {
        for(int t=0; t<type_of_album; t++)
        {
            temp_album=album[t];
            if(dp[i+t].amount==0 || dp[i+t].amount>dp[i].amount+1)
            {
                dp[i+t].amount=dp[i].amount+1;
                /*for(int r=0; r<type_of_album; r++) //copy previous contain
                {
                    dp[i+t].contain[r]=dp[i].contain[r];
                }*/
                //copy(begin())
                dp[i+t].contain[t]++;
            }
        }
    }
}
int main()
{
    dp[0].amount=0; // initial dynamic programming table
    for(int i=0; i<100; i++)
        dp[0].contain[i]=0;
    dynamic(40);
    printf("%d",dp[40].amount);
}
