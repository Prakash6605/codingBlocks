#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;
class edge
{
public:
    int src, dest;
};
class graph
{
public:
    edge *edgelist;
    int *parent;
    int e,v;

    graph(int v,int e)
    {
        this->e=e;
        this->v=v;
        parent=new int[v];
        for(int i=0;i<v;i++)
            parent[i]=-1;
        edgelist=new edge[e];
    }
    void addedge(int u,int v,int countt)
    {
        edgelist[countt].src=u;
        edgelist[countt].dest=v;
    }

    ull fact(int n)
    {
        ull f=1;
        for(ull i=1;i<=n;i++)
            f=f*i;
        return f;
    }

    int findparent(int child)
    {
        if(parent[child]<0)
            return child;
        else
            return findparent(parent[child]);
    }



    ull parentt()
    {
        for(int i=0;i<e;i++)
        {
            int v1=edgelist[i].src;
            int v2=edgelist[i].dest;

            int p1=findparent(v1);
            int p2=findparent(v2);

            if(p1!=p2){
            if(parent[p1]==parent[p2])
            {
                parent[p1]+=parent[p2];
                parent[p2]=p1;
            }
            else if(parent[p1]!=parent[p2])
            {
                if(parent[p1]>parent[p2])
                {
                    parent[p1]+=parent[p2];
                    parent[p2]=p1;
                }
                else
                {
                    parent[p2]+=parent[p1];
                    parent[p1]=p2;
                }

            }
            }
        }
        ull a=0,ans=0;int c=0;
        for(int i=0;i<v;i++)
        {
            if(parent[i]<-1)
            {
                 a+=(-parent[i])*((-parent[i])-1)/2;
            }
            /*if(parent[i]==-1)
            {
                c++;
            }*/
        }
        //a=a+c;
        ans=((v*(v-1))/2)-a;
        return ans;
    }
};

int main()
{
    int n,p;
    cin>>n>>p;
    graph g(n,p);
    for(int i=0;i<p;i++)
    {
        int u,v;
        cin>>u>>v;

        g.addedge(u,v,i);
    }
    cout<<g.parentt()<<endl;
}

