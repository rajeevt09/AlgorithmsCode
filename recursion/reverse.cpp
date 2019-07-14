#include <string>
#include <iostream>
using namespace std;


string reverse_fun(string &s)
{
   if(s.length() == 0) return ""; 
   string last = string(1,s[s.length()-1]);
   string prefix = s.substr(0,s.length()-1);
   string retstr = reverse_fun(prefix);
   return last + retstr;
}

int main()
{
   string test = "reverseme";
   string rev = reverse_fun(test);
   cout << endl << rev << endl;
}

