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
    char ch[100];int f,r;
    cout<<"enter the string :"<<endl;
    cin.getline(ch,100);
    int l=len(ch);
   // cout<<"length:"<<l<<endl;
    f=0;r=l-1;
    while(f<r)
    {
        if(ch[f]!=ch[r])
        {
            cout<<"not palindrome "<<endl;
            return 0;
        }
        f++;r--;
    }
    cout<<"palindrome"<<endl;
    return 0;

}
