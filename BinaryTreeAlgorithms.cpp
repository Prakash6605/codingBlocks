#include<bits/stdc++.h>
using namespace std;
// all binary search tree algorithm
class node{
public:
  int data;
  node* left;
  node* right;

  node(int d){
     data=d;
     left=NULL;
     right=NULL;
  }
};

node* build_bst(node* root){

  int data;
  cin>>data;
  if(data==-1)return NULL;

  root=new node(data);
  root->left=build_bst(root->left);
  root->right=build_bst(root->right);
  return root;

}
// checking for bst
bool checkBst(node* root, int min=INT_MIN,int max=INT_MAX){

    if(root==NULL)return true;

    if(min<=root->data && max>=root->data && checkBst(root->left,min,root->data)&& checkBst(root->right,root->data,max)){
        return true;
    }
    else return false;

}
// checking if bst is balanced or not
class helper{
public:
    int h;
    bool balanced;
};

helper isBalanced(node* root){

   helper p;
   if(root==NULL){
    p.h=0;
    p.balanced=true;
    return p;
   }
   helper l=isBalanced(root->left);
   helper r=isBalanced(root->right);
   p.h=max(l.h,r.h)+1;
   if(l.balanced && r.balanced && abs(l.h-r.h)<=1){
    p.balanced=true;
   }
   else p.balanced=false;
   return p;
}
// level order traversal of binary tree
int height(node* root){
if(root==NULL)return 0;
 return max(height(root->left),height(root->right))+1;
}
vector<vector<int> > levelOrder(node* root){

  queue<node*> q;
  q.push(root);
  q.push(NULL);
  vector<vector<int> > v(height(root));
  int i=0;
  node* prev_node=NULL;
  while(!q.empty()){
    node* cur_node=q.front();

    q.pop();
    if(cur_node)
    {
    v[i].push_back(cur_node->data);
    }
    if(cur_node && cur_node->left!=NULL){q.push(cur_node->left);}
    if(cur_node && cur_node->right!=NULL){q.push(cur_node->right);}
    if(cur_node==NULL && prev_node!=NULL){q.push(NULL);i++;}
    prev_node=cur_node;
  }
  return v;
}
void in_order(node* root){

  if(root==NULL)return;
  else{
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
  }

}
int main(){

 node* root=build_bst(root);
 cout<<" \n the in order traversal of tree "<<endl;
 in_order(root);
 cout<<" printing the level order traversal of the tree "<<endl;
 vector<vector<int> >v=levelOrder(root);
 cout<<" comming here "<<endl;
 for(int i=0;i<v.size();i++){
    for(int j=0;j<v[i].size();j++){
        cout<<v[i][j]<<" ";
    }
    cout<<endl;
 }

 cout<<" checking bst "<<endl;
 bool bst=checkBst(root);
 if(bst)cout<<" is bst "<<endl;
 else cout<<" is not bst "<<endl;

 cout<<" checking id bst is balanced  "<<endl;
 helper bal=isBalanced(root);
 if(bal.balanced)cout<<" is balanced "<<endl;
 else cout<<" is  not balanced "<<endl;
}
//10 5 -1 -1 15 6 -1 -1 20 -1 -1
