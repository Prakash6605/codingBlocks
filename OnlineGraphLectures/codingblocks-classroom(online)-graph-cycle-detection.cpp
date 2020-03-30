#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<typename T>
class graph{

public:
     map<T,list<T>> adjlist;

    graph(){

    }

    void addedge(T u,T v,bool bidir=true)
    {
        adjlist[u].push_back(v);
        if(bidir)adjlist[v].push_back(u);
    }

    /*
    void detect_cycle_in_undirected_graph(T src)
    {//cout<<"here";
        queue<T> q;
        map<T,bool> visited;
        q.push(src);
        visited[src]=true;
        map<T,T> parent;
        parent[src]=src;

        while(q.empty()!=true)
        {
            T node=q.front();
            cout<<"poped value :"<<node<<endl;
            q.pop();

            for(auto i:adjlist[node])
            {
                cout<<i<<" for node :"<<node<<endl;
                if(visited[i]==true && parent[node]!=i)
                {
                    cout<<"cycle is present"<<endl;
                    return;
                }

                if(visited[i]==false){
                visited[i]=true;
                parent[i]=node;
                q.push(i);}
            }
        }
        cout<<"no cycle present"<<endl;
        return;

    }
    */
    bool helper(T src,map<T,bool> &visited,map<T,bool> &inStack)
    {
        visited[src]=true;
        inStack[src]=true;

        for(auto j: adjlist[src])
        {
            if(visited[j] && inStack[j])
                return true;
            else if(!visited[j])
            {
                bool check1 =helper(j,visited,inStack);
                if(check1)
                    return true;
            }
        }
        inStack[src]=false;
        return false;
    }
    bool detect_cycle_in_directed_graph()
    {

        map<T,bool> visited;
        map<T,bool> inStack;

        for(auto i:adjlist)
        {
            if(!visited[i.first]){
            bool check=helper(i.first,visited,inStack);
            if(check)
                return true;
            }
        }
        return false;
    }
};
int main()
{
    graph<int> g;
    /*
    undirected graph
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,3);
    g.addedge(3,2);
    g.addedge(2,4);
    g.addedge(4,5);*/
    //directed graph

    g.addedge(0,2,false);
    g.addedge(0,1,false);
    g.addedge(2,3,false);
    g.addedge(2,4,false);
    g.addedge(4,5,false);
    g.addedge(1,5,false);
    //g.addedge(3,0,false);
    if(g.detect_cycle_in_directed_graph())
        cout<<"present"<<endl;
    else
        cout<<"not present"<<endl;

   // g.detect_cycle_in_undirected_graph(0);
}
