#include<iostream>
using namespace std;
int main()
{
    int n,s=0,r=0;
    cout<<"enter n";
    cin>>n;
    while(n>0)
    {
        r=n%10;
        s=s+r;
        n=n/10;
    }
    cout<<s;
}
