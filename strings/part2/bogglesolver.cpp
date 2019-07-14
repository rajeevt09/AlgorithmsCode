#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class TrieNode
{
public:
   std::unordered_map<char,TrieNode *>  m_map;
   bool m_isEnd=false;
   int count = 0;
   TrieNode(bool end):m_isEnd(end){};
   ~TrieNode(){};
};

class Trie
{
public:
    Trie()
    {
       m_root = new TrieNode(false);     
    }

    ~Trie()
     {
         //destroy Trie Nodes
     }
    
    void insert(string s)
    {
           cout << " INSERT " << s << " : " <<  endl;
           _insert(m_root,s,0);
           cout << endl;
    }
    TrieNode * root(){return m_root;};

    bool search(string pattern)
    {
        return search(pattern,m_root,0);
    }
private:
   TrieNode *m_root = nullptr;
   
   void _insert(TrieNode *cur,string s,int index)
   {
       TrieNode *next = nullptr;
       if(nullptr == cur) return;
       if( index >= s.length()) return;
       char c = s[index];
       if(cur->m_map.find(c) != cur->m_map.end())
       {
          next = cur->m_map[c];
       }
       else
       {
          next = new TrieNode(false);
          cur->m_map[c] = next;
       }
       cout << c;
       if(index == s.length() - 1)
       {   
          next->m_isEnd = true;
          next->count++;
          cout << "$";
          
       }
       cur->count++;
        _insert(next,s,index+1);
   }

   bool search(string s,TrieNode *cur,int index)
   {
      if(index >= s.length()) return false;
      auto it = cur->m_map.find(s[index]);
      if(it == cur->m_map.end()) return false;
      TrieNode *next = it->second;
      if(index == s.length()-1 && next->m_isEnd) 
      {
         return true;
      }
      return search(s,next,index+1);
   }
   
};

std::unordered_set<string>  dictionary;

pair<int,int> toCell(int neighbour,int m , int n);

bool isValidCell(int x,int y,int m,int n);
int toVertex(int x,int y,int m,int n);
vector<int> getNeighbours(int vertex,int m,int n);
void dfs(vector<vector<char>> &board,int vertex,string &strSofar,vector<bool> &visited,vector<string> &results);
vector<string> findWords(vector<string> dictionaryList, vector<vector<char>> board) {

    vector<string> words;
    int m = board.size();
    if(m == 0) return words;
    int n = board[0].size();
    vector<bool> visited(m*n,false);
    for(string s:dictionaryList)
      dictionary.insert(s);

   //test neighbours
 //  cout << "testing neighbbours" << endl;
 //  vector<int> ll= getNeighbours(0,m,n);
 //  for(int i:ll)
 //   cout << i << ",";

    string s;
    for(int i=0;i<m*n;i++)
    { 
       dfs(board,i,s,visited,words);
    }
    return words;       
}

pair<int,int> toCell(int neighbour,int m , int n)
{
  pair<int,int> cell;
  cell.first = neighbour/m;
  cell.second = neighbour%n;
  return cell;  
} 

int toVertex(int x,int y,int m,int n)
{
   int row = x;
   int col = y;
   return row*n + col;
}

bool isValidCell(int x,int y,int m,int n)
{
  if(x < 0 || y < 0 || x >= m || y >= n) return false; 
  return true;
}

vector<int> getNeighbours(int vertex,int m,int n)
{
  vector<int> neighbours;
  pair<int,int> cell = toCell(vertex,m,n);
  int x = cell.first;
  int y = cell.second;
  //go up
  if(isValidCell(x-1,y,m,n)) 
  neighbours.push_back(toVertex(x-1,y,m,n));
 
  //go down
  if(isValidCell(x+1,y,m,n)) 
  neighbours.push_back(toVertex(x+1,y,m,n));
  
  //go left
  if(isValidCell(x,y-1,m,n)) 
  neighbours.push_back(toVertex(x,y-1,m,n));

  //go right
  if(isValidCell(x,y+1,m,n)) 
  neighbours.push_back(toVertex(x,y+1,m,n));

  //go left-up
  if(isValidCell(x-1,y-1,m,n)) 
  neighbours.push_back(toVertex(x-1,y-1,m,n));

  //go right-up
  if(isValidCell(x-1,y+1,m,n)) 
  neighbours.push_back(toVertex(x-1,y+1,m,n));

  //go left-down
  if(isValidCell(x+1,y-1,m,n)) 
  neighbours.push_back(toVertex(x+1,y-1,m,n));

  //go right-down
  if(isValidCell(x+1,y+1,m,n)) 
  neighbours.push_back(toVertex(x+1,y+1,m,n));

  return neighbours;
}

void dfs(vector<vector<char>> &board,int vertex,string &strSofar,vector<bool> &visited,vector<string> &results)
{
    int m = board.size();
    int n = board[0].size();
    pair<int,int> cell = toCell(vertex,m,n);
    strSofar.push_back(board[cell.first][cell.second]);
    visited[vertex] = true;
   //check if word created so far is in the dictionary and add to results set if yes
   if(dictionary.find(strSofar) != dictionary.end())
   {
       results.push_back(strSofar);
   }

   //get all neighbours for currentvertex
   vector<int> neighbours = getNeighbours(vertex,m,n);
   //continue dfs on all univisited neighbours
   for(int neighbour:neighbours)
   {
       if(!visited[neighbour])
       {
           dfs(board,neighbour,strSofar,visited,results);
       }      
   }
   
   visited[vertex] = false;
   strSofar.pop_back();
}


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //test trie
    Trie t ;
    int index = 0;
    string invec[] = {{"bat"},{"tab"},{"cat"}};
    for(string s : invec)
    {
       cout << s;
       t.insert(s);
    }
    if(t.search("tab"))
    {
       cout << "Found !!  "  << endl;
    }


    vector<string> dictionaryList = {"GEEKS","FOR","QUIZ","GO"};
    vector<vector<char>> board= {{'G','I','Z'},{'U','E','K'},{'Q','S','E'}}; 
    vector<string> results; 
    results = findWords(dictionaryList,board);
    cout << "boogle solvers words are : " << endl;
    for(string res:results)
    {
       cout << res << endl;
    }
    return 0;
}


