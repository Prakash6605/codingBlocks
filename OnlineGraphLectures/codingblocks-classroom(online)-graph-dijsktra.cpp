#include<bits/stdc++.h>
using namespace std;

/*
int main()
{
    set<pair<int,int>> s;
    s.insert(make_pair(5,1));// value of 1 is 5
    s.insert(make_pair(3,2));// value of 2 is 3
    auto i=s.begin();
    i++;
    s.erase(s.begin(),i);
    for(auto i:s)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    //s.insert()
}
*/
template<typename T>
class graph
{
public:
    map<T,list<pair<T,int>>> adjlist;

    void addedge(T u,T v,int weight,bool bidir=true)
    {
        adjlist[u].push_back(make_pair(v,weight));
        if(bidir)
            adjlist[v].push_back(make_pair(u,weight));
    }

    void print()
    {
        for(auto i:adjlist)
        {
            cout<<i.first<<"-->";
            for(auto j:i.second)
            {
                cout<<j.first<<" "<<j.second<<"   ";
            }
            cout<<endl;
        }
    }

    void dijksitra(T src)
    {
       map<T,int> dist;
       for(auto i: adjlist)
        dist[i.first]=INT_MAX;
       dist[src]=0;

       set<pair<int,T>> s;// ye store krayga the current min vertex jiska distance sbse kam hai
       s.insert(make_pair(0,src));

       while(!s.empty())
       {
           auto p= *(s.begin());
           s.erase(s.begin());
           T currentNode=p.second;
           int distance_of_current_node=p.first;

           for(auto child : adjlist[currentNode])
           {
            if(dist[child.first]>distance_of_current_node+child.second)
            {
                dist[child.first]=distance_of_current_node+child.second;

                auto f=s.find(make_pair(dist[child.first],child.first));
                if(f!=s.end())
                    s.erase(f);
                s.insert(make_pair(dist[child.first],child.first));
            }
           }
       }

       for(auto i:dist)
       {
           cout<<i.first<<" have distance of "<<i.second <<" from "<<src<<endl;
       }
    }
};

int main()
{
    //graph<string> g;
    /*
    g.addedge(1,2,1);
    g.addedge(1,3,4);
    g.addedge(1,4,7);
    g.addedge(2,3,1);
    g.addedge(3,4,2);

    g.print();

    cout<<endl;
    g.dijksitra(1);
    */
    /*
    g.addedge("amritsar","jaipur",4);
    g.addedge("amritsar","delhi",1);
    g.addedge("jaipur","delhi",2);
    g.addedge("delhi","agra",1);
    g.addedge("agra","bhopal",2);
    g.addedge("bopal","mumbai",3);
    g.addedge("jaipur","mumbai",8);
    g.dijksitra("amritsar");
    return 0;
    */

    graph<int> g;
    g.addedge(0,7,8);
    g.addedge(0,1,4);
    g.addedge(1,7,11);
    g.addedge(7,8,7);
    g.addedge(1,2,8);
    g.addedge(7,6,1);
    g.addedge(2,8,2);
    g.addedge(8,6,6);
    g.addedge(6,5,2);
    g.addedge(2,5,4);
    g.addedge(2,3,7);
    g.addedge(3,5,14);
    g.addedge(3,4,9);
    g.addedge(5,4,10);

    g.dijksitra(0);
}
