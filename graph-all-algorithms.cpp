#include<iostream>
#include<map>
#include<bits/stdc++.h>
using namespace std;

///graph implementation using adjacency list where key are in number format
/*
class graph{
public:
    int vertices;
    list<int> *l;// making a pointer of type linked list

    graph(int v){
      vertices=v;
      l=new list<int>[v];
    }

    void addedge(int u,int v,bool bidir=true){
      l[u].push_back(v);
      if(bidir)
        l[v].push_back(u);
    }

    void print(){
      for(int i=0;i<vertices;i++){
            cout<<"l["<<i<<"] =>";
        for(list<int>::iterator j=l[i].begin();j!=l[i].end();j++)
            cout<<*j<<" ";
        cout<<endl;
      }
    }

};

int main(){
  int v;
  cout<<"Enter number of vertices in the graph"<<endl;
  cin>>v;

  graph g(v);

  g.addedge(0,1);
  g.addedge(0,4);
  g.addedge(4,1);
  g.addedge(4,3);
  g.addedge(3,1);
  g.addedge(1,2);
  g.addedge(2,3);

  g.print();

}
*/

/// generic graph implementation using map<T,list<T> g;
/*
template<typename T>
class graph{
public:
    map<T,list<T> > g;

    graph(){

    }

    void addedge(T u,T v, bool bidir=true){
      g[u].push_back(v);
      if(bidir)
        g[v].push_back(u);
    }

    void print(){
      for( auto i : g ){
        cout<<i.first<<"->";
        for(auto j:i.second){
            cout<<j<<" ";
        }
        cout<<endl;
      }

    }

};

int main(){
  graph<string> g;
  g.addedge("amritsar","delhi");
  g.addedge("amritsar","jaipur");
  g.addedge("jaipur","delhi");
  g.addedge("delhi","agra");
  g.addedge("jaipur","mumbai");
  g.addedge("mumbai","bopal");
  g.addedge("mumbai","bangalore");

  g.print();
}

*/

