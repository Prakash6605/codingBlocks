#include<iostream>
using namespace std;
int main()
{
    int n,i,a,j;
    cout<<"enter n"<<endl;
    cin>>n;
    for(i=1;i<=n;i++)
    {  a=i;
        for(j=1;j<=n-i;j++)
            cout<<"  ";
        for(j=1;j<=i;j++)
        {
            cout<<" "<<a++;
        }
        if(i>1)
        {a=i*2-2;
            for(j=1;j<i;j++)
                cout<<" "<<a--;
        }
        cout<<endl;
    }
    return 0;
}
