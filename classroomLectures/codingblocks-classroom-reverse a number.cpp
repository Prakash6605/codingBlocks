#include<iostream>
using namespace std;
int main()
{
    int n,s=0;
    cout<<"enter n";
    cin>>n;
    /*while(n>0)
    {
        s=s*10+n%10;
        n=n/10;
    }*/
    for(int i=n;n>0;)
    {
       int r=n%10;
        cout<<r;
       // s=s*10+r;

        n=n/10;
    }
   // cout<<"reverse is "<<s;
    return 0;
}