/// BFS(Breadth First Search)
/*
template<typename T>
class graph{
public:
    map<T,list<T> > adjlist;

    void addedge(T u,T v,bool bidir = true){
      adjlist[u].push_back(v);
      if(bidir)
        adjlist[v].push_back(u);
    }

    void print(){
      for(auto i: adjlist){
        cout<<i.first<<"=>";
        for(auto j: i.second)
            cout<<j<<" ";
         cout<<endl;
      }
    }
    // breadth first search algorithm using queue
    void BFS(T src){
      queue<T> q;
      q.push(src);
      map<T, bool> visited;
      for(auto i:adjlist)visited[i.first]=false;
      visited[src]=true;

      while(!q.empty()){
        auto t=q.front();
        q.pop();
        cout<<t<<" ";
        for(auto j:adjlist[t]){
            if(visited[j]!=true){
            q.push(j);
            visited[j]=true;}
        }
      }

    }
    // single source shortest path in bidirectional graph (i.e) all edge have same weight
    void sssp(T src){
     map<T,bool>visited;
     map<T,T>parent;
     map<T,int> distance;
     for(auto i:adjlist){
        distance[i.first]=INT_MAX;
        visited[i.first]=false;
        }
     parent[src]=src;
     distance[src]=0;
     visited[src]=true;
     queue<T> q;
     q.push(src);

     while(!q.empty()){
        T node=q.front();
        q.pop();
        for(auto j: adjlist[node]){
            if(distance[j]>(1+distance[node]) && visited[j]==false){
                parent[j]=node;
                distance[j]=1+distance[node];
                visited[j]=true;
                q.push(j);
            }
        }
     }

     cout<<"Distance of each node from the "<<src<<" is\n";
     for(auto i:distance){
        cout<<i.first<<" has distance "<<i.second;
        cout<<endl;
     }
     for(auto i:parent){
        cout<<i.first<<" has parent "<<i.second<<endl;
     }

    }
};

int main(){
  graph<string> g;
  g.addedge("amritsar","delhi");
  g.addedge("amritsar","jaipur");
  g.addedge("jaipur","delhi");
  g.addedge("delhi","agra");
  g.addedge("delhi","bhopal");
  g.addedge("jaipur","mumbai");
  g.addedge("mumbai","bhopal");
  g.addedge("mumbai","bangalore");

  g.print();
  cout<<"\n\nBFS\n";
  g.BFS("amritsar");

  cout<<"\n sssp \n";
  g.sssp("amritsar");
}
*/
/// topological sort()->works on unidirectional
/*
template<typename T>
class graph{
 public :
     map<T,list<T> > adjlist;

     void addEdge(T u,T v,bool bidir=true){
        adjlist[u].push_back(v);
        if(bidir)
            adjlist[v].push_back(u);
     }

     // topological sorting using dfs logic
     void helper(T src, map<T,bool> &visited, list<T> &ordering){
        visited[src]=true;
        for(auto i: adjlist[src]){
            if(visited[i]==false){
                helper(i,visited,ordering);
            }
        }
        ordering.push_front(src);
     }
     void topologicalsort(){

         map<T,bool> visited;
         list<T> ordering;

         for(auto i:adjlist){
            if(visited[i.first]==false){
                helper(i.first,visited,ordering);
            }
         }
       for(auto i: ordering)
        cout<<i<<" ";
     }

     // topological sorting using khan's algorithm

     void khans(){
     map<T,int> indegree;

     for(auto i:adjlist)
        indegree[i.first]=0;
     ///counting the in degree
     for(auto i:adjlist){
        for(auto j:i.second)
            indegree[j]++;
     }
     queue<T> q;
     for(auto i:adjlist){
        if(indegree[i.first]==0)
        {q.push(i.first);}
     }
     while(!q.empty()){
      T node=q.front();
        cout<<node<<" ";
        q.pop();
        for(auto i: adjlist[node]){
            indegree[i]--;
            if(indegree[i]==0)
               {q.push(i);}
        }
      }
     for(auto i:indegree)
        cout<<i.first<<"  "<<i.second<<endl;
     }

};
int main(){
  graph<string> g;
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

  g.topologicalsort();

  cout<<"khans =>"<<endl;
  g.khans();

}
*/
/// DFS(depth first search)
/*
template<typename T>
class graph{
  public:
      map<T,list<T> > adjlist;

      void addedge(T u, T v , bool bidir=true){
        adjlist[u].push_back(v);
        if(bidir)
            adjlist[v].push_back(u);
      }

      // dfs
      void DFShelper(T src, map<T,bool> &visited){
         visited[src]=true;
         cout<<src<<" ";
         for(auto i: adjlist[src]){
            if(visited[i]==false){
                DFShelper(i,visited);
            }
         }
      }
      void DFS( T src){
         map<T,bool> visited;
         DFShelper(src,visited);

      }

};

int main(){
 graph<string> g;
  g.addedge("amritsar","delhi");
  g.addedge("amritsar","jaipur");
  g.addedge("jaipur","delhi");
  g.addedge("delhi","agra");
  g.addedge("delhi","bhopal");
  g.addedge("jaipur","mumbai");
  g.addedge("mumbai","bhopal");
  g.addedge("mumbai","bangalore");

  g.DFS("amritsar");

}
*/
/// connected component
/*
template<typename T>
class graph{
 public:
     map<T , list<T> > adjlist;

     void addedge(T u,T v,bool bidir=true){
       adjlist[u].push_back(v);
       if(bidir)
        adjlist[v].push_back(u);
     }

     // ye connected component dfs se ho jata hai see how,
     void helper(T src, map<T,bool> &visited){
        visited[src]=true;
        for(auto i:adjlist[src]){
            if(visited[i]==false){
                helper(i,visited);
            }
        }
     }
     int  dfs(T src){
       map<T , bool > visited;
       helper(src,visited);
       int connected_components=1;
       for(auto i:adjlist){
        if(visited[i.first]==false){
            connected_components+=1;
            helper(i.first,visited);
        }
       }

     return connected_components;
     }
};

int main(){
 graph<string> g;
 g.addedge("amritsar","jaipur");
 g.addedge("amritsar","delhi");
 g.addedge("delhi","agra");
 g.addedge("jaipur","mumbai");
 g.addedge("delhi","bopal");
 g.addedge("mumbai","bangalore");
 g.addedge("delhi","jaipur");
 g.addedge("bopal","mumbai");
 g.addedge("andaman","nicobar");

  cout<<g.dfs("amritsar")<<endl;

}
*/
/// cycle detection in undirected graph
/*
template <typename T>
class graph{
 public:
     map<T,list<T> > adjlist;

     void addedge(T u,T v, bool bidir=true){
       adjlist[u].push_back(v);
       if(bidir)
        adjlist[v].push_back(u);
     }

     //using bfs logic
     bool check(T src){
      queue<T> q;
      map<T, bool> visited;
      map<T, T> parent;
      for(auto i: adjlist)visited[i.first]=false;
      parent[src]=src;
      visited[src]=true;
      q.push(src);

      while(!q.empty()){
        T node=q.front();
        q.pop();

        for(auto i:adjlist[node]){
            parent[i]=node;
            if(visited[i]==true && i!=parent[node])return true;
            if(i!=parent[node]){
            visited[i]=true;
            q.push(i);}
        }

      }
      return false;
     }

};

int main(){
  graph<int> g;
  g.addedge(0,1);
  g.addedge(0,2);
  g.addedge(1,3);
  g.addedge(2,3);
  g.addedge(3,4);
  g.addedge(5,4);

  if(g.check(0)==true){
    cout<<"cycle is present"<<endl;
  }
  else{
    cout<<"cycle is not present"<<endl;
  }

}

*/
/// cycle detection in undirected graph , using dfs method
/*
template<typename T>
class graph{
public:
    map<T, list<T> > adjlist;

    addedge(T u, T v, bool bidir=true){
      adjlist[u].push_back(v);
      if(bidir)
        adjlist[v].push_back(u);
    }
     void helper(T src, map<T,bool> &currently_in_stack, bool &ans){
       currently_in_stack[src]=true;

       for(auto i:adjlist[src]){
        if(currently_in_stack[i]==true)
        {   cout<<"backtrack node exits between "<< src <<" and "<< i<<endl;
            ans=true;
            return  ;
        }
        else if(ans==false){
          helper(i,currently_in_stack,ans);
        }
       }
       currently_in_stack[src]=false;

     }
     bool check(T src){
       map< T , bool > currrently_in_stack;

       for(auto i : adjlist)
        currrently_in_stack[i.first]=false;
       bool ans=false;
       helper(src,currrently_in_stack,ans);
       return ans;
     }
};

int main(){
 graph<int> g;
 g.addedge(0,1,false);
 g.addedge(0,2,false);
 g.addedge(2,3,false);
 g.addedge(2,4,false);
 g.addedge(3,0,false);
 g.addedge(1,5,false);
 g.addedge(4,5,false);

 if(g.check(0)){
    cout<<"cycle is present "<<endl;
 }
 else{
    cout<<"cyce is not present"<<endl;
 }
 }
*/

