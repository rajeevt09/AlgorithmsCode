#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
using namespace std;

void print(unordered_map<char,vector<char>> &adj)
{
   cout << "Printing Graph" << endl;   
   for(auto it:adj)
   {
      cout << it.first << "->";
      vector<char> neighbours = it.second;
      for(char n: neighbours)
       cout << n << ",";
      cout << endl;
   }
}

void generate(vector<string> words,unordered_map<char,vector<char>> &adj,int lo,int hi,int k);
void generateNeighbours(vector<string> words,unordered_map<char,vector<char>> &adj)
{
  int n = words.size();
  generate(words,adj,0,n-1,0);
    
}


void generate(vector<string> words,unordered_map<char,vector<char>> &adj,int lo,int hi,int k)
{
   int new_lo = lo;
   int new_hi = lo;
   if(lo > hi) return;
   if(lo == hi) 
   { 
       vector<char> neighbours;
       string s = words[new_lo];
       if(k >= s.length()) return;
       adj.insert(make_pair(s.at(k),neighbours));
       return;
   }
   string s;
   while(new_lo <= hi && new_hi <= hi)
   {
       vector<char> neighbours;
       //generate new lo,hi pairs
       new_lo = new_hi;
       new_hi = new_lo;
       s = words[new_lo];
       if(k >= s.length()){new_hi++;continue;};
       char c = s[k];
       //insert the char first into the graph
       cout << c << ";";
       adj.insert(make_pair(c,neighbours));
       while(new_hi <= hi && s[k] == words[new_hi].at(k)) new_hi++;
       //recurse on (new_lo,new_hi)
       //add an edge between c and next char
       if(new_hi <= hi)
       {
           cout << c << "," << words[new_hi].at(k) << endl;
           //insert corresponding second node also into graph
           adj.insert(make_pair(words[new_hi].at(k),neighbours));
           adj[c].push_back(words[new_hi].at(k));  
       }
        generate(words,adj,new_lo,new_hi-1,k+1);
   } 
       

}

void topsort(unordered_map<char,vector<char>> &adj,char v , stack<char> &order,unordered_map<char,bool> &visited)
{
    if(visited.find(v) != visited.end()) return;
    visited[v] = true;
    vector<char> neighbours = adj[v];
    for(char n :neighbours)
    {
       topsort(adj,n,order,visited);
    }
    order.push(v);
}

/*
 * Complete the function below.
 */
string find_order(vector <string> words) {
    unordered_map<char,vector<char>> adj;
    unordered_map<char,bool> visited;
    stack<char> order;
    string finalorder;
    //Step 1 generate graph of neighbours
    generateNeighbours(words,adj);
    //step 2 top sort the graph in adj for every vertes
    for(auto it:adj)
    {
       topsort(adj,it.first,order,visited);
    }
    while(!order.empty())
    {
        finalorder.push_back(order.top());
        order.pop();
    }
    return finalorder;
}



int main()
{
    cout << "Graphs Part 1 HW Lexicographic order in alien dict" << endl;
    string words[]= {"baa","abcd","abca","cab","cad"};
    vector<char> result;
    unordered_map<char,bool> visited;
    std::stack<char> order; 
    //graph representation
    unordered_map<char,vector<char>> adj;

    //construct the graph 
    generateNeighbours(words,adj);

    print(adj);

    //perform topologocial sort on graph
    for(auto it:adj)
      topsort(adj,it.first,order,visited);

    //output the order
    while(!order.empty())
    {
        result.push_back(order.top());
        order.pop();
    }
    cout << "results are " << endl;
    for(char c:result)
    {
        cout << c;
    }
    cout << endl;

}
