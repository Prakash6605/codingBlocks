#include<iostream>
using namespace std;
int main()
{
    float i=0;
    int p,n,j;
    cout<<"enter precision, number"<<endl;
    cin>>p>>n;
    float inf=1;
    for(j=1;j<=p;j++)
    {
        while(i*i<=n)
        {//cout<<"here"<<endl;
            if(i*i==n)
                {cout<<"square root is "<<i;
                return 0;}
            i=i+inf;
        }
        i=i-inf;
        inf=inf/10;
    }
    cout<<"closest square root is"<<i;
    return 0;
}
