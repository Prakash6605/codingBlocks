#include<iostream>
using namespace std;
int main()
{
    char ch;
    cin>>ch;
    if(ch>=90 &&ch<=122)
        cout<<"\n"<<"lowercase";
    else if(ch>=65 && ch<=90)
            cout<<"\n"<<"uppercase";

    else
        cout<<"\n"<<"invalid";
    return 0;
}
