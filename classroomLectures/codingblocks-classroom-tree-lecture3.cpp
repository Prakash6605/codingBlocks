#include<iostream>
#include<queue>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        data=d;
        right=NULL;
        left=NULL;
    }

};

class linkedlist
{
public:
    node* head;
    node* tail;

    linkedlist():head(NULL),tail(NULL)
    {

    }
};
node* level_order_input()
{
    int d,c1,c2;
    queue<node*>q;
    cin>>d;
    if(d==-1)
        return NULL;

    node* root=new node(d);

    q.push(root);

    while(!q.empty())
    {
        node *top=q.front();
        q.pop();

        cout<<"enter children of"<<top->data<<endl;
        cin>>c1>>c2;

        if(c1!=-1)// left child
        {
            top->left=new node(c1);
            q.push(top->left);
        }
        else
        {
            top->left=NULL;
        }

        if(c2!=-1)//right child
        {
            top->right=new node(c2);
            q.push(top->right);
        }
        else
        {
            top->right=NULL;
        }

    }
    return root;
}
linkedlist bsttoll(node* root)
{
    linkedlist l;
    if(root==NULL)// case 1: when no tree exits
    {
        l.head=NULL;
        l.tail=NULL;
        return l;
    }
    if(root->right==NULL && root->left==NULL)// case 2: when only one node of bst exits
    {
        l.head=root;
        l.tail=root;
        return l;
    }
    else if(root->right && root->left==NULL)// case 3: when right exits and left does not
    {
        linkedlist right=bsttoll(root->right);
        root->right=right.head;
        l.head=root;
        l.tail=right.tail;
        return l;
    }
    else if(root->left && root->right==NULL)// when left child exits
    {
        linkedlist left=bsttoll(root->left);
        left.tail->right=root;
        l.head=left.head;
        l.tail=root;
        return l;
    }
    else// when both left and right child exits
    {
       linkedlist left=bsttoll(root->left);
       linkedlist right=bsttoll(root->right);
       left.tail->right=root;
       root->right=right.head;

       l.head=left.head;
       l.tail=right.tail;
       return l;
    }
}
void print(node* h)
{
    while(h)
    {
        cout<<h->data<<" ";
        h=h->right;
    }
}
int main()
{
    //node *root=NULL;
    node* root=level_order_input();
  //level_order(root);

  linkedlist l=bsttoll(root);
  print(l.head);
}
