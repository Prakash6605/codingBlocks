#include<bits/stdc++.h>
#define inf 1e9
using namespace std;

class Edge
{
public:
    int source;int destination;int weight;
};

class Graph
{
public:
    int v,e;/// no of vertices and edges in graph
    Edge *edgeList;

    Graph(int v,int e)
    {
        this->v=v;
        this->e=e;
        edgeList=new Edge[e];
    }

    void addEdge(int svert,int dvert,int w,int countt)
    {
        edgeList[countt].source=svert;
        edgeList[countt].destination=dvert;
        edgeList[countt].weight=w;
    }

    void BellmanFord(int src)
    {
        int distance[v];
        for(int i=0;i<v;i++)
        {
            if(i==src)
                distance[i]=0;
            else
                distance[i]=inf;
        }

        ///relaxation code:- we were supposed to do the relaxation v-1 times.
          for(int i=0;i<=v-1;i++)/// iterating v-1 times
          {
              for(int j=0;j<=e-1;j++)/// for each v-1 iteration, iterating over all edges
              {
                int src=edgeList[j].source;
                int dest=edgeList[j].destination;
                int wt=edgeList[j].weight;
                /// relaxation check
                if(distance[dest]>distance[src]+wt)
                {
                    distance[dest]=distance[src]+wt;
                }
              }
          }
          ///check for negative weight cycle
          for(int j=0;j<=e-1;j++)/// for each v-1 iteration, iterating over all edges
              {
                int src=edgeList[j].source;
                int dest=edgeList[j].destination;
                int wt=edgeList[j].weight;
                /// relaxation check
                if(distance[dest]>distance[src]+wt)
                {
                    cout<<"Negative weight Cycle is present"<<endl;
                    return;
                }
              }

              cout<<" Printing the final distances of vertices for src"<<endl;
              for(int i=0;i<v;i++)
              {
                  cout<<i<<" "<<distance[i]<<endl;
              }
    }
};

int main()
{
    int v,e;
    cin>>v>>e;
    Graph g(v,e);
    for(int i=0;i<e;i++)
    {
        int src,des,wt;
        cin>>src>>des>>wt;
        g.addEdge(src,des,wt,i);
    }
    g.BellmanFord(0);
    return 0;
}
