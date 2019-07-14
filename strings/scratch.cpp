#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
   vector<string> array = {"bat","tab","cat"};
   vector<string> temp(array.size(),string());

 

   temp[2] = std::move(array[1]);
   temp[1] = std::move(array[0]);
   temp[0] = std::move(array[2]);

   cout << "Outputting array" << endl;
   for(int i=0;i<array.size();i++)
   {
      cout << array[i] << endl;
   }
 

   cout << "Outputting temp" << endl;
   for(int i=0;i<temp.size();i++)
   {
      cout << temp[i] << endl;
   }

   string p = "hello";
   string s = "greeting some one by saying hello how are you";
   auto it = std::search(s.begin(),s.end(),p.begin(),p.end());
   if(it != s.end())
   {
       cout << "text :" << s << endl;
       cout << "pattern found ta index :" << distance(s.begin(),it);
   }
   return 0;
}
