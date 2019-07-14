#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class StrTokenizer
{
public:
     StrTokenizer(string s,string delims):m_str(s),m_delims(delims)
     {
         auto it = s.begin();         
         auto it_next = it;
         while(it != s.end())
         {
             it_next = find_first_of(it,s.end(),m_delims.begin(),m_delims.end());
             size_t pos = distance(s.begin(),it);
             size_t nlen = distance(it,it_next);
             if(nlen)
             {
                 string sub = s.substr(pos,nlen);
                 m_tokens.push(sub);
             }
             if(it_next == s.end()) break;
             it = it_next +1;
         }
     }
     
     bool getNext(string &token)
     {
         if(m_tokens.empty()) return false;
         token = m_tokens.front();
         m_tokens.pop();
         return true;
     }

private:
     string m_str;
     string m_delims;
     queue<string> m_tokens;
};

class TrieNode
{
public:
   std::unordered_map<char,TrieNode *>  m_map;
   bool m_isEnd=false;
   int count = 0;
   vector<int> m_indexes;
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
    
    void insert(string s,int pos)
    {
           cout << " INSERT " << s << " : " <<  endl;
           _insert(m_root,s,0,pos);
           cout << endl;
    }

    bool find(string word,vector<int> &positions)
    {
          return _find(m_root,word,0,positions);    
    }
    TrieNode * root(){return m_root;};

    bool match(string pattern);
private:
   TrieNode *m_root = nullptr;
   
   void _insert(TrieNode *cur,string s,int index,int pos)
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
          next->m_indexes.push_back(pos);
          cout << "$";
          
       }
       cur->count++;
        _insert(next,s,index+1,pos);
   }

   bool _find(TrieNode *cur,string s,int index,vector<int> &positions)
   {
      if(index >= s.length()) return false;
      char c = s[index];
      if(cur->m_map.find(c) != cur->m_map.end())
      {
           TrieNode *next = cur->m_map[c];
           if(next->m_isEnd)
           {
               positions = next->m_indexes;
               return true;
           }
           return _find(next,s,index+1,positions);     
      }
      return false;     
   }

   
};


int main()
{
      Trie myTrie;
      string text("hello how are you how");
      StrTokenizer  sTokenizer(text," ");
      string word;
      cout << endl;
      int pos = 0;
      while(sTokenizer.getNext(word))
      {
           cout << word << ",";
           myTrie.insert(word,pos);
           pos += word.length() + 1; 
      }
      vector<int> matches;
      if(myTrie.find("how",matches))
      {
           cout << "Found at : " << endl;
           for(int pos:matches)
           {
              cout << pos << ",";
           }
      }
}
