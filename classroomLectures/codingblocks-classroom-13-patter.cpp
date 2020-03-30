#include<iostream>
using namespace std;
int main()
{
    int i,j,n,a=1;
    cout<<"enter n"<<endl;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        if(i%2==0)
            a=a+i;
        else
            a=a+i-1;
        for(j=1;j<=i*2-1;j++)
        {
            if(j%2!=0 && i%2!=0)
            {
                cout<<" "<<a;
                if(j!=i*2-1)
                    a++;
            }
            else if(j%2!=0 && i%2==0)
                {cout<<" "<<a;
                if(j!=i*2-1)
                    a--;}
            else
                cout<<" "<<"*";

        }
        cout<<"\n";
    }
}

