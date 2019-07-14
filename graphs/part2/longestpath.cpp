#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class edge
{
public:
   edge(int from,int to,int weight):m_from(from),m_to(to),m_weight(weight){}
   int other(int i){
           if(i == m_from) return m_to;
           else return m_from;
    }
   int weight()
   {
        return m_weight;
   }  
private:
    int m_from;
    int m_to;
    int m_weight;
};

class graph
{
public:
    void addEdge(int from,int to,int weight)
    {
        vector<edge> empty;
        m_adj[to] = empty;
        m_adj[from].push_back(edge(from,to,weight));   
        m_distTo[from] = m_distTo[to] = INT_MIN;
    }

    void print()
    {
        cout << "Displaying Graph : ";
        for(auto it:m_adj)
        {
             cout << endl;
             int vertex = it.first;
             cout << vertex << " : ";
             for(edge e : m_adj[vertex])
             {
                  cout << e.other(vertex) << "," << e.weight() << ";" ;
             }
        }
    }

    vector<int> topsort()
    {
         vector<int> result;
         stack<int> order;
         for(auto &it:m_adj)
         {
              int vertex = it.first;
              if(m_visited.find(vertex) == m_visited.end())
              {
                  //non visited vertex
                  dfs(vertex,order);
              }         
         }
         while(!order.empty())
         {
             int v = order.top();
             result.push_back(v);
             order.pop();
         }
         return result; 
    }

    void dfs(int vertex,stack<int> &order)
    {
        m_visited[vertex] = true;
        //exhaust  all edges of  vertex 
        for(edge &e:m_adj[vertex])
        {
           int other = e.other(vertex);
           if(m_visited.find(other) == m_visited.end())
              dfs(other,order);
        }
        order.push(vertex);   
    }

    vector<int> getLongestPath(int source , int dest)
    {
        vector<int> path;
        vector<int> order;
        order = topsort();
        for(int v:order)
        {
             //iterate all edges for v
             for(edge &e:m_adj[v])
             {
                 int other = e.other(v);
                 if(m_distTo[other] < m_distTo[v] + e.weight())
                 {
                      m_distTo[other] = m_distTo[v] + e.weight();
                      m_edgeTo[other] = v;
                 }
             }      
        }
        int v = dest;
        do
        {
            path.push_back(v);
            v = m_edgeTo[v];
        }while(v != source);
        path.push_back(source);
        reverse(path.begin(),path.end());
        return path;
     
    }

    int getDist(int v)
    {
        return m_distTo[v];   
    }
private:
    unordered_map<int,vector<edge>> m_adj;
    unordered_map<int,int> m_distTo;
    unordered_map<int,int> m_edgeTo;
    unordered_map<int,bool> m_visited;
    
};

vector <int> find_longest_path(graph &gg, int from_node, int to_node) {
     vector<int> path;
     path = gg.getLongestPath(from_node,to_node);
     return path;
}

int main()
{
    int dag_nodes = 4;
    vector<int> dag_from = {1,1,1,3};
    vector<int> dag_to = {2,3,4,4};
    vector<int> dag_weight = {2,2,4,3};
    int from_node = 1;
    int to_node = 4;

    //creating graph
    graph myGraph;
    for(int i=0;i<dag_nodes;i++)
    {
        myGraph.addEdge(dag_from[i],dag_to[i],dag_weight[i]);
    }
    myGraph.print();
        
    vector<int> path;
    path = find_longest_path(myGraph,from_node,to_node);
    cout << "Display Longest Path" << endl;
    for(int i:path)
    {
       cout << i << " -> " ;
    }



}
