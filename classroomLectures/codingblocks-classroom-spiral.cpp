
#include<iostream>
using namespace std;

int main()
{
    int a[100][100];
    int r,c,i,j,k=0;
    cin>>r>>c;

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
    {
        a[i][j]=k;
        k++;
    }

     for(i=0;i<r;i++)
     {
        for(j=0;j<c;j++)
    {
        cout<<a[i][j]<<" ";

    }
    cout<<endl;
     }
    int ri=0,ci=0,rf=r-1,cf=c-1;
    while(ri<=rf && ci<=cf)
    {
        for(i=ri;i<=cf;i++)
            cout<<a[ri][i]<<" ";
        ri++;
        cout<<endl;
       // cout<<"ri"<<ri<<endl;
       // cout<<
        for(j=ri;j<=rf ;j++)
            cout<<a[j][cf]<<" "<<endl;
        cf--;
        for(i=cf;i>=ci && ri<=rf;i--)
            cout<<a[rf][i]<<" ";
         rf--;
        for(i=rf;i>=ri && ci<=cf;i--)
            cout<<a[i][ci]<<" ";
        ci++;
    }


}
