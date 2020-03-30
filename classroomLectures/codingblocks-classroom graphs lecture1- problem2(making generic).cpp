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

      void DFShelper( T  src ,map<T,bool>&visited)
  {
      cout<<src<<" ";
      visited[src]=true;

      for(auto node:adjlist[src])
      {
          if(visited[node]!=true)
          {
              DFShelper(node,visited);
          }
      }
  }
  void DFS(T src)
  {
      map<T,bool>visited;
      DFShelper(src,visited);
      int component=1;
      for(auto node:adjlist)
      {
        if(visited[node.first]!=true)
        {
            cout<<endl;
            component++;
            DFShelper(node.first,visited);
        }
      }

      cout<<component<<endl;
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
    graph<string> g;
    g.addEdge("modi","yogi",false);
    g.addEdge("modi","trump",false);
    g.addEdge("prabhu","modi",false);
    g.addEdge("trump","modi",false);
    g.addEdge("yogi","modi",false);
    g.addEdge("yogi","prabhu",false);
    g.addEdge("putin","trump",false);
    g.addEdge("putin","modi",false);
    g.addEdge("putin","pope",false);

    //g.print();

  //  g.BFS("modi");

   // g.single_source_shortest_path("modi");
   g.DFS("putin");
    return 0;
}
