// using the property of our created header file
#include<iostream>
#include "stack.h"
using namespace std;
int main()
{
    stack<int>s;
    for(int i=0;i<9;i++)
        s.push(i);
    while(!s.isempty())
    {
        cout<<s.top()<<" "<<endl;
        s.pop();
    }
    return 0;
}
