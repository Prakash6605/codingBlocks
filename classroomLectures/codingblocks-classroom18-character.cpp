#include<iostream>
using namespace std;
/*int main()
{
    char ch;int c=0;
    cin>>ch;
    while(ch!='$')
    {
       //if()
        c++;
        cin>>ch;}
    cout<<c;
    //cout<<
}*/
//  to count space we have to use ch=cin.get();
/*int main()
{
   /* char ch;int c=0;
    ch=cin.get();
    while(ch!='$')
    {
        c++;
        ch=cin.get();
    }
    cout<<"output"<<c;
    char ch;
    ch='1';
    cout<<(int)ch;
}*/
int main()
{
    char ch;int d=0,l=0,u=0,s=0;
    ch=cin.get();
    while(ch!='$')
    {
        if(ch>='0' && ch<='9')
            d++;
        else if(ch>='a' && ch<='z')
            l++;
        else if(ch>='A' && ch<='Z')
            u++;
        else
            s++;
       ch=cin.get();
    }
    cout<<"digits:"<<d<<"  lowercase:"<<l<<"  uppercase:"<<u<<"  special characters:"<<s;
}
