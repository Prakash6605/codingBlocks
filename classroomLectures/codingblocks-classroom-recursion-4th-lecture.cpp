#include<iostream>
using namespace std;
int findpaths(int a[][10],int n,int i,int j)
{
    if(i==0 && j==0)
    {
        return 1;
    }
    if(i<0 || j<0)
        return 0;
    int ans=0;//ans1=0;
    for(int k=1;k<=i;k++){
    ans=ans+findpaths(a,n,i-k,j);
    }
    for(int k=1;k<=j;k++)
    {ans=ans+findpaths(a,n,i,j-k);
    }
    return ans;// can only move down and right
   // k++;
    //return ans;
}



int main()
{
    int arr[10][10];
    int n,i,j,k=1;
    cout<<"enter n"<<endl;
    cin>>n;
    cout<<"enter position :"<<endl;
    cin>>i>>j;
    cout<<findpaths(arr,n,i,j);
}

