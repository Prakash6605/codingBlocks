#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int i,n,maxv,minv,a;
    cout<<"enter the n"<<endl;
    cin>>n;
    i=1;
    minv=INT_MAX;
    maxv=INT_MIN;
    while(i<=n)
    {
        cout<<"enter the "<<i<< " number"<<endl;
        cin>>a;
        if(a<minv)
            minv=a;
        if(a>maxv)
            maxv=a;
        i++;
    }
    cout<<"The greatest "<<maxv<<"\n The smallest "<<minv<<endl;
}
