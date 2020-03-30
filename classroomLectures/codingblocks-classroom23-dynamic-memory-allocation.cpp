#include<iostream>
using namespace std;
int main()
{
    int *p=new int;
    *p=10;
    cout<<*p<<" "<<p<<endl;
    delete p;
   // p=NULL;// NULL IS my memory 0th index
    cout<<"here "<<*p<<" "<<p<<endl;// delete ho chuka hai bs jb tk or koi ata nhi hai wo hold krra hai

    // 1-d array dynamically

    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>*(a+i);
    }
    for(int i=0;i<n;i++)
    {
        cout<<*(a+i)<<" ";
    }

    delete []a;// deleting f=dynamically allocated memory to array

    //whole 2-d array dynamically
     int r,c;
     cin>>r>>c;

     int **arr=new int*[r];// one d array for storing the address of each row
     for(int i=0;i<r;i++)
        arr[i]=new int[c];// each value in one d array get the starting address of each row of 2d array


    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            arr[i][j]=i*j;
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    for(int i=0;i<r;i++)
        delete []arr[i];
    delete []arr;

    arr=NULL;


}
