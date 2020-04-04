#include<bits/stdc++.h>
using namespace std;
// tree algorithms
class node{
 public:
   int data;
   node *left,*right;
   node(int d){
   data=d;
   left=NULL;
   right=NULL;
   }
};
//building the tree
node* build_tree(){
   int data;
   cin>>data;
   if(data==-1)return NULL;
   else{
    node * root=new node(data);
    root->left=build_tree();
    root->right=build_tree();
    return root;
   }
}
// in order traversal
void in_order(node *root){
  if(root==NULL)return;
  in_order(root->left);
  cout<<root->data<<" ";
  in_order(root->right);
}
// pre order traversal
void pre_order(node* root){

  if(root==NULL)return ;
  else{
    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
  }
}
// number of nodes in the tree
int count_nodes(node * root){

  if(root==NULL)return 0;
  else{

    int left=count_nodes(root->left);
    int right=count_nodes(root->right);
    return left+right+1;
  }

}
// height of the tree
int height(node *root){

  if(root==NULL)return 0;
  else{
    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;
  }

}
// finding the diameter of the tree
class dia{
  public:
      int h,d;
};
dia diameter(node* root){
  dia p;
  if(root==NULL){
    p.h=0;
    p.d=0;
    return p;
  }
  dia l=diameter(root->left);
  dia r=diameter(root->right);
  p.d=max((l.h+r.h+1),max(r.d,l.d));
  p.h=max(l.h,r.h)+1;
  return p;
}
int main(){

  node *root=build_tree();
  // printing the tree in pre order
  cout<<"\n printing the tree in pre order "<<endl;
  in_order(root);
  cout<<endl;
  cout<<" printing the pre_order "<<endl;
  pre_order(root);
  cout<<endl;
  cout<<" printing the number of nodes in the tree "<<endl;
  cout<<count_nodes(root)<<endl;
  cout<<" printing the height of the tree "<<endl;
  cout<<height(root)<<endl;
  cout<<" finging the diameter of the tree "<<endl;
  dia ans=diameter(root);
  cout<<ans.d-1<<endl;
}
//10 5 7 8 -1 -1 9 -1 -1 -1 6 22 8 -1 -1 -1 -1
