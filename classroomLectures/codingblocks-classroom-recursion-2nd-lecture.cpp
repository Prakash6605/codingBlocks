#include<iostream>
#include<cstring>
using namespace std;

bool issafeToPut(int a[][10],n,int i,int j)
{
    for(k=0;k<n;k++)
    {
        if(a[k][j] || a[i][k])// checking for horizontal and checking for vertical
            return false;// unsafe because either of row or that col contains 1
    }
    int p=i;
    int l=j;
    while(p>=0 && l<=n-1)
    {
        if(a[i][l])
            return false;
        p--;l--;
    }
    p=i;l=j;
    while()
}
bool nqueen(int n,int a[][10],int row)
{
    if(row==n)
       {
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<n;j++)
                cout<<a[i][j];
               cout<<endl;
           }
         return true;
       }

       for(int col=0;col<n;col++)
       {
           if(issafeToPut(a,))
       }

}
int main()
{
    int n;int a[10][10]={0};
    cin>>n;
    nqueen(n,a,0);
}
/* subsequence




#include<iostream>
using namespace std;


void subsequences(char *in,char *out,int i,int j)
{

	//base case
	if(in[i]=='\0')
	{
		out[j]='\0';
		cout<<out<<endl;
		return;
	}


	//include
	out[j]=in[i];
	subsequences(in,out,i+1,j+1);
	//exclude
	subsequences(in,out,i+1,j);

}


int main()
{
	char in[100];
	cin>>in;
	char out[100];

	subsequences(in,out,0,0);
    cout<<endl;

}

/*void subsequence(char *s,int i,int j)
{

}
*/
/*
void merge(int *a,int *x,int *y,int s,int e)
{
    int i=s;
    int mid=(s+e)/2;
    int j=mid+1;

    int k=s;// bcoz jo bhi x ka start hoga wo 'a' ka start hoga

    while(i<=mid && j<=e)
    {
        if(x[i]<y[j])
        {
            a[k]=x[i];i++;k++;
        }
        else
        {
            a[k]=y[j];j++;k++;
        }

    }
    while(i<=mid)
    {
        a[k]=x[i];
        i++;k++;
    }
    while(j<=e)
    {
        a[k]=y[j];
        j++;k++;
    }
}
void mergesort(int *a,int s,int e)
{
    if(s>=e)
        return;
    int mid=(s+e)/2;
    int x[1000],y[1000];
    for(int i=s;i<=mid;i++)
        x[i]=a[i];

    for(int i=mid+1;i<=e;i++)
        y[i]=a[i];

    mergesort(a,s,mid);
    mergesort(a,mid+1,e);

    merge(a,x,y,s,e);


}
int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++)
        cin>>a[i];

    mergesort(a,0,n-1);

    for(int i=0;i<n;i++)
        cout<<a[i];
}*/
/*int binary_search(int *a,int n,int ns ,int ul,int ll)
{
    if(ul>ll)
        return 0;
    int mid=(ul+ll)/2;
    if(ns>a[mid])
        return (binary_search(a,n,ns,mid+1,ll));
    else if(ns<a[mid])
        return (binary_search(a,n,ns,ul,mid-1));
    else
        return 1;
}
int main()
{
    int n,a[1000],ns,ul,ll;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"enter the ele to be searched"<<endl;
    cin>>ns;

    if(binary_search(a,n,ns,0,n-1))
        cout<<"found";
    else
        cout<<"not found";
}
*/
//int sum=0;
// converting string to integer using recursion

/*int convert(char *s,int i,int sum)// my implementation
{
    if(i==strlen(s))
        return sum ;
    sum=sum*10+s[i]-'0';
   return (convert(s,i+1,sum));
}
int convert(char *s,int l)
{
    if(l==0)
        return 0;
    int lastterm=s[l-1]-'0';
    return ((convert(s,l-1))*10+lastterm);
}
int main()
{
    char str[1000];
    cin.getline(str,100);
    //cout<<convert(str,0,0);
    cout<<convert(str,strlen(str));
}

/*
void bubble_sort(int *a,int n,int i)
{
    if(i==n-1)
        return;
    for(int j=0;j<n-1-i;j++)
    {
        if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
    }
    bubble_sort(a,n,i+1);
}
// bubble sort 2nd approach
void bubble_sort(int *a,int n,int i,int j)
{
    if(i==n-1)
        return ;
   if(j==n-1-i)
   {
       bubble_sort(a,n,i+1,0);
       return;
   }
   if(a[j]>a[j+1])
   {
    swap(a[j],a[j+1]);
   }
   bubble_sort(a,n,i,j+1);
}
int main()
{
    int a[1000];int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
   // bubble_sort(a,n,0);
      bubble_sort(a,n,0,0);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
*/
