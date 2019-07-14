#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode
{
public:
   std::unordered_map<char,TrieNode *>  m_map;
   bool m_isEnd=false;
   int count = 0;
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
    
    void insert(string s)
    {
           cout << " INSERT " << s << " : " <<  endl;
           _insert(m_root,s,0);
           cout << endl;
    }
    TrieNode * root(){return m_root;};

    bool match(string pattern);
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

   
};

class regexp
{
public:
    regexp(Trie *t,string pattern):m_trie(t),m_pattern(pattern){};
    ~regexp(){};

    bool matches()
    {
       bool match = false;
       match = find(m_trie->root(),0);
       return match;
    }
    
private:
    Trie *m_trie = nullptr;
    
    string m_pattern = "";

    bool find(TrieNode *node,int i)
    {
         if(i == m_pattern.length()) return true; 
         if(node == nullptr) return false;
         char c = m_pattern[i];
         if(c != '.' && c != '*')
         {
               TrieNode *child = nullptr;
               char c = m_pattern[i];
               if(node->m_map.find(c) != node->m_map.end())
               {
                   child = node->m_map[c];
               }
               else
               {
                   return false;
               }
               return find(child,i+1);
         }
         else
         {
               cout << c;
               for(auto it:node->m_map)
               {
                   bool local = false;
                   TrieNode *child = nullptr;
                   child = it.second;
                   if(c == '.')
                   {
                       local = find(child,i+1);
                       if(local) return true;
                   }
                   else if (c == '*')
                   {
                      local = find(child,i+1); //match 1 char in text wih *
                      if(local) return true;
                      local = find(child,i);  //match arbitrary chars in text with *
                      if(local) return true;
                   }
               }
               if (c == '*')
               {
                   // 0 matches of * case
                   bool local = find(node,i+1);
                   if(local) return true;
               }

               return false;
         }
  
    }
};

int main()
{
     Trie tt;
     string text = "hellohowarehowyouhowareyou";
     //string text = "banana";
     string pattern = "h..lo*how*are*y";
     //string pattern = "how*you*y";

     int n = text.length();
     for(int i =0 ;i < n; i++)
     {
        //insert all suffixes
        tt.insert(text.substr(i,n-i));        
     }
     regexp exp(&tt,pattern);
     //string lrs_ans = ll.get();
     //cout << "Longest Repeated SubString Is : " << lrs_ans;
     TrieNode * root= tt.root();
     for(auto it:root->m_map)
     {
          cout << it.first  << "," << it.second << " ";
     }
     cout << "Tring to Macth Pattern" << endl;
     bool b = exp.matches();
     cout << "Pattern : " << pattern << "Matches : " << b << endl;
     
}
