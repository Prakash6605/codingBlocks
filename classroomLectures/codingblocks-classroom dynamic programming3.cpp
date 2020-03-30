#include<iostream>
using namespace std;
// 0-1 knap sack problem
int max_profit(int n,int x,int wts[],int profit[])
{
    if(n==0 || x==0)
        return 0;

    int include=0,exclude=0;
    if(wts[n-1]<=x)
        {
             include=profit[n-1]+max_profit(n-1,x-wts[n-1],wts,profit);
        }
             exclude=max_profit(n-1,x,wts,profit);


    return max(include,exclude);

}

int bottom_up(int n,int x,int wts[],int profit[])
{
    int dp[100][100];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else
            {
                int include=0,exclude=0;
                if(wts[i-1]<=j){
                include=profit[i-1]+dp[i-1][j-wts[i-1]];}

                exclude=dp[i-1][j];

                dp[i][j]=max(include,exclude);
            }
        }
    }
    return dp[n][x];
}
int main()
{
    int n,x;
 int wts[1000],profit[1000];
 cout<<"enter n\n";
 cin>>n;
 cout<<"enter sack capacity\n";
 cin>>x;

// cout<<max_profit(n,x,wts,profit);

 for(int i=0;i<n;i++)
    cin>>wts[i];
 for(int i=0;i<n;i++)
    cin>>profit[i];

     cout<<max_profit(n,x,wts,profit);
     cout<<"\n";
     cout<<bottom_up(n,x,wts,profit);
}

