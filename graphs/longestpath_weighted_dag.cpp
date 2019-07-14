#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class graph
{

public:
    graph(int n):m_n(0)
    {
    }
    void addEdge(int from,int to,int weight)
    {
         if(map.find(from) == map.end())
         {
           map.insert(make_pair(from,vector<pair<int,int>>()));
           m_n++;
         }
         map[from].push_back(make_pair(to,weight));
    }

    vector<int> topOrder()
    {
       for(auto vertex:map)
       {
         if(visited.find(vertex.first) == visited.end())
         dfs(vertex.first);    
       }
      std::reverse(order.begin(),order.end());
      return order;
    }

   void dfs(int vertex)
   {
      if(visited.find(vertex) != visited.end()) return;
      cout << "vsiting" << " " << vertex << endl;
      visited.insert(vertex);
      for(auto neighbour:map[vertex])
      {
         if(visited.find(neighbour.first) == visited.end())
         {
            dfs(neighbour.first);  
         }
      }
      order.push_back(vertex);
   }
   vector<pair<int,int>> getNeighbours(int vertex)
   {
      vector<pair<int,int>> list;
      for(pair<int,int> p: map[vertex])
      {
        list.push_back(p);
      }
      return list;
   }
   int V(){return m_n;};
    
private:
    unordered_map<int,vector<pair<int,int>>> map;
    unordered_set<int> visited;
    int m_n;
    vector<int> order;
};

//return the longest path from_node to to_node
vector<int> find_longest_path(graph &g,int from_node,int to_node)
{
     vector<int> order = g.topOrder();
     unordered_map<int,int> maxDist;
     unordered_map<int,int> pathTo;
     //visit nodes in top Order
     for(int vertex:order)
     {
        vector<pair<int,int>> neighbours = g.getNeighbours(vertex);
        for(pair<int,int> neighbour:neighbours)
        {
            if(maxDist.find(neighbour.first) == maxDist.end()) maxDist[neighbour.first] = INT_MIN;
            //check if longer path to neighbour exists and update
            if(maxDist[neighbour.first] < maxDist[vertex] + neighbour.second)
            {
               maxDist[neighbour.first] = maxDist[vertex] + neighbour.second;
               pathTo[neighbour.first] = vertex;          
            }
        }
     }

     //walk back path from to storing path on the way
     vector<int> longestPath;
     int v = to_node;
     while(v != from_node)
     {
       longestPath.push_back(v);
       v = pathTo[v];
     }
     longestPath.push_back(v);
     std:reverse(begin(longestPath),end(longestPath));
     return longestPath;
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
    graph myGraph(dag_nodes);
    for(int i=0;i<dag_nodes;i++)
    {   
        myGraph.addEdge(dag_from[i],dag_to[i],dag_weight[i]);
    }
//    myGraph.print();
        
    vector<int> path;
    path = find_longest_path(myGraph,from_node,to_node);
    cout << "Display Longest Path" << endl;
    for(int i:path)
    {  
       cout << i << " -> " ;
    }



}
