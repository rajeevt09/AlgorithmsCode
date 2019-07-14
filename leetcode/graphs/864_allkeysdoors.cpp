#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {

   /*class cell{
         private:
           int x = 0;
           int y = 0;
           int m = 0;
           int n = 0;
         public:
           cell(int _x,int _y,int _m,int _n):x(_x),y(_y),m(_m),n(_n){};
           bool operator ==(const cell &rhs)
           {
                
           }
           getId(){return x*m + y;};
           getX(){return x;};
           getY(){return y;};
           
   };*/

private:
    vector<vector<bool>> visited;
    unordered_map<char,int> keys;
    int m; //max num rows
    int n; //max num columns
    vector<vector<char>> grid;
    int numKeys = 0;
public:
    void printGrid()
    {
        cout << "Displaying Grid " << endl;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << grid[i][j] << " " ;
            }
            cout << endl;
        }
        cout << "Displaying Visited " << endl;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << visited[i][j] << " " ;
            }
            cout << endl;
        }

    }
    bool isOpen(char c)
    {
        if((c =='.') || (c == '@')) return true;
        if((c >= 'a') && (c <= 'z'))
        {
           return true;
        }
        if((c >= 'A') && (c <= 'Z'))
        {
            if(keys.find(tolower(c)) != keys.end()) // key is already collected
            {
               return true;
            }
            return false;
        } 
        return false;
    }
    bool isKey(char c)
    {
        if((c >= 'a') && (c <= 'z'))
        {
           return true;
        }
       return false;
    }
    //get all neigbouring cells from i,j that can be visited
    vector<pair<int,int>> getNeighbours(int i,int j)
    {
        vector<pair<int,int>> neighbours;
        //left
        if(j > 0) 
        { 
           if(isOpen(grid[i][j-1]))
               neighbours.push_back(make_pair(i,j-1));
        }
        //right
        if(j < n-1) 
        { 
           if(isOpen(grid[i][j+1]))
               neighbours.push_back(make_pair(i,j+1));
        }
 
        //up
        if(i > 0) 
        { 
           if(isOpen(grid[i-1][j]))
               neighbours.push_back(make_pair(i-1,j));
        }
 
        //down
        if(i < m-1) 
        { 
           if(isOpen(grid[i+1][j]))
               neighbours.push_back(make_pair(i+1,j));
        }
        //cout << "$ " << neighbours.size() << endl;     
        return neighbours;  
    }
    //clear only vitied open cells , no keys/doors to be cleared
    void clearVisited()
    {

    }

    /*int shortestPathAllKeys(vector<string>& grid) {
        queue<pair<int,int>> q;
        pair<int,int> start;
        //get count of numKeys;

        //enqueue start vertex
        q.push(start);

        //maintain distance of BFS depth
        int depth = 0;

        // do bfs from start till all keys are collected
       while(!q.empty() && keys.size() != numKeys)
       {
           int size = q.size();
           pair<int,int> v = q.front();
           q.pop();
           //process next level 
           while(size)
           {
               for(pair<int,int> nbr:getNeighbours(v.first,v.second))
               {
                char c = grid[nbr.first][nbr.second];
                if(isKey(c))
                {
                    if(keys.find(c) == keys.end())
                    {
                       keys.insert(make_pair(c,true));
                    }
                    if(keys.size() == numKeys) break;
                }
                //enque neighbours to queue if not visited
                if(!visited[nbr.first][nbr.second])
                {
                    q.push(nbr);
                    visited[nbr.first][nbr.second] = true;
                }
             
               }
               size--;
           } 
           //we are moving to next level now
           depth++;
       }
       return -1;      
    }*/

int shortestPathAllKeys(vector<string>& sgrid) {
        //parse and populate grid;
        grid.resize(sgrid.size());
        visited.resize(sgrid.size());
        int i =0,j=0;
        int srow,scol; //start row and col
        for(string &row:sgrid)
        {
            j = 0;
            grid[i].resize(row.length());
            visited[i].resize(row.length());   
            for(char c:row)
            {
               grid[i][j] = c;
               if(isKey(c)) numKeys++;
               if(c == '@') { srow = i;scol = j;}
               j++; 
            }:q

            i++;
        }
        m = i;
        n = j;
        cout << "Expecting numKeys : " << numKeys << " in grid " << m << " x " << n;
        cout << endl << "start cell is " << srow << " , " << scol << endl;
        printGrid();
        visited[srow][scol] = true;
        return dfsShortestPath(srow,scol);
       
    }
int dfsShortestPath(int x,int y)                   
{
    int optDist = INT_MAX;
    cout << "(" << x << "," << y << ") --> "; 
    //if all keys are collected  return
    if(keys.size() == numKeys) return 0;
    //for every neighbour do dfs
    for(pair<int,int> &nbr : getNeighbours(x,y))
    {
       char c = grid[nbr.first][nbr.second];
       //visit neighbours  if not visited
       if(!visited[nbr.first][nbr.second])
       {
           bool isKeyInserted = false;
           if(isKey(c))
           {
              if(keys.find(c) == keys.end())
              {
                  isKeyInserted = true;
                  keys.insert(make_pair(c,true));
              }
              if(keys.size() == numKeys) 
              {
                  //we have found all keys . So this is the target cell for dist purpose
                  return 1;
              }
           }
           cout << "Now I am visiting " << nbr.first << " , " << nbr.second << " keys : " << keys.size() <<  endl;
           visited[nbr.first][nbr.second] = true;
           int dist = dfsShortestPath(nbr.first,nbr.second);
           //clear state (//backtrack)
           visited[nbr.first][nbr.second] = false;
           if(isKeyInserted) keys.erase(c);          
           optDist = std::min(dist,optDist);
       }
     }
     if(optDist < INT_MAX)
     {
         //add distacnce of 1 to optimum choice neighbour 
         optDist += 1;
     }
     if(optDist == INT_MAX) cout << endl;
     return optDist;
}
};


int main()
{
 vector<string> grid = {"@.a.#",
                        "###.#",
                        "b.A.B"};
 Solution solve;
 int optDist = solve.shortestPathAllKeys(grid);
 cout << endl << "Optimum Distance to get all keys is " << optDist;
 return 0;  
}
