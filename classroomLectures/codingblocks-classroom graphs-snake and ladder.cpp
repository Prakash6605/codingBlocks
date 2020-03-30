#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;

template<typename T>
class graph{

    map<T, list<T> >adjlist;

    public:

    void addEdge(T u,T v,bool bidirectional=true)
    {
        adjlist[u].push_back(v);
        if(bidirectional)
        {
            adjlist[v].push_back(u);
        }
    }

    void print()
    {
        for(auto node:adjlist)
        {
            cout<<node.first<<"-->";
            for(auto child:node.second)
                cout<<child<<" ";
            cout<<"\n";
        }
    }
    void BFS(T start)
{
    queue<T>q;
    map<T,bool>visited;
    q.push(start);
    visited[start]=true;

    while(!q.empty())
    {
        T top=q.front();
        q.pop();
        cout<<top<<" ";

        for(auto child:adjlist[top])
        {
            if(!visited[child])
            {
                q.push(child);
                visited[child]=true;
            }
        }
    }


}
     void single_source_shortest_path(T start)
     {
         queue<T>q;
    //map<T,bool>visited;
    map<T,int>distance;
   /* for(int i=0;i<4;i++)
        distance[i]=INT_MAX;*/

    for(auto node:adjlist)
    {
        distance[node.first
        ]=INT_MAX;
    }
    q.push(start);
   // visited[start]=true;
      distance[start]=0;
    while(!q.empty())
    {
        T top=q.front();
        q.pop();
        cout<<top<<" ";

        for(auto child:adjlist[top])
        {
            if(distance[child]==INT_MAX)
            {
                q.push(child);
                distance[child]=1+distance[top];
            }
        }
    }

    for(auto i:distance)
        cout<<i.first<<" "<<i.second<<" ";


     }
};


// traversal
//1. BFS

/*void BFS(T start)
{
    queue<T>q;
    map<T,bool>visited[];
    q.push(start);
    visited[start]=true;

    while(!q.empty())
    {
        T top=q.front();
        q.pop();
        cout<<top<<" ";

        for(auto child:addlist[top])
        {
            if(!visited[child])
            {
                q.push(child);
                visited[child]=true;
            }
        }
    }


}
*/
int main()
{
graph<int>g;
int board[50] = {0};
board[2] = 13;
board[5] = 2;
board[9] = 18;
board[18] = 11;
board[17]=-13;
board[20] = -14;
board[24] = -8;
board[25] = -10;
board[32] = -2;
board[34] = -22;

for(int u=0;i<=36;i++)
{
    for(int dice=1;dice<=6;dice++)
    {
        int v=u+dice+board[u+dice];
        g.addEdge(u,v,false);
    }
}
    g.single_source_shortest_path(0,36);
    return 0;
}

