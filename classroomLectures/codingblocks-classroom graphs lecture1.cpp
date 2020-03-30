#include<iostream>
#include<list>
using namespace std;

class graph
{
    int v;
    list<int>* adjlist;

public:
    graph(int V)
    {
        v=V;
        adjlist=new list<int>[V];
    }

    void addEdge(int u ,int v,bool bidirectional=true)
    {
        adjlist[u].push_back(v);
        if(bidirectional)
        {
            adjlist[v].push_back(u);
        }
    }

    void print()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<"-->";
            for(auto node:adjlist[i])// for each loop ,auto - automatically detects data type
            {
                cout<<node<<" ";
            }
            cout<<endl;
        }
    }


};




int main()
{
    graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);


    g.print();
}
