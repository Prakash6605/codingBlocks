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
void preorder(node* root)
{
    if(root)
    {
        cout<<root->data<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node* root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int count(node *root)
{
    if(root==NULL)
        return 0;
    else  return ((count(root->left)+count(root->right))+1);
}
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int height(node *root)
{
    if(root==NULL)
        return 0;
    else
        return(max(height(root->left),height(root->right))+1);
}
int maxi(int a,int b,int c)
{
    if(a>b && a>c)
        return a;
    else if(b>a && b>c)
        return b;
    else
        return c;
}
int diameter(node* root)
{
    if(root==NULL)
        return 0;
   int heightl=height(root->left);
    int heightr=height(root->right);
    int total=heightl+heightr+1;
     return maxi(total,diameter(root->left),diameter(root->right));
}
class Pair
{
public:
    int height;
    int diameter;
};
Pair fastdaimeter(node *root)
{
    Pair p;
    if(root==NULL)
    {
        p.height=0;
        p.diameter=0;
        return p;
    }
    Pair left=fastdaimeter(root->left);
    Pair right=fastdaimeter(root->right);

    p.height=max(left.height,right.height)+1;
    int op1=left.height+right.height+1;
    int op2=left.diameter;
    int op3=right.diameter;
    p.diameter=max(op1,max(op2,op3));
    return p;
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

        //cout<<"enter children of"<<top->data<<endl;
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
void mirror(node* &root)
{
    if(root==NULL)
        return ;
    swap(root->left,root->right);
    mirror(root->right);
    mirror(root->left);
}
int i=0;
int pre[]={8,10,1,6,4,7,3,14,13};
node* build_tree(int *in,int s,int e)// s and e are search space
{
    if(s>e)
        return NULL;
    else{
        int data=pre[i];
        i++;
        node* root=new node(data);
        int k=-1;
        for(int j=s;j<=e;j++)
        {
            if(in[j]==data)
            {
                k=j;
                break;
            }
        }

        root->left=build_tree(in,s,k-1);
        root->right=build_tree(in,k+1,e);
        return root;
    }
}
int main()
{

 //node *root=create_tree();
 /*cout<<"pre order"<<endl;
 preorder(root);*/
 /*cout<<"inorder"<<endl;
 inorder(root);*/
/*cout<<endl;
 cout<<"number of nodes"<<count(root)<<endl;

 cout<<"height of the tree"<<height(root)<<endl;
  cout<<"the diameter is "<<diameter(root)<<endl;

  cout<<"the fast diameter";
  Pair p;
  p=fastdaimeter(root);
  cout<<"height"<<p.height;
  cout<<"diameter"<<p.diameter;
  //cout<<"mirror image";

  cout<<"The level order traversal "<<endl;
  level_order(root);*/
  /*int in[]={1,10,4,6,7,8,3,13,14};

  int n=sizeof(in)/sizeof(int);
  cout<<"build tree"<<endl;
  node* root=build_tree(in,0,n-1);

  preorder(root);*/

  node* root=level_order_input();
  //level_order(root);
  inorder(root);
}
