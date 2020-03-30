//vectors
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a,int b)
{
    return a>b;
}

int main()
{
  vector<int>v;// vector<data type>vector_name;

  int n;
  cin>>n;
  for(int i=0;i<n;i++)
     {
       cin>>(v.push_back());// input tecnique
     }

   for(int i=0;i<n;i++)
  {
    cout<<v[i]<<" ";
  }
  cout<<endl;
  v.pop_back();// deleting element only ones
  v.pop_back();
  v.push_back(10);
  for(int i=0;i<n;i++)
  {
    cout<<v[i]<<" ";
  }
  cout<<endl;
  for(int i=0;i<v.size();i++)// v.size at present number of actual elements
  {                           // v.capacity() at present capacity of vector
    cout<<v[i]<<" ";
  }

  cout<<"\n  the present capacity "<<v.capacity()<<endl;

   cout<<"sorting"<<endl;

   sort(v.begin(),v.end(),compare);
   for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
   cout<<endl;


  return 0;


}
// vector class creation




/*
class Vector
{
public:
    int *arr;
    int cs;
    int ms;

    Vector(int n)
    {
        arr=new int[n];
        cs=0;
        ms=n;
    }

    void push_back(int data)
    {
        if(cs==ms)
        {
            int oldsize=ms;
            int *oldarr=arr;
            ms=2*ms;
            arr=new int[ms];
            for(int i=0;i<oldsize;i++)
            {

                arr[i]=oldarr[i];
            }
            delete []oldarr;
            //ms=ms*2;
        }
        arr[cs]=data;
        cs++;
    }

    void pop_back()
    {
        if(cs>0)
        {
            cs--;
        }
    }

    int size()
    {
        return cs;
    }

    int capacity()
    {
        return ms;
    }
    bool empty()
    {
        if(cs==0)
            return true;
        else
            return false;
    }
    int operator[](int i)// operator overloading of []
    {
        return arr[i];
    }
};

int main()
{
    Vector v(8);
    for(int i=0;i<8;i++)
        v.push_back(i);
    v.pop_back();
    v.pop_back();
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
*/
