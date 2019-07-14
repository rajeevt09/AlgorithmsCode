#include <vector>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
class Solution {
public:
    
       vector<vector<int>>& m_board;   
        int m_n;
        int m_rows;
        int m_cols;
    
    int snakesAndLadders(vector<vector<int>>& board) {
        m_board = board;
        if(board.size()  == 0) return 0;
        m_rows = board.size();
        m_cols = board[0].size();
        int m_n = m_rows * m_cols;
        return bfs();
    }
    
    pair<int,int> toCell(int v)
    {
        int row = m_rows -1 - (v-1)/m_rows;
        int col= (v-1) %m_cols;
        if(row%2)
        {
           //odd rows go in opposite dir 
           col = m_cols - col -1; 
        }        
        return make_pair(row,col);
    }
        
    vector<int> getNeighbours(int v)
    {
         vector<int> neighbours;
         for(int i=1;i<=6;i++)
         {
             int next = v+i; 
             if(next > m_n) continue;
             pair<int,int> cell = toCell(next);
             if(m_board[cell.first][cell.second] != -1)
             {
                 next = m_board[cell.first][cell.second];
             } 
             neighbours.push_back(next);
         }
         return neighbours;
    }
    
    int bfs()
    {
        int levels = 0;
        int n = m_board.size() * m_board[0].size();
        vector<int> visited(n,0);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        while(!q.empty())
        {
            //get count of children at current level
            int n = q.size();
            
            //process all elemnts at current level first
            while(n)
            {
                int vertex = q.front();
                q.pop();
                //get all neighbours from current positions
                vector<int> neighbours = getNeighbours(vertex);
                for(int neighbour:neighbours)
                {
                    if(neighbour == m_n) return levels;
                    if(visited[neighbour]) continue;
                    q.push(neighbour);
                    visited[neighbour] = true;
                }   
                n--;
            }
            
            levels++;
        }
        return levels;
    }
    
};


int main()
{
   return 0;
}
