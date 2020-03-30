#include<iostream>
using namespace std;
int main()
{
    int a;char ch[100];
    cout<<"enter the number"<<endl;
    cin>>a;
    cout<<"enter the string "<<endl;
    cin.ignore();
    cin.getline(ch,100);

    cout<<"the number"<<a<<"\n the string "<<ch<<endl;
    return 0;
}
