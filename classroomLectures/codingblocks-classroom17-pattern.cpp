#include<iostream>
using namespace std;
int main()
{
    int i,j,n;
    cout<<"enter n";
    cin>>n;
    for(i=n;i>=1;i--)
    {
        char ch=64;
        for(j=1;j<i;j++)
        {
            ch=ch+1;
            cout<<" "<<ch;
        }
        ch=ch-1;
        for(j=1;j<=i;j++)
        {
            cout<<" "<<ch;
            ch=ch-1;
        }
        cout<<endl;
    }
}
