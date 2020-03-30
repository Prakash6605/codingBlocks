#include<iostream>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5,6};
    cout<<a<<endl;
    cout<<&a<<endl;
     cout<<&a+1<<endl;// jumps from whole array
    cout<<&a[0]<<endl;
    cout<<&a[0]+1<<endl;//jumps from one memory location

    char ch='a';
    char *chptr=&ch;
    cout<<chptr<<endl;// this will not work
    cout<<(int*)chptr<<endl;
    cout<<(float*)chptr<<endl;
    cout<<(void*)chptr<<endl;
    cout<<*(chptr)<<endl;
    return 0;
}