///Dijkstra Alogrithm for single source shortest PATH
/*
template<typename T>
class graph{
 public:
     map<T ,list<pair<T,int> > >adjlist;

     void addedge(T u,T v,int w, bool bidir=true){
      adjlist[u].push_back(make_pair(v,w));
      if(bidir)
        adjlist[v].push_back(make_pair(u,w));
     }

     void print(){
     for(auto i: adjlist){
        cout<<i.first<<"=>";
        for(auto j:i.second){
            cout<<j.first<<" "<<j.second<<"|";
        }
        cout<<endl;
     }
     }

     void dijkstra(T src){

     map<T,int> distance;
     map<T,bool> visited;
     for(auto i:adjlist){
        distance[i.first]=INT_MAX;
        visited[i.first]=false;
     }
     distance[src]=0;
     visited[src]=true;
     queue<T> q;
     q.push(src);

     while(!q.empty()){
        T node=q.front();
        q.pop();
        for(auto i: adjlist[node]){
            if(distance[i.first]> distance[node]+i.second){
                distance[i.first]=distance[node]+i.second;
                if(visited[i.first]==false)
                    {q.push(i.first);visited[i.first]=true;}

            }
        }

     }
      cout<<"\n Printing the distance form "<< src <<" to all other nodes "<<endl;
      for(auto i: distance){
        cout<<i.first<<" has "<< i.second<<endl;
      }

     }


};

int main(){

graph<char> g;
g.addedge('a','b',5);
g.addedge('a','e',5);
g.addedge('a','c',5);
g.addedge('e','c',6);
g.addedge('b','d',3);
g.addedge('c','d',4);

g.print();

g.dijkstra('a');


    graph<string > g;
    g.addedge("amritsar","jaipur",4);
    g.addedge("amritsar","delhi",1);
    g.addedge("jaipur","delhi",2);
    g.addedge("delhi","agra",1);
    g.addedge("agra","bhopal",2);
    g.addedge("bopal","mumbai",3);
    g.addedge("jaipur","mumbai",8);
    g.dijkstra("amritsar");



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

    g.dijkstra(0);

}
*/

