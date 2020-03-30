//find number with only one occurence
#include<iostream>
using namespace std;
int main()
{
    int n,a=0,ans=0,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        ans=ans^a;
    }
    cout<<"ans "<<ans;
}
