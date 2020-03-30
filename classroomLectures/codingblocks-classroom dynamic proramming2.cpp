// n stairs

#include<iostream>
using namespace std;

int count_steps(int n,int k)
{
    if(n==0 || n==1)
        return 1;
    if(n<0)
        return 0;

     int ans=0;
        for(int i=1;i<=k;i++)
        {
            ans=ans+count_steps(n-i,k);
        }



    return ans;
}
int topdown(int n,int k,int dp[])
{
    if(n==0 || n==1)
    {
        dp[n]=1;
        return dp[n];
    }
    if(n<0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];

    else
    {
        int ans=0;
        for(int i=1;i<=k;i++)
        {
            ans+=topdown(n-i,k,dp);
        }
        dp[n]=ans;

    }
    return dp[n];
}


int bottomup(int n,int k)
{
    int dp[100]={0};
    dp[0]=1;
    dp[1]=1;
    for(int stair=2;stair<=n;stair++)
    {
        if(stair-1-k >=0)
        {
            dp[stair]=2*dp[stair-1]-dp[stair-1-k];// optimized way
        }
        else
        {
            dp[stair]=2*dp[stair-1];
        }
    }
    return dp[n];
}

int main()
{
    int n,k;
    cin>>n>>k;
    int dp[1000];
    for(int i=0;i<=n;i++)
       {dp[i]=-1;}
        cout<<"\n using single recursion \n"<<endl;
    cout<<count_steps(n,k);

    cout<<"\n using top down \n"<<endl;
    cout<<topdown(n,k,dp);

    cout<<"\n using bottom up \n"<<endl;
    cout<<bottomup(n,k);
}
