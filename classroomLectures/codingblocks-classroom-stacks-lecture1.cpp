#include<iostream>
#include<stack>
using namespace std;

/*class node
{
public:
    int data;
    node* next;

    node(int d)
    {
        data=d;
        next=NULL;
    }
};
void push(node* &head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
    }
    else
    {
        node *t=new node(data);
        t->next=head;
        head=t;
    }
}
void pop(node* &head)
{
    if(head==NULL)
    {
        cout<<"No elements to delete"<<endl;
        return;
    }
    else
    {
        node* t=head;
        head=t->next;
        delete t;
    }
}
void print(node* head)
{
   node *t=head;
   while(t!=NULL)
   {
       cout<<t->data<<" ";
       t=t->next;
   }
}
int main()
{
    node *head=NULL;
    int ch,d;
    while(1)
    {
        cout<<"\n enter 1 for inserting"<<endl;
        cout<<"\n enter 2 for deleting elements"<<endl;
        cout<<"\n enter 3 for printing"<<endl;
        cout<<"\n enter your choice"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                cout<<"enter the data"<<endl;
                cin>>d;
                push(head,d);
                break;
            }
        case 2:
            {
                pop(head);
                break;
            }
        case 3:
            {
                print(head);
                break;
            }
        case 4:
            return 0;
        }
    }
    return 0;
}

// teacher implementation using stack class
class node
{
public:
    int data;
    node* next;

    node(int d)
    {
        data=d;
        next=NULL;
    }
};
class stack
{
public:
    node *head;
    int size;

    stack():head(NULL),size(0)
    {

    }

    void push(int d)
    {
        if(head==NULL)
        {
            head=new node(d);
            size++;
        }
        else
        {
            node *n=new node(d);
            n->next=head;
            head=n;
            size++;
        }
    }

    void pop()
    {
        if(size>0)
        {
           node *t=head;
           head=t->next;
           delete t;
           size--;
        }
    }

    int top()
    {
        if(size>0)
        {
            return head->data;
        }
    }

    bool isempty()
    {
        if(size==0)
            return true;
        else
            return false;
    }
};
int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);


    cout<<"data at top"<<s.top()<<endl;

    s.pop();

    cout<<"data at top"<<s.top()<<endl;
}
*/

// inbuilt stack implementation
int main()
{
    stack<int>s;
    for(int i=0;i<9;i++)
        s.push(i);
    while(!s.empty())
    {
        cout<<s.top()<<" "<<endl;
        s.pop();
    }
    return 0;
}
