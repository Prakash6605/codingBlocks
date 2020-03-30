#include<iostream>
using namespace std;
//void count_note(int *,int,int);
int main()
{   int amt,p=0,i=0,j,diff=0;
    int note[]={1,2,5,10,20,50,100,200,500,2000};
    int len=(sizeof(note)/sizeof(int));
    cout<<"len"<<len<<endl;
    cout<<"Enter the amount :"<<endl;
    cin>>amt;

   /* for( i=len-1;i>=0;i--)
        cout<<note[i]<<" ";*/
    cout<<endl;
        while(amt>=1){

        for( j=9;j>=0;j--)
        {   diff=amt-note[j];
            if(diff>=0)
            {
                break;
            }
            //p++;
        }
        amt=amt-note[j];
        if(note[j]<=5)
            cout<<note[j]<<" coin , to make "<<amt<<endl;
        else
            cout<<note[j]<<" notes , to make "<<amt<<endl;
       // count_note(a,l,amt);
       p++;
    }
    return 0;
}
