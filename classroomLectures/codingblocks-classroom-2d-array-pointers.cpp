#include<iostream>
using namespace std;
int main()
{
  /*  int a[][3]={{1,2,3},{4,5,6}};
    char ch[][3]={{'a','b','c'},{'d','e','f'}};

    cout<<a[0]<<endl;
    cout<<a[1]<<endl;

    cout<<ch[0]<<endl;
    cout<<ch[1]<<endl;

    return 0;*/


    int a[10][10];int r,c,i,j;
    cin>>r>>c;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
          cin>>a[i][j];

    cout<<"enter data "<<endl;
    cin>>ns;
   /* for(j=0;j<c;j++)
    { int s=0;
    for(i=0;i<r;i++)
    {
        s=s+a[i][j];
        cout<<a[i][j]<<" ";
    }
    cout<<s;
    cout<<endl;
    }*/

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]==ns)
            {
                cout<<"found";
                return 0;
            }
        }
    }
    cout<<"not found";
    return 0;
}
