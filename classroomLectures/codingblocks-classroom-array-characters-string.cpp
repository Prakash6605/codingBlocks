#include<iostream>
using namespace std;

int len(char *a)
{ int i=0,l=0;
    while(a[i]!='\0')
    {l++;i++;}
    return l;
}
int main()
{
   // char ch[]="hello world";
   char ch[100],ch1[100];
   cout<<"enter the string "<<endl;
   cin>>ch;
    cout<<"length is :"<<len(ch)<<endl;;

    cout<<"enter the line "<<endl;
    cin.ignore();
    cin.getline(ch1,100);// this terminated with enter or \n;
    cout<<ch1<<endl;
    cout<<"length is :"<<len(ch1)<<endl;
}

