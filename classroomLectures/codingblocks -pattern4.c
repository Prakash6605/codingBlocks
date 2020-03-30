#include<stdio.h>
void main()
{
    int i,val,j,n;
    printf("\n enter n :");
    scanf("%d",&n);
    for( i=1;i<=n;i++)
    {
      if(i%2==0)
        val=1;
      else
        val=0;
      for(j=1;j<=i;j++)
      {
          val=1-val;
          printf("%d",val);
      }
      printf("\n");

    }
}
