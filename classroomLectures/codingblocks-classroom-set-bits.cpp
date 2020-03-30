#include<iostream>
using namespace std;
int main()
{
    int n,c=0;
    cout<<"enter n";
    cin>>n;
    while(n>0)
    {
      /*  if(n%2==1)
            c++;
        n=n/2;*/
        if(n & 1==1)
            c++;
        n=n>>1;
    }
    cout<<"number of set bits "<<c;
}
