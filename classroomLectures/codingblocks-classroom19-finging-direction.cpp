#include<iostream>
using namespace std;
int main()
{
    char ch;int y=0,x=0,i;
    ch=cin.get();
    while(ch!=' ')
    {
        if(ch=='S')
            y++;
        else if(ch=='N')
            y--;
        else if(ch=='E')
            x++;
        else
            x--;
        ch=cin.get();
    }
    if(x>0)
        for(i=1;i<=x;i++)
          cout<<"E";
    if(y<0)
        for(i=1;i<=-y;i++)
           cout<<"N";
    if(y>0)
        for(i=1;i<=y;i++)
          cout<<"S";
    if(x<0)
        for(i=1;i<=-x;i++)
          cout<<"W";
    if(x==0 && y==0)
            cout<<"origin";
}
