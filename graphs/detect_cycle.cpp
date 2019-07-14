#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        return hasCycle(numCourses,prerequisites);
    }
    
     bool dfs(int vertex,vector<vector<int>> &adj,vector<int> &visited)
    {
        visited[vertex] = 1;
        vector<int> nlist = adj[vertex];
        for(auto neighbour:nlist)
        {
            if(!visited[neighbour])
            {
                if(dfs(neighbour,adj,visited)) return true;
            }
            else
            {
                return true;
            }
        }
        visited[vertex] = 0;
        return false;
    }
    
    bool hasCycle(int numCourses,vector<pair<int, int>>& prerequisites)
    {
        vector<int> visited(numCourses,0);
        vector<vector<int>> adj(numCourses,vector<int>());
        for(auto p:prerequisites)
        {
            adj[p.first].push_back(p.second);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,adj,visited)) return true;
            }
        }
        return false;
    }
    
   
};

int main()
{
   return 0;
}

