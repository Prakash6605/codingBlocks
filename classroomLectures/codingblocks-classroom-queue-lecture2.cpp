#include<iostream>
using namespace std;

class queue
{
public :
    int *a;
    int cs,f,r,size;

    queue(int n)
    {
        a=new int[n];
        cs=0;
        f=-1;
        r=-1;
        size=n;
    }

    void push(int d)
    {
        if(cs==size-1)
        {
            cout<<"full";
            return;
            cs++;
        }
        else
        {
            if(r==-1 && f==-1)
            {
                r++;f++;
                a[r]=d;
            }
            else{
            r=(r+1)%size;
            if(r==f)
            {
                cout<<"full";
            }
            else{
            a[r]=d;
            cs++;}

            }
        }
    }
    void pop()
    {
        if(cs==0)
        {
            cout<<"empty"<<endl;
            return;
        }
        else
        {
           // data=a[f];
            f=(f+1)%size;
            if(f==r)
            {
                f=-1;
                r=-1;
                cs=0;
            }
            else{
            cs--;}
        }
    }
    int top()
    {
        return a[f];
    }
    bool empty()
    {
        if(cs==0)
            return true;
        else
            return false;
    }
};
int main()
{
    queue q(5);
 for(int i=0;i<5;i++)
    q.push(i);
 while(!q.empty())
 {
     cout<<q.top()<<endl;
     q.pop();
 }

}
