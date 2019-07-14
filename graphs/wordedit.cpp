#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

void print(unordered_map<string,vector<string>> &adj)
{
   cout << "Printing Graph" << endl;   
   for(auto it:adj)
   {
      cout << it.first << "->";
      vector<string> neighbours = it.second;
      for(string n: neighbours)
       cout << n << ",";
      cout << endl;
   }
   cout << endl;
}

void build_graph(unordered_map<string,vector<string>> &adj, vector<string> words)
{
     unordered_map<string,string> map;
     //first insert all words into graph with null neighbour list
     for(string w:words)
     {
        vector<string> neighbours;
        adj.insert(make_pair(w,neighbours));
     }

     for(string w:words)
     {
          string pattern = w;
          //generate all patterns of the word and insert into map
          for(int i = 0; i < w.length(); i++)
          {
                pattern[i] = '*';
                if( map.find(pattern) != map.end())
                {
                    string orig = map[pattern];
                    //edge exists between w and matched pattern's orig in map
                    adj[orig].push_back(w);
                    adj[w].push_back(orig);
                    cout << "Add Edge" << w << " : " << orig << endl;
                }
                else
                {
                    //insert newly created pattern into map <key = pattern,value = word>
                    map[pattern] = w;
                }
                //restore
                pattern[i] = w[i];
          }
     }
}

vector<string> bfs(unordered_map<string,vector<string>> &adj, string start, string stop)
{
   queue<string> q;
   unordered_map<string,bool> visited;
   unordered_map<string,string> edgeto;
   vector<string> results;
   stack<string> s;
   visited[start] = true;
   q.push(start);
   bool found = false;
   while(!q.empty())
   {
       string node = q.front();
       q.pop(); 
       if(node == stop) 
       {
          //shortest path found
          found = true;
          break;
       }
       //get all neighbours of node
       vector<string> neighbours = adj[node];
       for(string n:neighbours)
       {
           //skip already visited
           if(visited.find(n) != visited.end()) continue;
           edgeto[n] = node;
           //cout << endl << n << " --> " << node << endl;
           visited[n] = true;
           q.push(n);
       }
   }

   if(found)
   {
      string next = stop;
      while(next != start)
      {
         s.push(next);
         next = edgeto[next];
      }
      s.push(start);
   }
   //populate results
   while(!s.empty())
   {
     results.push_back(s.top());
     s.pop();
   }
   return results;
}

vector<string> string_transformation(vector<string> words, string start, string stop) 
{
    unordered_map<string,vector<string>> adj;
    words.push_back(start);
    build_graph(adj,words);
    print(adj);
    vector<string> results;
    results = bfs(adj,start,stop);
    if(results.size() == 0)
    {
       results.push_back("-1");
    }   
    return results;
}

int main()
{
    vector<string> words = {"cat","hat","bad","had"};
    string start = "bat";
    string stop = "had";
    vector<string> results = string_transformation(words,start,stop);
    cout << "Convert one word to another word in Min Steps" << endl;
    for(string s:results)
    {
       cout << s << " -> " ;
    }
    cout << endl;
}

