#include<bits/stdc++.h>
using namespace std;
int wine_rec(int *bottel,int start,int end,int day)
{
    if(start>end)
    {
        return 0;
    }
    int op1=bottel[start]*day+wine_rec(bottel,start+1,end,day+1);
    cout<<"\n op1 "<<op1<<" when "<<" start "<<start<<" end "<<end;
    int op2=bottel[end]*day+wine_rec(bottel,start,end-1,day+1);
    cout<<"\n op2 "<<op2<<" when "<<" start "<<start<<" end "<<end;
    return max(op1,op2);
}
int main()
{
    int n;
    cin>>n;
    int bottel[1000];
    cout<<"Enter wines bottel "<<endl;
    for(int i=0;i<n;i++)
        cin>>bottel[i];

    cout<<wine_rec(bottel,0,n-1,1);//array,starting ,end,day
}
