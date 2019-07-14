#include <vector>
#include <iostream>
using namespace std;

void wildcard(string &s,int index)
{
   if(index == s.length()) 
   {
       cout << s;
       cout << endl;
       return;
   }
   if(s[index] == '?')
   {
       s[index] = '0';
       wildcard(s,index+1);
       s[index] = '1';
       wildcard(s,index+1);
       s[index] = '?';
   } 
   else
   {
       wildcard(s,index+1);
   }
  
}


int main()
{
   string s = "?1?0";
   cout << "input" << s << endl;
   cout << "output" << endl;
   wildcard(s,0);
}