///BellMann Ford Algorithm: for finding single soruce shortest path , where negative edges are present and to detect the negative weight cycle.
/*
template<typename T>
class Edge{
 public:
     T source;
     T dest;
     int weight;

//     Edge(T s,T d,int w){
//     source=s;
//     dest=d;
//     weight=w;
//     }
};
template<typename T>
class Graph{
public:

    int edges;
    int vertices;
    set<T> vet;
    int i;
    Edge<T> *arr;

    Graph(int e,int vertices){
    this->vertices=vertices;
    i=0;
    edges=e;
    arr=new Edge<T>[e];
    }

    void addEdge(T src,T des,int w){
    arr[i].source=src;
    arr[i].dest=des;
    arr[i].weight=w;
    i++;
    vet.insert(src);
    vet.insert(des);
    }

    void print(){
    for(int j=0;j<edges;j++){
        cout<<arr[j].source<<" "<<arr[j].dest<<" "<<arr[j].weight<<endl;
    }
    cout<<"\nprinting the vertices "<<endl;
    for(auto k: vet){cout<<k<<" ";}
    }


    //bellman ford algorithm
    void BellmanFord(T src){
      map<T,int> distance;

      for(auto k:vet)
        distance[k]=INT_MAX;

      distance[src]=0;

      for(int k=0;k<vertices-1;k++){
        for(int l=0;l<edges;l++){
            if(distance[arr[l].dest] > distance[arr[l].source] + arr[l].weight)
                distance[arr[l].dest] = distance[arr[l].source] + arr[l].weight;
        }
      }

      cout<<"printing the shortest path "<<endl;
      for(auto k:distance){
        cout<<src<<" "<<k.first<<" => "<<k.second<<endl;
      }
    }
};

int main(){
  int e,v;
  cout<<"enter the number of edges in the graph"<<endl;
  cin>>e;
  cout<<"enter the number of vertices "<<endl;
  cin>>v;

  Graph<int> g(e,v);
  int src,dest,w;
  for(int i=0;i<e;i++){
    cout<<"enter source :";cin>>src;
    cout<<"enter destination :";cin>>dest;
    cout<<"entre the weight:";cin>>w;
    g.addEdge(src,dest,w);
  }
  g.print();
  int s;
  cout<<"\n enter the source from where you want to start :";cin>>s;
  g.BellmanFord(s);

}
*/
/// Disjoint set method: to detect the cycle in undirected graph ( 2nd methid to detect cycle in undirected graph)
/*
template<typename t>
class edge{
public:

    t source;
    t dest;
    int weight;

};

template<typename t>
class graph{
public:

  int i;
  int vertex;
  int edges;
  edge<t> *arr;
  set<t> vert;

  graph(int v,int e){
  i=0;
  vertex=v;
  edges=e;
  arr=new edge<t>[e];
  }

  void addedge(t s,t d,int w){
  arr[i].source=s;
  arr[i].dest=d;
  arr[i].weight=w;
  i++;
  vert.insert(s);
  vert.insert(d);
  }

  void print(){
  for(int j=0;j<edges;j++)
    cout<<arr[j].source<<" "<<arr[j].dest<<" => "<<arr[j].weight<<endl;
  for(auto k:vert)
    cout<<k<<" ";
  }

  t findparent(map<t,t> &parent,t node){
  if(parent[node]<0)return node;
  else return findparent(parent,parent[node]);
  }

  bool check(map<t,t> &parent, t s,t d){
  t a=findparent(parent,s);
  t b=findparent(parent,d);
  //if(a==b) both have same parents mtlb yes cycle exits;
  if(a==b)return true;
  //else update the parent;
  else{
    if(parent[a]==parent[b]){
        parent[a]+=parent[b];
        parent[b]=a;
    }
    else if(parent[a]>parent[b]){
        parent[a]+=parent[b];
        parent[b]=a;
    }
    else{
        parent[b]+=parent[a];
        parent[a]=b;
    }
    return false;
  }

  }
  bool disjoint()// for finding the cycle in undirected graph
  {
      map<t,t> parent;
      for(auto k:vert){
        parent[k]=-1;
      }

      for(int k=0;k<edges;k++){
        if(check(parent,arr[k].source,arr[k].dest)==true)
        {return true;}
      }
      return false;
  }
};

int main(){

    int e,v;
cout<<"enter the number of edges :";cin>>e;
cout<<"enter the numer of vertex:";cin>>v;

graph<int> g(v,e);
int src,des,w;
for(int i=0;i<e;i++){
    cout<<"enter the source :";cin>>src;
    cout<<"entre the dest :";cin>>des;
    cout<<"enter the weight :"; cin>>w;
    g.addedge(src,des,w);
}

g.print();
if(g.disjoint())cout<<"yes cycle exists"<<endl;
else cout<<"No cycle "<<endl;
}
*/
///Minimum Spanning Tree
///1.Kruskals Algorithm
template<typename t>
class edge{
public:
    t src;
    t des;
    int weight;
};

