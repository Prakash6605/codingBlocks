#include<iostream>
using namespace std;

void readline(char *a,char delimeter='\n')
{ int i=0;
    char c=cin.get();
    while(c!=delimeter)
    { a[i]=c;
      i++;
        c=cin.get();

    }
    a[i]='\0';
}
int main()
{
    char a[100];
    cout<<"enter the line :"<<endl;
    readline(a);
    cout<<a;
    cout<<"enter the line :"<<endl;
    readline(a,'$');
    cout<<a;
}
