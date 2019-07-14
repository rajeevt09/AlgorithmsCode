#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode
{
public:
   std::unordered_map<char,TrieNode *>  m_map;
   bool m_isEnd=false;
   int count = 0;
   int id = 0;
//   char m_c;
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
    
    void insert(string s,int id)
    {
           cout << " INSERT " << s << " : " <<  endl;
           _insert(m_root,s,0,id);
           cout << endl;
    }
    TrieNode * root(){return m_root;};

    bool search(string pattern,int &id)
    {
        return search(pattern,m_root,0,id);
    }
private:
   TrieNode *m_root = nullptr;
   
   void _insert(TrieNode *cur,string s,int index, int id)
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
          next->id = id;
          cout << "$";
          
       }
       cur->count++;
        _insert(next,s,index+1,id);
   }

   bool search(string s,TrieNode *cur,int index ,int &id)
   {
      if(index >= s.length()) return false;
      auto it = cur->m_map.find(s[index]);
      if(it == cur->m_map.end()) return false;
      TrieNode *next = it->second;
      if(index == s.length()-1 && next->m_isEnd) 
      {
         id = next->id;
         return true;
      }
      return search(s,next,index+1,id);
   }
   
};

string reverse(string s)
{
    string rev;
    int n = s.length();
    for(int i=n-1;i>=0;i--)
    {
        rev.push_back(s[i]);
    }
    return rev;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Trie t ;
    int index = 0;
    string invec[] = {{"bat"},{"tab"},{"cat"}};
    for(string s : invec)
    {
       cout << s;
       t.insert(s,index++);
    }
    int id ;
    index = 0;
    for(string s : invec)
    {
       int matchIndex;
       string rev = reverse(s);
       if(t.search(rev,matchIndex))
       {
           cout << "Fount at " << matchIndex << endl;
           if( matchIndex != index)
           {
              cout << "Palindrome for " << invec[index]<< "exists and is" <<  invec[matchIndex] << endl;
           }
           index++;
       }
     }

    return 0;
}


