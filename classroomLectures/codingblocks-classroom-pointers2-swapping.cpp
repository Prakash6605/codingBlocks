#include<iostream>
using namespace std;
void swap(int *a,int *b)
 {
     int t=*(a);
     *a=*b;
     *b=t;
 }
int main()
 {
     int a,b;
     cout<<"enter a and b"<<endl;
     cin>>a>>b;
     cout<<"initial value "<<a<<" "<<b<<endl;
      swap(&a,&b);
     cout<<"final value "<<a<<" "<<b<<endl;
 }
