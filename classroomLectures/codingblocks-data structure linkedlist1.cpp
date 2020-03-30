#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *ptr;
    node(int d)// constructor used for benefit
    {
        data=d;
        ptr=NULL;
    }
};

void insertfront(node* &start,node* &end,int data)
{
    if(start==NULL)
    {
        start=new node(data);
        end=start;
    }
    else
    {
        node *p=new node(data);
        p->ptr=start;
        start=p;
    }
}
void print(node* &start)// similar to void print(node **start,node **end) or send kro as print(&start,&end)
{ node *p=start;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->ptr;
    }
}
int length(node *head)
{
    int l=0;
    while(head!=NULL)
    {
        head=head->ptr;
        l++;
    }
    return l;
}
void insertend(node* &start,node* &end,int data)
{
    if(start==NULL)
    {
        start=new node(data);
        end=start;
    }
    else
    {
        node *t=new node(data);
        end->ptr=t;
        end=t;

    }
}
void insert_middle(node* &start,node* &end,int data,int i)
{
    if(i==0)
    {
        insertfront(start,end,data);
    }
    else if(i>length(start))
    {
        insertend(start,end,data);
    }
    else
    {
        node *n=new node(data);
        node* temp=start;
        for(int j=0;j<i-1;j++)
        {
            temp=temp->ptr;
        }
        n->ptr=temp->ptr;
        temp->ptr=n;
    }
}
void delete_front(node* &start,node* &end)
{
    if(start==NULL)
        cout<<"empty"<<endl;
    else if(start==end)
    {
        node* t=start;
        delete t;
        start=NULL;
        end=NULL;
    }
    else
    {
        node* t=start;
        start=t->ptr;
        delete t;
    }
}
void delete_end(node* &start,node* &end)
{
    if(start==NULL){
        cout<<"empty";
       // return NULL;
    }
    else if(start==end)
    {
        node *t=start;
        delete t;
        start=NULL;
        end=NULL;
    }
    else
    {
        node *t=start;
        while(t->ptr!=end )
        {
            t=t->ptr;
        }
        delete end;
        t->ptr=NULL;
        end=t;
        //delete p;
    }
}
void delete_middle(node* &start,node* &end,int i)
{
    if(i==0)
        delete_front(start,end);
    else if(i==length(start)-1)
        delete_end(start,end);
    else if(i>=length(start))
            return;
    else
    {
        node* prev=start;
        for(int j=1;j<i;j++)
            prev=prev->ptr;
        node *d=prev->ptr;
        prev->ptr=d->ptr;
        delete d;
    }
}
node* search1(node* start,int ns)
{
    if(start==NULL)
        return NULL;
    else if(start->data==ns)
        return start;
    else
       return(search1(start->ptr,ns));
}
//node *start=NULL;
node* findmid(node* start)
{
    node* slow;node*fast;
    slow=start;fast=start;
    while(fast->ptr!=NULL && fast->ptr->ptr!=NULL)
    {
        slow=slow->ptr;
        fast=fast->ptr->ptr;
    }
    return slow;
}
node* merge(node* start1,node* start2)
{
    if(start1==NULL)
        return start2;
    else if(start2==NULL)
        return start1;
    node* newstart;
    if(start1->data<start2->data)
    {
        newstart=start1;
        newstart->ptr=merge(start1->ptr,start2);
    }
    else
    {
        newstart=start2;
        newstart->ptr=merge(start1,start2->ptr);
    }
    return newstart;
}
node* merge_sort(node* head)
{
    /*while(start->ptr!=NULL)
    {

    }*/
    if(head==NULL || head->ptr==NULL)
    {
        return head;
    }

    node *m=findmid(head);
    node *a=head;
    node *b=m->ptr;
    m->ptr=NULL;

    a=merge_sort(a);
    b=merge_sort(b);

    node *temp=merge(a,b);
}
void reverse(node* &start)
{
    node *t1=NULL;
    node* t2=NULL;
    while(start!=NULL)
    {
        t2=start->ptr;
        start->ptr=t1;
        t1=start;
        start=t2;
    }
    start=t1;
}
bool iscycle(node *start)
{
    node *slow=start;
    node *fast=start;
    while(fast->ptr==NULL && fast!=NULL)
    {
         slow=slow->ptr;
        fast=fast->ptr->ptr;
        if(slow==fast)
        {
            return true;
        }
       // slow=slow->ptr;
       // fast=fast->ptr->ptr;
    }
    return false;
}
void bubble_sort(node* &start)
{
    node* prev;
    node* n;
    node* current;
    for(int i=0;i<length(start)-1;i++)
    {
        prev=NULL;
        current=start;
        n=current->ptr;
        while(current->ptr!=NULL && current!=NULL)
        {cout<<"here"<<endl;
            if(current->data>n->data)
            {
                if(prev==NULL)
                {
                    current->ptr=n->ptr;
                    n->ptr=current;
                    start=n;
                    prev=n;
                }
                else
                {
                    current->ptr=n->ptr;
                    n->ptr=current;
                    prev->ptr=n;
                    prev=n;
                }
            }
            else{
                prev=current;
                current=n;
                n=current->ptr;
            }
            }
        }
    }

