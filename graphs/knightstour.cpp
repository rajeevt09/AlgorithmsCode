#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

vector<pair<int,int>> getNeighbours(pair<int,int> &vertex)
{
   vector<pair<int,int>> neighbours;
   int row = vertex.first;
   int col = vertex.second;
   //up
   neighbours.push_back(make_pair(row-2,col+1));   
   neighbours.push_back(make_pair(row-2,col-1));   

   //down
   neighbours.push_back(make_pair(row+2,col+1));   
   neighbours.push_back(make_pair(row+2,col-1));   
   
   //left
   neighbours.push_back(make_pair(row+1,col-2));   
   neighbours.push_back(make_pair(row-1,col-2));   

   //right
   neighbours.push_back(make_pair(row+1,col+2));   
   neighbours.push_back(make_pair(row-1,col+2));   

   return neighbours;
}

bool isValid(pair<int,int> &p,int m,int n)
{
   int row = p.first;
   int col = p.second;
   return ((row >= 0) && (row < m) &&
          (col >= 0) && (col < n)); 
}

int bfsktour(int m,int n,int startrow,int startcol,int endrow,int endcol)
{
    queue<pair<int,int>> q;
    int numSquares = m*n;
    int steps= 0;
    vector<vector<int>> visited(m,vector<int>(n,0));
    visited[startrow][startcol] = 0;
    q.push(make_pair(startrow,startcol));
   
    //do bfs unti end is reached
    while(!q.empty())
    {
        int numChildren = q.size();
        steps++;
        while(numChildren)
        {
            pair<int,int> vertex = q.front();
            q.pop(); 
            //enqueue the next level for each vertex popped from q
            for(auto child:getNeighbours(vertex))
            {
                 if(!isValid(child,m,n)) continue;
                 if((child.first == endrow) && (child.second == endcol))
                 {
                     //reached end;
                     return steps;
                 }   
               
                 if(!visited[child.first][child.second])
                 {
                     visited[child.first][child.second] = 1;
                     q.push(make_pair(child.first,child.second));  
                 }       
            }
            //process all children level by level
            numChildren--;
        }
    }
    return -1;   
}

int main()
{  
   int k = 0;
   cout << "Graphs Homework 1 Knights Tour :" << endl;
   //int steps = bfsktour(5,5,0,0,4,1);
   pair<int,int> vertex(2,2);
   for(auto next:getNeighbours(vertex))
   {
      cout << "(" << next.first <<"," << next.second << ")" << ",";
      
   }

   
   //cout << endl << "Printing answer" <<  steps << endl;
}
