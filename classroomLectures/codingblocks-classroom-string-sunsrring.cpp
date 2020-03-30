#include<iostream>
using namespace std;

int len(char *s)
{
    int i=0,l=0;
    while(s[i]!='\0')
    {
        i++;l++;
    }
    return l;
}
int main()
{
    char s[100];int l=0,i,j,k=0;
    cin>>s;
    l=len(s);
    while(k<l){
            int c=l;
    for(i=k;i<l;i++)
    {

        for(j=k;j<c;j++)
            cout<<s[j];
        cout<<endl;
        c--;
    }
    k++;}

}
