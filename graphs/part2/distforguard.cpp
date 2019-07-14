#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class cell
{
public:
   cell(int x,int y):m_x(x),m_y(y){}
   ~cell(){};
   int getX(){return m_x;};
   int getY(){return m_y;};
private:
   int m_x;
   int m_y;
};


bool isOpen(char c)
{
    if(c == 'O' || c == 'G') return true;
    return false;
}

vector<cell> getNeighbours(vector<vector<char>> &grid,int i,int j)
{
   int m = grid.size();
   int n = grid[0].size();
   vector<cell> neighbours;
   if(!isOpen(grid[i][j])) return neighbours;
   if((i>0) && isOpen(grid[i-1][j])) neighbours.push_back(cell(i-1,j)); 
   if((i<m-1) && isOpen(grid[i+1][j])) neighbours.push_back(cell(i+1,j)); 
   if((j>0) && isOpen(grid[i][j-1])) neighbours.push_back(cell(i,j-1)); 
   if((j<n-1) && isOpen(grid[i][j+1])) neighbours.push_back(cell(i,j+1));
   return neighbours; 
}

/*
 * Complete the find_shortest_distance_from_a_guard function below.
 */
vector<vector<int>> find_shortest_distance_from_a_guard(vector<vector<char>> &grid) {
    /*
     * Write your code here.
     */
     vector<vector<int>> results;
     vector<vector<int>> visited;
     int m = grid.size();
     if(m == 0) return results;
     visited.resize(m);  
     results.resize(m);
     int n = grid[0].size();
     for(int i =0;i<n;i++)
     {
        visited[i].resize(n,0);
        results[i].resize(n,0);
     }

     queue<cell> q;
     for(int i=0;i<m;i++)
     {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j] == 'G')
            {
                q.push(cell(i,j));
                visited[i][j] = true;
            }
            if(!isOpen(grid[i][j]))
            {
                results[i][j] = -1;
            }
        }
     }
    
    //Do BFS From Start Vertex to End Vertex and return the shortest moves
    int dist = 0;
    while(!q.empty())
    {
        cell vertex = q.front();
        q.pop(); 
        visited[vertex.getX()][vertex.getY()] = true;
        // enqueue all neighbours of vertex into q
        for(cell neighbour:getNeighbours(grid,vertex.getX(),vertex.getY()))
        {
           int x = neighbour.getX();
           int y = neighbour.getY();
           if(!visited[x][y])
           {
               q.push(cell(x,y));
               results[x][y] = results[vertex.getX()][vertex.getY()] + 1;          
           }
           visited[neighbour.getX()][neighbour.getY()] = true;
           
        }
        
    }
   return results;
}

int main()
{
   vector<vector<char>> grid{
        {'O', 'O', 'O', 'O', 'G'},
        {'O', 'W', 'W', 'O', 'O'},
        {'O', 'O', 'O', 'W', 'O'},
        {'G', 'W', 'W', 'W', 'O'},
        {'O', 'O', 'O', 'O', 'G'}
    };
   vector<vector<int>> results = find_shortest_distance_from_a_guard(grid);
   for(vector<int> res:results)
   {
       cout << endl;
       for(int i: res)
       {
          cout << "'" << i << "'" << ",  "; 
       }
   }
}
