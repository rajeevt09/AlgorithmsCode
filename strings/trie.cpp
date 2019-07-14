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

class lrs
{
public:
    lrs(Trie *t):m_trie(t){};
    ~lrs(){};

    string get()
    {
       string s = "";
       lrs_find(m_trie->root(),s);
       return max_so_far;
    }
    
private:
    Trie *m_trie = nullptr;
    
    string max_so_far = "";

    void lrs_find(TrieNode *node,string s)
    {
         if(node == nullptr) return ;
         if(node->m_isEnd) cout << endl <<" < " << s <<  " >" << endl;
         int count  = 0;
         for(auto it:node->m_map)
         {
               TrieNode *child = nullptr;
               char c = it.first;
               child = node->m_map[c];
               //cout << c << " " << child;
               s.push_back(c);
               lrs_find(child,s);
               s.pop_back();
         } 
         cout  << s << " count" << node->count <<  endl;
         if(node->count >= 2)
         {
             if( max_so_far.length() < s.length())
             {
                 max_so_far = s;          
             }        
         }
         
    }
};

int main()
{
     Trie tt;
     //string text = "hellohowarehowyouhowareyou";
     string text = "banana";
     int n = text.length();
     for(int i =0 ;i < n; i++)
     {
        //insert all suffixes
        tt.insert(text.substr(i,n-i));        
     }
     lrs ll(&tt);
     //string lrs_ans = ll.get();
     //cout << "Longest Repeated SubString Is : " << lrs_ans;
     TrieNode * root= tt.root();
     for(auto it:root->m_map)
     {
          cout << it.first  << "," << it.second << " ";
     }
     cout << "Tring to Find LRS" << endl;
     string lrs_ans = ll.get();
     cout << "Longest Repeated SubString Is : " << lrs_ans << endl;
     
}
