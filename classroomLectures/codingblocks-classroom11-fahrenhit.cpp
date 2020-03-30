#include<iostream>
using namespace std;
int main()
{
    int a,f,s,i;
    int c;
   // cout<<"enter initial value, final value and step value"<<endl;
    cin>>i>>f>>s;
    for(a=i;a<=f;a=a+s)
    {
        c=((5/9.0)*(a-32));
        cout<<a<<" "<<c<<endl;;
    }
}
