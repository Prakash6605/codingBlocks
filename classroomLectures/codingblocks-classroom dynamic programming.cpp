#include<iostream>
using namespace std;
/*int min(int op[],int n)
{
    int a=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(a<op[i])
            a=op[i];
    }
    return a;
}*/
int find_change(int a[],int s,int n)
{
    if(s==0)
    {
        return 0;
    }
    //int op[100];
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(s-a[i]>=0)
        {
            ans=min(ans,1+find_change(a,s-a[i],n));
        }
    }
    return ans;
}
int topdown(int a[],int s,int n,int dp[])
{
    if(s==0)
    {
        dp[s]=0;
        return dp[s];
    }

    if(dp[s]!=-1)
        return dp[s];

    else
    {
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(s-a[i]>=0)
                ans=min(ans,1+topdown(a,s-a[i],n,dp));
        }
        dp[s]=ans;
    }
    return dp[s];
}
int main()
{
    int s=0;
    int a[]={1,7,10};
    cin>>s;
    cout<<find_change(a,s,3);

    int dp[10000];
    for(int i=0;i<10000;i++)
        dp[i]=-1;
    cout<<"\n";
    cout<<topdown(a,s,3,dp);
}
