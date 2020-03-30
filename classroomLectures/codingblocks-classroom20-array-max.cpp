#include<iostream>
#include<climits>
using namespace std;
int main()
{
   int a[100],n,i,max=INT_MIN;
   cin>>n;
   for(i=0;i<n;i++)
         cin>>a[i];
   for(i=0;i<n;i++)
   {
       if(a[i]>max)
        max=a[i];

   }
   cout<<"largest"<<max;
}
/*int main()
{
    int n=100000;
    int a[n];
    return 0;
}*/
