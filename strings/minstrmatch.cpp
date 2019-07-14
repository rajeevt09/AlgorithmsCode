#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <iostream>
using namespace std;

/* find min sub - string that contaions all characters in given set */
class Solution {
public:
    string minWindow(string s, string t) {
       string strSmallestSoFar;
       size_t minIndex = 0;
       size_t minLen = 0; 
       cout << "Input " << s << " , " << t << endl;        
       std::set<char> pattern;
       std::unordered_map<char,int> window;
       for(char c:t) pattern.insert(c);
       size_t lo = 0,hi =0;
       size_t n = s.length();
       size_t m = t.length();
       while(lo < n && hi < n)
       {
//           cout << lo << "," << hi << endl;
           //keep increasing hi till constraint satisfied
           while(window.size() < m && hi < n)
           {
               if(pattern.find(s[hi]) != pattern.end()) 
               {
                   char c = s[hi];
                   if(window.find(c) != window.end())
                   {
                      cout << "inserted in map : " <<  c;
                      window.insert({s[hi],1}); 
                   }
                   else
                   {
                      window[c]++;
                   }
               }
               hi++;
           }
//           cout << "window match  found (" << lo << "," << hi << ")" << " " << window.size() << endl;
 
           //keep increasing lo till constraint remains satisfied
           while(window.size() == m && lo < hi )
           {
                if((hi-lo) < minLen)
                {
                   minIndex = lo;
                   minLen = hi-lo;
                }
               char c = s[lo];
               if(window.find(c) != window.end())
               {
                    window[c]--; 
                    cout << "removed from map : " << c << " count  : " << window[c];
                    if(window[c] == 0) 
                    {
                    cout << "removed " << lo << " : " << c;
                    window.erase(window[c]);
                    }
               }
               lo++;
           }
       }
       cout << minIndex << "," << minLen;
       return strSmallestSoFar;
    }
};


int main()
{
   Solution soln;
   string ans = soln.minWindow("ABAACACAB","ABC");
   cout << ans;
}
