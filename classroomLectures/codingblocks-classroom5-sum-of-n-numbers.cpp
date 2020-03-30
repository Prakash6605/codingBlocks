#include<iostream>
using namespace std;
int main()
{
    int k,sum=0,n;
    cout<<"enter the numbers of no you want "<<endl;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        cout<<"enter the number "<<endl;
        cin>>k;
        sum=sum+k;
        i++;
    }
    cout<<sum<<" is the sum"<<endl;
    return 0;
}
