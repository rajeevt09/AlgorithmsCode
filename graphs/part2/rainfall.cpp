#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

bool hasNeighbour(vector<vector<int>> &elevation_map,int i,int j,int n,int &neighbour);
void dfs(int vertex,unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &visited,int &count);

int toVertex(int i,int j,int n)
{
    return i*n + j;
}
/*
 * Complete the calculate_sizes_of_basins function below.
 */
vector<int> calculate_sizes_of_basins(vector<vector<int>> elevation_map) {
    /*
     * Write your code here.
     */
    //get # of vertices in graphs
    int n = elevation_map.size() ;
    unordered_map<int,vector<int>> adj;
    //create a graph from input data
    int vertex = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            vertex = toVertex(i,j,n);
            int neighbour;
            if(hasNeighbour(elevation_map,i,j,n,neighbour))
            {
                //create an edge between vertex and neighbour
                adj[vertex].push_back(neighbour);
                adj[neighbour].push_back(vertex);
            }
        }
    }
    
    vector<int> results;
    unordered_map<int,bool> visited;
    //count strongly connected components
    int scc = 0;
    for(int i=0;i<n*n;i++)
    {
        if(visited.find(i) == visited.end())
        {
           int count = 1;
           dfs(i,adj,visited,count);
           results.push_back(count);
           scc++;
        }
    }
    std::sort(results.begin(),results.end(),std::greater<int>());
    return results;
}



bool hasNeighbour(vector<vector<int>> &elevation_map,int i,int j,int n,int &neighbour)
{
    vector<pair<int,int>> neighbours;
    int curVal = elevation_map[i][j];
    if(i > 0) neighbours.push_back(make_pair(elevation_map[i-1][j],toVertex(i-1,j,n)));
    if(i < n-1) neighbours.push_back(make_pair(elevation_map[i+1][j],toVertex(i+1,j,n)));
    if(j > 0) neighbours.push_back(make_pair(elevation_map[i][j-1],toVertex(i,j-1,n)));
    if(j < n-1) neighbours.push_back(make_pair(elevation_map[i][j+1],toVertex(i,j+1,n)));
    auto minNeighbour = std::min_element(begin(neighbours),end(neighbours));
    if(curVal > minNeighbour->first) 
    {
        neighbour = minNeighbour->second;
        return true;
    }
    return false;
}

void dfs(int vertex,unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &visited,int &count)
{
     visited[vertex] = true;
     // visit all edges adjacent to vertex
     for(int neighbour:adj[vertex])
     {
         if(visited.find(neighbour) == visited.end())
         {
             count++;
             dfs(neighbour,adj,visited,count);
         }
     }
}

int main()
{
    vector<vector<int>> land= {{1,0,2,5,8},{2,3,4,7,9},{3,5,7,8,9},{1,2,5,4,3},{3,3,5,2,1}};
    vector<int> res = calculate_sizes_of_basins(land);
    for (int i:res)
    cout << i << ",";   
}


