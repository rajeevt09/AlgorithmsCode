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
         while(it != s.end())         {
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
      }
}
