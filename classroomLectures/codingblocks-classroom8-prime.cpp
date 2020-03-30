#include<iostream>
using namespace std;
int main()
{
    int i,n;
    cout<<"enter the n"<<endl;
    cin>>n;
    i=2;
    while(i<=n/2)
    {
        if(n%i==0){
            cout<<"Not prime"<<endl;
            return 0;}
        i++;
    }
    cout<<"prime";
    return 0;
}
