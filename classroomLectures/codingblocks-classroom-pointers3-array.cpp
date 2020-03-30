#include<iostream>
using namespace std;
void bubble_sort(int*,int);
void selection_sort(int *a,int n)
{
    int i,j,minpos,t=0;
    for(i=0;i<n-1;i++)
    { minpos=i;
        for(j=i+1;j<n;j++)
        {
            if(*(a+j)<*(a+minpos))
                minpos=j;
        }
        t=*(a+i);
        *(a+i)=*(a+minpos);
        *(a+minpos)=t;
    }
    cout<<"\n Printing sorted array \n";
    for(i=0;i<n;i++)
        cout<<*(a+i)<<" ";
}
int main()
{
  int a[100],n;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  selection_sort(a,n);
  bubble_sort(a,n);
}
void bubble_sort(int *a,int n)
{
    int i,j,t=0,s;
    for(i=0;i<n-1;i++)
    {  s=0;
        for(j=0;j<n-1-i;j++)
        {
            if(*(a+j)>*(a+j+1))
            {   s=1;
                t=*(a+j);
                *(a+j)=*(a+j+1);
                *(a+j+1)=t;
            }
        }
        if(s==0)
            break;

    }
    cout<<"\n Printing sorted array \n";
    for(i=0;i<n;i++)
        cout<<*(a+i)<<" ";
}
