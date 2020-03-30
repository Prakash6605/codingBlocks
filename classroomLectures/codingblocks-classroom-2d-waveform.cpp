#include<iostream>
using namespace std;
int main()
{
    int a[100][100];
    int r,c,i,j,k=0;
    cin>>r>>c;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
           {a[i][j]=k;k++;}

   for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++)
        cout<<a[i][j]<<" ";
       cout<<endl;
   }


   for(i=0;i<r;i++)
   {if(i%2==0){
       for(j=0;j<c;j++)
          cout<<a[i][j]<<" ";
   }
   else
   {
        for(j=c-1;j>=0;j--)
            cout<<a[i][j]<<" ";
   }
   }

   cout<<endl;
   for(j=0;j<c;j++)
   {
       if(j%2==0)
       {
           for(i=0;i<r;i++)
            cout<<a[i][j]<<" ";
       }
       else
       {
           for(i=r-1;i>=0;i--)
            cout<<a[i][j]<<" ";
       }
   }
}
