#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<unordered_map>
#include<stack>
#include<cstring>
using namespace std;

template<typename T>
class graph{

public:
    int vertex;
    unordered_map<T,list<T>> arr;

    graph()
    {


    }

    addEdge(T u,T v,bool bidir=true)
    {

        arr[u].push_back(v);
        if(bidir)
            arr[v].push_back(u);
    }

    void printList()
    {
        for(auto i:arr)
           {
               cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<" ";
            }
            cout<<endl;
           }
    }


    void bfs(T src)
    {
        queue<T> q;
        map<T,bool> visited;///by default false

        q.push(src);
        visited[src]=true;

        while(q.empty()!=true)
        {
            T node=q.front();
            q.pop();
            cout<<node<<" ";
            for(auto i:arr[node])
            {
                if(visited[i]==false)
                {
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }

    void sssp(T src)///using bfs ,hmlog jb bhi bfs use kraynge the graph should be unweighted
    {
        queue<T> q;
        map<T,int> distance;// to store the distance of node
        map<T,T>parent;
        parent[src]=src;

        for(auto i:arr)
        {
            distance[i.first]=INT_MAX;
        }
        distance[src]=0;
        q.push(src);

        while(q.empty()!=true)
        {
            T node=q.front();
            q.pop();
            for(auto i:arr[node])
            {
                if(distance[i]==INT_MAX)
                {
                    q.push(i);
                    parent[i]=node;
                    distance[i]=distance[parent[i]] + 1;

                }
            }

        }

        for(auto i:arr)
            cout<<i.first<<" "<<distance[i.first]<<" ";
        cout<<endl;
    }
    /*
    void dfs(T src)
    {
        stack<T> s;
        s.push(src);
        cout<<src<<" ";
        map<T,bool> visited;
        visited[src]=true;
        int flag=0;
        while(s.empty()!=true)
        {
            T p=s.top();
            //cout<<p<<" ";
            flag=0;
            for(auto j:arr[p])
            {
                flag=0;
                if(visited[j]==false)
                { //cout<<"\n pusing :";
                    cout<<j<<" ";
                    s.push(j);
                    visited[j]=true;
                    flag=1;
                    break;
                }
            }
            if(flag==0)/// no nodes from that source to visit;
            {
                //cout<<"\n popping ->"<<s.top()<<"\n";
                s.pop();
                flag=0;
            }
        }
    }*/
    void dfshelper(T src,map<T,bool> &visited)
    {
        cout<<src<<" ";
        for(auto i:arr[src])
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                dfshelper(i,visited);
            }
        }
    }
    void dfs(T src)
    {
        map<T,bool> visited;
        visited[src]=true;
        int component=1;
        dfshelper(src,visited);

        for(auto i:arr)
        {
            if(visited[i.first]==false)
            {component++;
                visited[i.first]=true;
                dfshelper(i.first,visited);
            }
        }

        cout<<"\n connected components :"<<component<<endl;
    }



    void topologicalHelper(T src,unordered_map<T,bool> &visited,list<T> &ordering)
    {
        //cout<<"src :"<<src<<endl;
        visited[src]=true;
        for(auto i:arr[src])
        {//cout<<"\n i :"<<i<<endl;
            if(visited[i]==false)
            {
                topologicalHelper(i,visited,ordering);

            }

        }//ordering.push_front(src);
    }
    void topologicalSort()
    {
        unordered_map<T,bool> visited;
        list<T> ordering;

        for(auto i:arr)
        {
            if(visited[i.first]==false)
            {
                topologicalHelper(i.first,visited,ordering);
            }
        }

        for(auto i=ordering.begin();i!=ordering.end();i++)
            cout<<*i<<" ";
    }

    ///topological sort using bfs-khan's algorithm

    topological_sort_bfs()
    {
        map<T,bool> visited;
        map<T,int> indegree;
        queue<T> q;
        for(auto i: arr)
        {
            indegree[i.first]=0;
        }

        for(auto i:arr)
        {
            for(auto j: i.second)
            {
                indegree[j]++;
            }
        }

        for(auto i:arr)
        {
            if(indegree[i.first]==0)
                q.push(i.first);
        }


        while(q.empty()!=true)
        {
            T node=q.front();
            cout<<node<<" ";
            q.pop();

            for(auto i :arr[node])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
        }
    }
};


int main()
{
    graph<string> g;
    /*g.addEdge("putin","trump",false);
    g.addEdge("putin","modi",false);
    g.addEdge("putin","pope",false);
    g.addEdge("trump","modi");
    g.addEdge("prabhu","modi",false);
    g.addEdge("modi","yogi");
    g.addEdge("yogi","prabhu",false);
    g.printList();*/

    /*
    g.addEdge("amritsar","jaipur");
    g.addEdge("amritsar","delhi");
    g.addEdge("jaipur","delhi");
    g.addEdge("jaipur","mumbai");
    g.addEdge("delhi","bopal");
    g.addEdge("mumbai","bopal");
    g.addEdge("mumbai","bangalore");
    g.addEdge("delhi","agra");
    g.addEdge("andaman","nicobar");
*/
    g.addEdge("eng","programmingLogic",false);
    g.addEdge("maths","programmingLogic",false);
    g.addEdge("eng","html",false);
    g.addEdge("programmingLogic","html",false);
    g.addEdge("programmingLogic","jss",false);
    g.addEdge("programmingLogic","python",false);
    g.addEdge("programmingLogic","java",false);
    g.addEdge("html","css",false);
    g.addEdge("python","webDevelopment",false);
    g.addEdge("java","webDevelopment",false);
    g.addEdge("css","jss",false);
    g.addEdge("jss","webDevelopment",false);
    g.printList();
    //cout<<"************BFS**********\n";
    //g.bfs("putin");
    //g.bfs("amritsar");

    cout<<"\n";
    //g.sssp("putin");
   // g.sssp("delhi");

    //cout<<"\n ***************DFS***********\n";
    //g.dfs("putin");
    //g.dfs("amritsar");

    //g.topologicalSort();
    g.topological_sort_bfs();
}