template<typename t>
class graph{
public:
    int i;
    int edges,vertices;
    edge<t> *arr;
    set<t> vert;

    graph(int e,int v){
    edges=e;
    vertices=v;
    arr=new edge<t>[e];
    i=0;
    }
    void addedge(t s,t d, int w){
    arr[i].src=s;
    arr[i].des=d;
    arr[i].weight=w;
    vert.insert(s);
    vert.insert(d);
    i++;
    }
    t findparent(t node,map<t,t> &parent){
    if(parent[node]<0)return node;
    else return findparent(parent[node],parent);
    }
    bool check(t src,t des, int wt ,map<t,t> &parent){
      int a=findparent(src,parent);
      int b=findparent(des,parent);

      if(a==b)return false;//means cycle is parent , don't include that edge
      else{
        if(parent[a]>=parent[b]){
            parent[a]+=parent[b];
            parent[b]=a;
        }
        else if(parent[a]<parent[b]){
            parent[b]+=parent[a];
            parent[a]=b;
        }
        return true;
      }

    }
    int kruskals(){
    map<t,t> parent;
    for(auto j:vert)parent[j]=-1;

    //making map of edge lits: which is sorted on the basis of weights
    multimap<int,pair<t,t> > edgelist;
    for(int j=0;j<edges;j++){
        edgelist.insert(make_pair(arr[j].weight,make_pair(arr[j].src,arr[j].des)));
    }

    //printing the edgelist
    for(auto i:edgelist){
        cout<<i.second.first<<" "<<i.second.second<<" => "<<i.first<<endl;
    }
    int cost=0,edges_included=0;
    for(auto i:edgelist){
        if(check(i.second.first,i.second.second,i.first,parent))// check(src,des,wt,parent)
        {   cost+=i.first;
            edges_included++;
        }
        if(edges_included==vertices-1)return cost;
    }

    }

};
int main(){
int v,e;
cout<<"enter number of vertices :";cin>>v;
cout<<"enter number of edges :";cin>>e;

graph<int> g(e,v);
int src,des,w;
for(int i=0;i<e;i++){
    cout<<"enter the source :"; cin>>src;
    cout<<"enter the  destination :"; cin>>des;
    cout<<"enter the weight :"; cin>>w;
    g.addedge(src,des,w);
}

cout<<"Cost of Minimum Spanning tree => "<<g.kruskals();

}
