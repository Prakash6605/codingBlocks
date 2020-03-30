#include<iostream>
using namespace std;
int fibdp(int i,int dp[])// top down  approach
{
    if(i==0 || i==1)
        return i;
    else if(dp[i]!=-1)
            return dp[i];
    else{
        dp[i]=fibdp(i-1,dp)+fibdp(i-2,dp);
        return dp[i];
    }
}
int bottomup(int n)
{
    int dp[1000];
    dp[0]=0;dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}
int fib(int i)
{
    if(i==0 || i==1)
        return i;
    else
        return (fib(i-1)+fib(i-2));
}
int step=0;
int make(int i)
{
    if(i==1)
    {
        return(step);

    }
    if(i%3==0)
    {
        step++;
        return(make(i/3));
    }
    else if(i%2==0 && (i-1)%3!=0)
    {
        step++;

        return(make(i/2));
    }
    else
    {
        step++;
        return(make(i-1));
    }
}
int minstep(int n)// make
{
    if(n==1)
        return 0;

    int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;

    op1=1+minstep(n-1);
    if(n%2==0)
    {
        op2=1+minstep(n/2);
    }
    if(n%3==0)
    {
        op3=1+minstep(n/3);
    }
    return (min(op1,min(op2,op3)));
}
int bottomup_of_minstep(int n)
{
    int dp[1000];
    dp[0]=0;
    dp[1]=0;
    int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
    for(int i=2;i<=n;i++)
    {
         op1=1+dp[i-1];
        if(i%2==0)
        {
             op2=1+dp[i/2];
        }
        if(i%3==0)
        {
            op3=1+dp[i/3];
        }
       dp[i]= (min(op1,min(op2,op3)));
       op1=INT_MAX;op2=INT_MAX;op3=INT_MAX;
    }
    return dp[n];
}
int main()
{
    int n,dp[100];
    cin>>n;
    //cout<<"using dp"<<endl;
   /* for(int i=0;i<=n;i++)
        dp[i]=-1;
    dp[0]=0;
    dp[1]=1;*/
   /* for(int i=0;i<n;i++)
    {
        cout<<fibdp(i,dp)<<" ";
    }
    cout<<"using recursion"<<endl;
   /* for(int i=0;i<n;i++)
        cout<<fib(i);*/

       cout<<make(n);

       cout<<"using minstep"<<endl;
       cout<<minstep(n);
        //cout<<bottomup(n)<<" ";


        cout<<"\n here using bottom up \n";
        cout<<bottomup_of_minstep(n);

}




