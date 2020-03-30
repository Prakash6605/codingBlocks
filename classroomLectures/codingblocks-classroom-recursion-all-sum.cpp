#include<iostream>
using namespace std;
/*int fibo(int);
int main()
{
    int n;
    cout<<"enter the index"<<endl;
    cin>>n;

    int ans=fibo(n);

    cout<<"the value at index "<<n<<" : "<<ans;
}
int fibo(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    int ans=fibo(n-1)+fibo(n-2);

    return ans;
}*/



// printing the elements of the array
/*void printarray(int *,int);
int main()
{
    int a[]={1,2,3,4,5,6};
    int l=(sizeof(a)/sizeof(int));

    printarray(a,l);
}*/
/*void printarray(int *a,int l)
{
    if(l==0)
        return ;
    else
    {
        cout<<a[0];
        printarray(a+1,l-1);
    }
}*/
// 2nd approach my method
/*int i=-1;
void printarray(int *a,int l)
{i++;
    if(i==l)
        return;
    else
    {
        cout<<a[i];
        printarray(a,l);
    }
}
*/
// sorting using recursion
/* bool check_sorted(int a[],int l)
 {
     if(l==0 || l==1)// l==1 when array have inly one elements.
        return true;


     bool kyaaagesesortedmila=check_sorted(a+1,l-1);
     if(a[0]<=a[1] && kyaaagesesortedmila)
     {
        return true;
     }
     return false;

 }*/
bool check_sorted(int *,int);
int find_sum(int *,int);
void print_reverse(int*,int);
int search_last(int *,int,int,int,int);
int main()
{
    //int a[]={1,3,0,5,2};
    int a[]={1,1,22,1,3};
    /*if(check_sorted(a,5))
        cout<<"sorted";
    else
        cout<<"not sorted";
    return 0;*/

    //cout<<"sum is "<<find_sum(a,5);
    //print_reverse(a,5);
    int p;
    cout<<"enter the element you want to search "<<endl;
    cin>>p;
    cout<<"index "<<search_last(a,5,p,0,-1);
}
// 2nd approach

/*bool check_sorted(int a[],int l,int i)
{
    if(i==l-1)
        return true;
    bool kyaaagesesortedmila=check_sorted(a,l,i+1);
    if(a[i]<=a[i+1] && kyaaagesesortedmila)
        return true;
    return false;
}*/

// 3rd approach  checking from backwards

/*bool check_sorted(int a[],int l)
{
    if(l==0 || l==1)// l==1 sirf us contion k liye hai jb array me sirf eek element hai
        return true;
   bool kyapichese=check_sorted(a,l-1);
    if(a[l-1]>=a[l-2]  && kyapichese)
        return true;
    return false;
}
*/


// sum
/*int find_sum(int a[],int l)
{
    if(l==1)// if(l==0)return 0;
        return a[0];
   int sum=a[0]+find_sum(a+1,l-1);
    return sum;
}
*/

// printing array in reverse order

/*void print_reverse(int a[],int l)
{
    if(l==0)
        return ;
    cout<<a[l-1];
    print_reverse(a,l-1);
}
*/
// searching element
/*
int search(int a[],int n,int ns,int i)// similar serching first index
{
    if(i==n)
        return -1;
    if(a[i]==ns)
        return i;
    return search(a,n,ns,i+1);
}*/
int search_last(int a[],int n,int ns,int i,int max_index)
{
    if(i==n)
        return -1;
    if(a[i]==ns)
    {
        if(max_index<i)
            max_index=i;
    }
    if(i==n-1)
        return max_index;
     search_last(a,n,ns,i+1,max_index);
}








