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


node * bst(node* root,int d)
{
    if(root==NULL)
    {
        root=new node(d);
        return root;
    }
    else
    {
        if(d>root->data)
        {
            root->right=bst(root->right,d);
        }
        else
        {
            root->left=bst(root->left,d);
        }

    }
     return root;
}
node* build_bst(int *in,int s,int e)
{
    if(s>e)
        return NULL;
    else
    {
        int mid=(s+e)/2;
        int data=in[mid];
        node* root=new node(data);

        root->left=build_bst(in,s,mid-1);
        root->right=build_bst(in,mid+1,e);
        return root;
    }
}
void level_order(node* root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *top=q.front();
        q.pop();

        if(top==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<top->data<<" ";
            if(top->left)
            {
                q.push(top->left);
            }
            if(top->right)
            {
                q.push(top->right);
            }
        }
    }
}
bool checkbst(node *root)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->left==NULL)
        return true;
    if(root->right==NULL)
        return true;
   // else{
     bool k1=true,k2=true;
    if(( root->data>root->left->data))// && root->data < root->right->data)
    {
         k1= checkbst(root->left);
    }
    else{return false;}
    if(( root->data < root->right->data))
    {
         k2= checkbst(root->right);
    }
    else{return false;}
   // }
    if(k1==true && k2==true)
    {
        return true;
    }
    else{
    return false;
    }
}
node* create_tree()
{
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    node *root=new node(d);
    root->left=create_tree();
    root->right=create_tree();
    return root;
}
int main()
{
    node *root=NULL;
   /* while(1)
    {
        int d;
        cin>>d;
        if(d==-1)
            break;
        else
        {
            root=bst(root,d);
        }
    }
    level_order(root);
    */
    //root=create_tree();
    int in[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(in)/sizeof(int);
    root=build_bst(in,0,n-1);

    //level_order(root);

    if(checkbst(root))
        cout<<"yes";
    else
        cout<<"no";
}
