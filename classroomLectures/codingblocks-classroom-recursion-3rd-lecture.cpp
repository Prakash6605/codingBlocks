#include<iostream>
using namespace std;
/* n staircase


*/
// mobile solver
char word[][5]={"'","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void find_code(char *in,char *output,int i,int j)
{
    if(in[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<endl;
        return ;
    }
    int index=in[i]-'0';
    for(int k=0;word[index][k]!='\0';k++)
    {
        output[j]=word[index][k];
        find_code(in,output,i+1,j+1);
    }
}
int main()
{
    char in[10],output[100];
    cout<<"enter your string :"<<endl;
    cin>>in;

    find_code(in,output,0,0);
}
/* suduko solver
int main()
*/
/*
1. tower of hanoi
void toh(int n,char source,char helper,char destination)
{
    if(n==0)
        return;
    toh(n-1,source,destination,helper);
    cout<<"moving "<<n <<" from source"<<source<<"to destination"<<destination<<endl;
    toh(n-1,helper,source,destination);
}

int main()
{
    int n;
    cin>>n;
    char source='A',helper='B',destinatio='C';
    toh(n,source,helper,destinatio);
}*/
/*
bool ratinmaze(char maze[10][10],char sol[][10],int i,int j,int n,int m)
{
    // base case
    if(i==n-1 && j==m-1)
    {
        sol[i][j]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<sol[i][j]<<" ";
            cout<<endl;
        }
        return true;
    }


    sol[i][j]='1';
    if(j+1<n && maze[i][j+1]!='x')
    {
        bool kyaaagerastamila=ratinmaze(maze,sol,i,j+1,n,m);
        if(kyaaagerastamila)
            return true;
    }
    if(i+1<n && maze[i+1][j]!='x')
    {
        bool kyanicherastamila=ratinmaze(maze,sol,i+1,j,n,m);
        if(kyanicherastamila)
            return false;
    }
    sol[i][j]='0';
    return false;
}
int main()
{
    char maze[10][10]={"0000","00xx","0000","xx00"};
    char sol[10][10]={{0}};
    char p=ratinmaze(maze,sol,0,0,4,4);
}
*/
/* permutation of string
void permutation(char in[],int i)
{
    if(in[i]=='\0')
     {
         cout<<in<<endl;
         return ;
     }

     for(int j=i;in[j]!='\0';j++)
     {
         swap(in[i],in[j]);
         permutation(in,i+1);
         swap(in[i],in[j]);// backtracking kuki agali calling me bhi usko us tym ka array cchiye hoga na;
     }

}
int main()
{
    char in[100];
    cin>>in;
    permutation(in,0);
}
*/

