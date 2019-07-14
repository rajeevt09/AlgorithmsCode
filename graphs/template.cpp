#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;



class graph
{

class nodestate
{
public:
    nodestate(int _x,int _y,int _state,char c):x(_x),y(_y),state(_state)
    {
    }
    addState(char key)
    {
       //add key to state
       if(isKey(c)
       {   
          state |= 1 << (c - 'a');
       }
    }
    getState(){return state;};
    bool valid(char c)
    {
        //make sure if it is already visited
        if(isVisited(x,y,state)) return false;
        //if it is a door make sure we have the key
        if(isDoor(c))
        {
           char key = toKey(c);
           if((state & (1 << key)) == 0x0) return false;
        }
        return true;
    }
private:
    int x;
    int y;
    int state = 0;
    
    bool isKey(char c)
    {
       return (c >= 'a' && c <= 'z');
    }
    bool isDoor(char c)
    {
       return (c >= 'A' && c <= 'Z');
    }
    char toKey(char c)
    {
      //get key needed for  a door 
      return c - 'A' +'a';
    }

};
public:
    graph(vector<string> &grid)
    {
      int row =0;
      int col =0;
      for(string &s:grid)
      {
        col =0;
        for(char c:s)
        {
          if(c == '@') 
          {
            start.first = row;
            start.second = col;
          }
          else if(c == '+')
          {
            end.first = row;
            end.second = col;
          }
          cols++;    
        }  
        rows++; 
      }
      visited.resize(rows+1,vector<int>(cols+1,0));
    }

    vector<nodestate> getneighbours(nodestate vertex)
    {
        vector<nodestate> list;
        int row = vertex.first;
        int col = vertex.second;
        
        //go up
        nodestate ns(row--,col,vertex.getState());
        list.push_back(ns);
        
        //go down
        nodestate ns(row++,col,vertex.getState());
        list.push_back(ns);

        //go left
        nodestate ns(row,col--,vertex.getState());
        list.push_back(ns);
        
        //go right
        nodestate ns(row,col++,vertex.getState());
        list.push_back(ns);
 
        return list;
       
    }

    bool isValid(nodestate ns)
    {
       //check if cell is valid first
       if(ns.first >= 0 && ns.first <= rows) &&
         (ns.second >=0 && ns.second <= cols)
       {
         return true;
       }
       return false;
    }

   
    vector<vector<int>> shortestPath()
    {
        //do bfs from start to end vertex 
        bool bDone = false;
        int steps = 0;
        vector<vector<int>> path;
        vector<vector<cell>> edgeTo;
        queue<nodestate> q;
        nodestate start(start.first,start.second);
        setVisited(start.first,start.second,start.getState());
        q.push(start);
        while(!q.empty && !bDone)
        {
            int size = q.size();
            while(size)
            {
                 nodestate vertex = q.front();
                 q.pop();
                 for(auto neighbour:getneighbours(vertex))
                 {
                      if((neighbour.first == end.first) && (neighbour.second == end.state))
                      {
                          //reached end
                          bDone = true;
                          break;
                      }
                      if(!isValid(p)) continue;
                      p.setState(grid[p.first][p.second]);
                      //now check if cell is unlocked and not visited
                      if(!p.valid()) continue;
                      // its an unvisited vertex and accessible based on keys collected for state
                      q.push(p);
                      setVisited(neighbour.first,neighbour.second,neighbour.getState());
                 }
                 size--;
            }
            steps++;
        }

        //reconstruct path 
        return path;
    }
private:
    void setVisited(int x,int y,int state)
    {
       visited[x][y].add(state);
    }
    bool isVisited(int x,int y,int state)
    {
       if(visited[x][y].find(state) != visited.end())
       {
          return true;
       }
       return false;
    }
 
    vector<vector<unordered_set<int>> visited;
    pair<int,int> start;
    pair<int,int> end;
    int rows = 0;
    int cols = 0;
}

vector<vector<int>> find_shortest_path(vector<string> grid)
{
    graph g(grid);
       
}

int main()
{  
   cout << "<Topic> Homework <part -1/2> <Title> :" << endl;
   return 0;
}
