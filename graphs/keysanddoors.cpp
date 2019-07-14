#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

class graph
{

class nodestate
{
public:
    nodestate(int _x,int _y,int _state):x(_x),y(_y),state(_state)
    {
    }
    nodestate(const nodestate &ns):x(ns.x),y(ns.y),state(ns.state)
    {
     
    } 
    void addState(char key)
    {
       //add key to state
       if(isKey(key))
       {   
          state |= 1 << (key - 'a');
       }
    }
    int getState(){return state;};
    int getX(){return x;};
    int getY(){return y;};
    bool valid(char c)
    {
        //if it is a door make sure we have the key
        if(c == '#') return false;
        if(isDoor(c))
        {
           char key = toKey(c);
    //       cout <<" DOOR :" << c << "NEEDS KEY " << key << endl;
           if((state & (1 << (key - 'a'))) == 0x0) return false;
        }
        return true;
    }
    void print()
    {
       cout << " ( " << x << "," << y << "," << state << " ) ";
    }
    nodestate& operator =(const nodestate& ns)
    {
       this->x = ns.x;
       this->y = ns.y;
       this->state = ns.state;
       return *this;
    }
    bool operator !=(const nodestate& ns)
    {
       return ((this->x != ns.x) ||
               (this->y != ns.y) ||
               (this->state != ns.state));
    }

private:
    int x = 0;
    int y = 0;
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
    graph(vector<string> _grid)
    {
      for(string &s:_grid)
      {
        cout << s << endl;
        cols = 0;
        for(char c:s)
        {
          if(c == '@') 
          {
            start.first = rows;
            start.second = cols;
          }
          else if(c == '+')
          {
            end.first = rows;
            end.second = cols;
          }
          cols++;    
        }  
        rows++; 
      }
      visited.resize(rows+1,vector<unordered_map<int,nodestate>>(cols+1));
      cout << "begin :" << start.first << "," << start.second << endl; 
      cout << "end :" << end.first << "," << end.second << endl;
      cout << "m " << rows << "n " << cols << endl;
      grid= _grid;
    }

    vector<nodestate> getneighbours(nodestate vertex)
    {
        vector<nodestate> list;
        int row = vertex.getX();
        int col = vertex.getY();
       
        //go up
        {
        nodestate ns(row-1,col,vertex.getState());
        list.push_back(ns);
//      ns.print();
        }
        //go down
        {
        nodestate ns(row+1,col,vertex.getState());
        list.push_back(ns);
//      ns.print();

        }
        //go left
        {
        nodestate ns(row,col-1,vertex.getState());
        list.push_back(ns);
//      ns.print();
        }
        //go right
        {
        nodestate ns(row,col+1,vertex.getState());
        list.push_back(ns);
//        ns.print();
        }
        return list;
       
    }

    bool isValid(nodestate &ns)
    {
       //cout << "isValid?" << ns.getX() << "," << ns.getY() << "  " ; 
       //check if cell is valid first
       if((ns.getX() >= 0 && ns.getX() < rows) && 
       (ns.getY() >=0 && ns.getY() < cols))
       {
         char c =  grid[ns.getX()][ns.getY()];
         ns.addState(c);
         if(!ns.valid(c))
         {
        //    cout << "ERRLOCKED ";
            return false;
         }
         if(isVisited(ns.getX(),ns.getY(),ns.getState()))
         {
          // cout << "ERRVISITED ";
           return false;
         }
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
        queue<nodestate> q;
        nodestate begin(start.first,start.second,0);
        nodestate virtualbegin(-1,-1,-1);
        setVisited(begin.getX(),begin.getY(),0,virtualbegin);
        q.push(begin);
        while(!q.empty() && !bDone)
        {
            int size = q.size();
//            cout << "Level : " << steps << endl;
            while(size)
            {
                 nodestate vertex = q.front();
                 q.pop();
                 //cout << " ( " << vertex.getX() << "," << vertex.getY() << " ) :" << endl ;
                 for(nodestate &neighbour:getneighbours(vertex))
                 {
                      if((neighbour.getX() == end.first) && (neighbour.getY() == end.second))
                      {
                          setVisited(neighbour.getX(),neighbour.getY(),neighbour.getState(),vertex);
                          //cout << "reached end " << end.first << "," << end.second << endl;
                          //reached end
                          bDone = true;
                          nodestate cur(neighbour);
                          //cout << "displaying route : " << endl;
                          while(cur != virtualbegin)
                          {
                             vector<int> pair;
                             pair.push_back(cur.getX());
                             pair.push_back(cur.getY());
                             path.push_back(pair);
                             auto it = visited[cur.getX()][cur.getY()].find(cur.getState()); 
                             cur =  it->second;                    
                          };
                          vector<vector<int>> rpath;
                          std::reverse_copy(path.begin(),path.end(),back_inserter(rpath));
                          return rpath;
                      }
                      if(!isValid(neighbour)) continue;
                      //neighbour.print();
                      //cout << endl;
      
                      // its an unvisited vertex and accessible based on keys collected for state
                      q.push(neighbour);
                      setVisited(neighbour.getX(),neighbour.getY(),neighbour.getState(),vertex);
                      
                 }
                 size--;
            }
            steps++;
        }
        return path;
    }
private:
    void setVisited(int x,int y,int state,nodestate &parentnode)
    {
       visited[x][y].insert(make_pair(state,parentnode));
    }
    bool isVisited(int x,int y,int state)
    {
       if(visited[x][y].find(state) != visited[x][y].end())
       {
          return true;
       }
       return false;
    }
 
    vector<vector<unordered_map<int,nodestate>>> visited;
    pair<int,int> start;
    pair<int,int> end;
    vector<string> grid;
    int rows = 0;
    int cols = 0;
};

vector<vector<int>> find_shortest_path(vector<string> grid)
{
    graph g(grid);
    return g.shortestPath();      
}

int main()
{  
   cout << "<Topic> Homework <part -1/2> <Title> :" << endl;
   vector<string> grid ={"...B",".b#.","@#+."};
    cout << grid.size() << endl;
   vector<vector<int>> path  = find_shortest_path(grid);
   cout << "displaying path" << endl;
   for(auto pair:path)
   {
      cout << "(" << pair[0] << "," << pair[1] << ")" << "->" ;
   }
   return 0;
}
