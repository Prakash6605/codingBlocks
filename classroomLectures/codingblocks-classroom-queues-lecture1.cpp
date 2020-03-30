#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int d):data(d),next(NULL)
    {

    }

};
class queue
{
public:
    node *head;
    int cs;
    queue():head(NULL),cs(0)
    {

    }
    void push(int d)
    {
        if(head==NULL)
        {
            head=new node(d);
            cs++;
        }
        else
        {
            node *t=head;
            while(t->next!=NULL)
            {
                t=t->next;
            }
            t->next=new node(d);
            cs++;
        }
    }
    void pop()
    {
        if(head==NULL)
        {
            cout<<"queue is empty"<<endl;
            return ;
        }
        else
        {
            node* t=head;
            head=t->next;
            delete t;
            cs--;
        }
    }
    int top()
    {
        return head->data;
    }
     bool isempty()
     {
         if(cs==0)
            return true;
         else
            return false;
     }
};

int main()
{
    queue q;
    for(int i=0;i<9;i++)
        q.push(i);
    while(!q.isempty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }

    return 0;
}
