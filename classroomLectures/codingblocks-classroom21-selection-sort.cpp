#include<iostream>
using namespace std;
int main()
{
    int a[20],i,flag=0,j,n,t=0,minpos;
    cin>>n;
    cout<<"enter values in the array "<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];
   /* for(i=0;i<n-1;i++)
    {
        minpos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[minpos])
            {
                minpos=j;
            }
        }
        t=a[i];
        a[i]=a[minpos];
        a[minpos]=t;
    }*/
    for(i=0;i<n-1;i++)
    { flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                flag=1;
                swap(a[j],a[j+1]);
            }

        }
        if(flag==0)
            break;
    }
    cout<<"i"<<i;
    cout<<"sorted array :"<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