int main()
{
    int ch=0,data;
    node *start=NULL;
   // start=new node(6);
    node *end=NULL;
   // cout<<(*start).data<<endl;
   while(1)
   {
       cout<<"\n enter 1 for inserting ";
       cout<<"\n enter 2 for printing";
       cout<<"\n enter 3 to insert end";
       cout<<"\n enter 4 for insert middle";
       cout<<"\n enter 5 delete from front";
       cout<<"\n enter 6 delete from end";
       cout<<"\n enter 7 delete from anywhere";
       cout<<"\n enter 8 to search using recursion";
       cout<<"\n enter 9 for finding mid";
       cout<<"\n enter 10 for merging";
       cout<<"\n enter 11 for merge sort";
       cout<<"enter 12 for bubble_sort";
       cout<<"\n enter 20 for exit";
       cout<<"\nenter your choice";
       cin>>ch;
       cout<<"\n\n";
       switch(ch)
       {
       case 1:
        {
            cout<<"enter the value you want to insert"<<endl;
            cin>>data;
            insertfront(start,end,data);
            break;
        }
       case 2:
        {
            print(start);
            break;
        }
       case 3:
        {
            cout<<"enter the value "<<endl;
            cin>>data;
            insertend(start,end,data);
            break;
        }
       case 4:
           {
               int i;
               cout<<"insert the position "<<endl;
               cin>>i;
               cout<<"enter the value"<<endl;
               cin>>data;
               insert_middle(start,end,data,i);
               break;
           }
       case 5:
           {
               delete_front(start,end);
               break;
           }
       case 6:
        {
            delete_end(start,end);
            break;
        }
       case 7:
        {int i;
            cout<<"enter the position"<<endl;
            cin>>i;
            delete_middle(start,end,i);
            break;
        }
       case 8:
        {
            int ns;
            cout<<"enter the element"<<endl;
            cin>>ns;
            node *t=search1(start,ns);
            if(t!=NULL)
            {
                cout<<t->data;
                cout<<"found";
            }
            else
            {
                cout<<"not found";
            }
            break;
        }
       case 9:
        {
            node* t=findmid(start);
            cout<<t->data;
            break;
        }
       case 10:
        {
            node *start1=NULL;node *end1=NULL;
            node *start2=NULL;node *end2=NULL;
            insertend(start1,end1,2);
            insertend(start1,end1,7);
            insertend(start1,end1,9);
            insertend(start1,end1,10);

            insertend(start2,end2,3);
            insertend(start2,end2,5);
            insertend(start2,end2,8);

            node *t=merge(start1,start2);
            print(t);
        }
       case 11:
        {
            //merge sort
            node *p=merge_sort(start);
            print(p);
            break;
        }
       case 12:
        {
             bubble_sort(start);
            print(start);
            break;
        }
       case 13:
        {
            reverse(start);
            print(start);
            break;
        }
       case 14:
        {
            if(iscycle(start))
                cout<<"yes";
            else
                cout<<"no";
            break;
        }
       case 20:
        return 0;
       }
   }
}
