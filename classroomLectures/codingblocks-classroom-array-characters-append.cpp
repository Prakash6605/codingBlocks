#include<iostream>
using namespace std;
void append(char*,char*);
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
    char ch1[100],ch2[100];
    cout<<"enter both string"<<endl;
    cin.getline(ch1,100);
    cin.getline(ch2,100);

    append(ch1,ch2);

    cout<<"appended string :"<<ch1<<endl;

}
void append(char *ch1,char *ch2)
{
    int i=0;
    int l=len(ch1);
    //cout<<"here"<<ch1[l+0]<<endl;
    //ch1[l]='p';
    //cout<<ch1[l]<<endl;
    while(ch2[i]!='\0')
    {

        ch1[l+i]=ch2[i];
        cout<<ch1[l+i]<<" "<<ch2[i]<<endl;
        i++;
    }
    ch1[l+i]='\0';
}
