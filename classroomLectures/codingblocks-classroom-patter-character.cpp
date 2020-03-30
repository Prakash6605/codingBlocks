#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter n";
    cin>>n;
    int i,j,k=18;
    for(i=65;i<65+n;i++)
    {
        for(j=i;j>=65;j--)
        {
            char ch=j;
            cout<<" "<<ch;
        }
        for(j=1;j<65+n-(i);j++)
        {//cout<<"hr";
            char ch1=65+j;
            cout<<" "<<ch1;
        }
        cout<<endl;
    }
}
