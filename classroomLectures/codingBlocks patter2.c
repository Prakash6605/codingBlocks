#include<stdio.h>
#include<math.h>
void main()
{
    int n,l=0;
    printf("\n enter the number :");
    scanf("%d",&n);
    int cn=n;
    while(cn>0)
    {
        cn=cn/10;
        l++;
    }
    printf("\n length : %d\n",l);
    int i=1,r;int k=10,s=0,r1;
    while(i<=l)
    {
        r=n%(int)(pow(k,i));
        s=0;r1=0;
        while(r>0)
        {
            r1=r%10;
            s=s*10+r1;
            r=r/10;
        }
        printf("%d ",s);
        printf("\n");
        i++;
       // n=n/(pow(10,i));
    }
}
