#include <string>
#include <vector>
#include <iostream>
using namespace std;


int main()
{
   string s = "Hello#How#Are#You";
   //lets tokenize the string
   auto cur = s.begin();
   auto next = cur;
   while(cur != s.end())
   {
      next = find(cur,end(s),'#');
      if(next == s.end()) break;
      size_t pos = distance(s.begin(),cur); 
      size_t len = distance(cur,next);
      cout << s.substr(pos,len) << endl;
      cur = next + 1;    
   }
   return 0;
}
