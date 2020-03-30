#include<iostream>
using namespace std;
void inttostring(int);
void print(int ,int ,int);
char s[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int reverse(int n)
{ int s=0;
    while(n>0)
    {
        s=s*10+n%10;
        n=n/10;
    }
    return s;
}
int main()
{
    int n,l;
    cout<<"enter the number "<<endl;
    cin>>n;
    cout<<"enter the length "<<endl;
    cin>>l;

   /*  n=reverse(n);
    print(n,l,0);*/
    inttostring(n);
}
/*
void print(int n,int l,int i)
{
    if(i==l)
        return;
    int d=n%10;

    cout<<s[d]<<" ";
    n=n/10;
    print(n,l,i+1);
}*/
// 2nd method
void inttostring(int n)
{
    if(n==0)
        return ;
    int d=n%10;
    inttostring(n/10);// ye phelay last tk lay jara hai then printing start krra hai.
    cout<<s[d]<<" ";
}














