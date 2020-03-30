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
    int n;char ch[100],ch1[100],j=0,maxl=INT_MIN,i,l;
    cin>>n;
    cin.ignore();
    for(i=0;i<n;i++)
    {
        cin.getline(ch,100);
        l=len(ch);
        if(l>maxl)
            {maxl=l; j=0;
            while(ch[j]!='\0')
            {
                ch1[j]=ch[j];
                j++;
            }
            ch1[j]='\0';
        }
    }
    cout<<ch1<<endl;
}
