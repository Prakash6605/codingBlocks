#include<iostream>
using namespace std;
int main()
{
    int i,n,j,flag=0;
    cout<<"enter n"<<endl;
    cin>>n;
    for(i=2;i<=n;i++)
    {
        flag=0;
        for(j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
                //cout<<i<<" is not prime"<<endl;
                //break;
                flag=1;
                break;
            }

        }
        if(flag==0)
            cout<<i<<"is prime"<<endl;
    }
    return 0;
}
