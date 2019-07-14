#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main()
{
   string s = "hellhellohowareyoyou";
   string p = "hello";
   auto it = std::search(s.begin(),s.end(),p.begin(),p.end());
   if(it != s.end())
   {
       cout << "substring is found at " << it - s.begin() << endl;
   }
   return 0;
}

