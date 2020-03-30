#include<iostream>
using namespace std;
int main()
{
    char str[1000],str1[1000];int f[26]={0};//int f2[26]={0};
    cout<<"enter the string :"<<endl;
    cin.getline(str,100,'\n');
    cin.getline(str1,100,'\n');
    int i=0;
    while(str[i]!='\0')
    {
        int index=str[i]-'A';
      //  (a[index])++; first approach
       // cout<<a[index]<<endl;
       // f[index]=a[index];

       //second approach

       f[index]=f[index]+1;
        i++;
    }
    i=0;
    while(str1[i]!='\0')
    {
        int index=str1[i]-'A';
        f[index]=f[index]-1;
        i++;
    }

    for(i=0;i<26;i++)
        {if(f[i]!=0)
           {
               cout<<"not permutaion"<<endl;
               return 0;
           }
        }
        cout<<"Permutation "<<endl;


}
