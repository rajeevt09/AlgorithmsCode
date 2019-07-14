#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;
int bfs(unordered_map<int,int> &map,int sv,int ev);
// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
     int shortestDist = 0;
     unordered_map<int,int> map;
     cout << "Ladders:" << endl;
     for(auto &it:ladders)
     {
         map.insert(make_pair(it[0],it[1]));
         cout << it[0] << " : " << it[1] << endl;
     }
     cout << "Snakes:" << endl;
     for(auto &it:snakes)
     {
         map.insert(make_pair(it[0],it[1]));
         cout << it[0] << " : " << it[1]<< endl;
     }
     shortestDist = bfs(map,1,36);
     return shortestDist;
}


int bfs(unordered_map<int,int> &map,int sv,int ev)
{
    //Do BFS From Start Vertex to End Vertex and return the shortest moves
    queue<int> q;
    unordered_map<int,bool> visited;
    unordered_map<int,int> edgeTo;
    q.push(sv);
    visited[sv] = true;
    int dist = 0;
    bool found = false;
    while(!q.empty() && !found)
    {
        int vertex = q.front();
        q.pop(); 
        visited[vertex] = true;
        // enqueue all neighbours of vertex into q
        for(int i=1;i<=6;i++)
        {
           int neighbour = vertex + i;
           //if visiting the neighbour has snake or ladder update the new neighbour
           if(map.find(neighbour) != map.end())
           {
                neighbour = map[neighbour];
           }
           if(neighbour == ev)
           {
               edgeTo[neighbour] = vertex;
               //reached destination
               found = true;
               break;
           }
           if(visited.find(neighbour) == visited.end())
           {
               edgeTo[neighbour] = vertex;
               q.push(neighbour);
           }
           visited[neighbour] = true;
           
        }
        
    }
    if(found) return -1; 
    if (found)
    {
       int p = ev;
       while( p != sv)
       {
          cout << p << "->";
          p = edgeTo[p];
          dist++;   
       }
   }
   return dist;
}

int main()
{

     cout << "Snakes and Ladders" << endl;
     vector<vector<int>> ladders = {{2,15},{5,7},{9,27},{25,35}};
     vector<vector<int>> snakes = {{17,4},{20,6},{24,16},{32,30},{34,12}};
     int numSteps = quickestWayUp(ladders,snakes);
     cout << "Dist to reach dest : " << numSteps << endl;
}
