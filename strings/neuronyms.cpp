#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> generate(string s)
{
    vector<string> solution;
    vector<string> prefixes;
    vector<string> suffixes;
    for(int i=s.length()-2;i>=0;i--)
    {
        string pp = s.substr(0,i);
        prefixes.push_back(s.substr(0,i));
        cout << pp << endl;
    }
    for(int i=0;i<=s.length()-2;i++)
    {
        string ss = s.substr(i+2,s.length()-i-2);
        suffixes.push_back(ss);
        cout << ss << endl;
    }
    for(string s1:prefixes)
    {
      for(string s2:suffixes)
      {
          //cout << s1 << s2 << endl;
          int missing = s.length() - (s1.length() + s2.length());
          if(missing >= 2)
          {
               cout << s1 << missing << s2 << endl;
          }
      }
    }
   return solution;
}


int main() {
    string s = "batch";
    generate(s);
return 0;
}
