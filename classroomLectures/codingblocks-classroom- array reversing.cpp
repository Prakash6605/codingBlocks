#include<iostream>
using namespace std;
int main()
{
    int a[20];int i,n;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    int f=0,r=n-1;
    while(f<r)
    {
        swap(a[f],a[r]);
        f++;r--;
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
