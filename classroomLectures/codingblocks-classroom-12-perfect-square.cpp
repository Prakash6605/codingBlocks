#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    while(i*i<=n)
    {   if(i*i==n)
          {
              cout<<" square root is "<<i<<endl;
              return 0;
          }
        i++;
    }
    cout<<"not a perfect square"<<endl;
    return 0;
}
