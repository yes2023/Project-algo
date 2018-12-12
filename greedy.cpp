#include<stdio.h>
#include<algorithm>
using namespace std;
int amount_of_album = 3,album[] = {12,20,32};
int main()
{
    int n,ans=0,use;
    scanf("%d",&n);
    sort(album,album+amount_of_album);
    for(int i=amount_of_album-1;i>=0;i--)
    {
        use=n/album[i];
        printf("%d use = %d\n",album[i],use);
        n=n-(use*album[i]);
        ans+=use;
    }
    printf("use total album = %d\n",ans);
    printf("Must Include empty song sai = %d",n);
    return 0;
}
