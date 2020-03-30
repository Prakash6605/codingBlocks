#include<iostream>
#include<list>

using namespace std;

class graph
{
public:
    int v;
    list<int>* l;

    graph(int V)
    {
        this->v=V;
        l=new list<int>[V];
    }

    void addEdge(int u,int v,bool bidir=true)
    {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
    }
    void printAdjList()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<"->";

            for(auto j:l[i])
                cout<<j<<" ";
            cout<<endl;
        }
    }
};

int main()
{
    graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,1);
    g.addEdge(4,3);
    g.addEdge(3,1);
    g.addEdge(3,2);
    g.addEdge(2,1);

    g.printAdjList();
}
