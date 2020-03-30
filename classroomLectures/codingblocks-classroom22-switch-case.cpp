#include<iostream>
using namespace std;
int main()
{
    char ch;
    cin>>ch;
    switch(ch)
    {
    case 'm':
        {
            cout<<"monday";
            break;
        }
    case 't':
        {

            cout<<"tuesday";
            break;
        }
    default:
        {
            cout<<"invalid";
        }
    }
}
