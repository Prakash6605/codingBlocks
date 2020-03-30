#include<iostream>
using namespace std;
int len(char *ch)
{
    int i=0,l=0;
    while(ch[i]!='\0')
    {
        l++;i++;
    }
    return l;
}
int main()
{
    char ch[100];int n,i,j;
    cout<<"enter the string "<<endl;
    cin>>ch;
    cout<<"enter n value :"<<endl;
    cin>>n;

    int l=len(ch);
    int k=1;
    for(i=l-1;i>=l-n;i--)
    {
        char c=ch[i];
        for(j=l-1-k;j>0;j--)
        {
            ch[j+1]=ch[j];
        }
        ch[0]=c;
        k++;
    }
    cout<<ch;
}
