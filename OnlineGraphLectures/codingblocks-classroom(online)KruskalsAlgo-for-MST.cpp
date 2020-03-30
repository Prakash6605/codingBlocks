#include<bits/stdc++.h>
using namespace std;

int weight=0;
class graph
{
public:
    multimap<int,pair<int,int>> edgelist;
    int *parent;
    int e,v;

    graph(int v,int e)
    {
        parent=new int[v+1];
        for(int i=0;i<v;i++)
            parent[i+1]=-1;
        this->e=e;
        this->v=v;
        parent[0]=0;
    }

    void addedge(int v11,int v22,int wtt,int countt)
    {
        edgelist.insert({wtt,make_pair(v11,v22)});
    }
    int findparent(int child)
    {
        if(parent[child]<0)
        {
            return child;
        }
        else
            return findparent(parent[child]);

    }
    void MstKruskals()
    {
        multimap<int,pair<int,int>> mst;
        for(auto i:edgelist)
        {

            //cout<<i.first<<endl;
            int wt=(i.first);
            pair<int,int> p=(i.second);
            int v1=p.first;int v2=p.second;
            cout<<"for :"<<"wt :"<<wt<<"edge"<<v1<<" "<<v2<<endl;

            if(parent[v1]==-1 && parent[v2]==-1)
            {
                ///empty set
                parent[v1]+=parent[v2];
                parent[v2]=v1;
                mst.insert({wt,make_pair(v1,v2)});
                weight+=wt;
            }
            else
            {
                int x=findparent(v1);int y=findparent(v2);
                if(x==y)
                {
                    cout<<"contains cycle"<<endl;
                }
                else if(parent[x]==parent[y])
                {
                    cout<<"here in eqaul"<<endl;
                    parent[x]+=parent[y];
                    parent[y]=x;
                    weight+=wt;
                    mst.insert({wt,make_pair(v1,v2)});
                }
                else if(parent[x]!=parent[y])
                {
                    cout<<"here in not equal"<<endl;
                    if(parent[x]>parent[y])
                    {
                        parent[x]+=parent[y];
                        parent[y]=x;
                    }
                    else
                    {
                        parent[y]+=parent[x];
                        parent[x]=y;
                    }
                    weight+=wt;
                    mst.insert({wt,make_pair(v1,v2)});
                }

            }
            if(mst.size()==v-1)
                break;
        }
        for(auto i:mst)
        {
            cout<<"weight :"<<i.first<<" ";
            pair<int,int> p=i.second;
            cout<<p.first<<" "<<p.second<<endl;
        }
    }



};
int main()
{
   // graph g;
    int v,e;
    cin>>v>>e;
    graph g(v,e);
    for(int i=0;i<e;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        g.addedge(v1,v2,wt,i);
    }
    g.MstKruskals();
    cout<<"\n Weight "<<weight<<endl;
}

