#include<bits/stdc++.h>
using namespace std;

class graph
{
public:
    int v;
    map<int,list<int>> m;


    graph(int v)
    {
        this->v=v;
    }

    void addedge(int u,int v,bool bidir=true)
    {
        m[u].push_back(v);
        if(bidir)
        {
            m[v].push_back(u);
        }
    }

    void print()
    {
        for(auto i:m)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
                cout<<j<<" ";
            cout<<endl;
        }
    }

    bool checkBipartitle(int src)
    {
        int color[v];
        bool visited[v];
        for(int i=0;i<v;i++)
            {color[i]=-1;visited[i]=false;}
        color[src]=0;
        visited[src]=true;
        queue<int> q;
        q.push(src);

        while(!q.empty())
        {
            int p=q.front();
            q.pop();

            for(auto i:m[p])
            {
                if(color[i]==-1)
                {
                    if(color[p])
                        color[i]=0;
                    else
                        color[i]=1;
                    ///make id not of color of p
                }
                else if(color[i]==color[p])
                {
                    return false;
                }
                if(visited[i]==false){
                q.push(i);
                visited[i]=true;}
            }
        }
        /*for(int i=0;i<v;i++)
            cout<<color[i]<<" ";*/
        return true;
    }



};

int main()
{
    int v,e;
    cin>>v>>e;
    int u,vv;
    graph g(v);
    while(e--)
    {
        cin>>u>>vv;
        g.addedge(u-1,vv-1);
    }
   g.print();
   if(g.checkBipartitle(0))
   {
       cout<<"YES";
   }
   else
   {
       cout<<"NO";
   }

}

