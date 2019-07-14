/* Longest substring with at most two distinct characters String homework part 1
Homework
*/

#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

void add(unordered_map<char,int> &map,char &c)
{
    if(map.find(c) != map.end())
    {
        map[c]++;
    }
    else
    {
        map[c] = 0;
    }
}

void remove(unordered_map<char,int> &map,char c)
{
    auto it = map.find(c);
    if(it != map.end())
    {
        if(map[c]) map[c]--;
        if(map[c] == 0) map.erase(it);
    }
}

string longestSub(string strText)
{
   string strMax;
   unordered_map<char,int> map;
   int lo=0,hi=0;
   int len = strText.length();
   
   //keep going forward till constraint satisfied
   while(hi < len)
   {
       add(map,strText[hi]);
       hi++;
       
       //keep increasing lo till constraint satisfied
       while(map.size() > 2 && lo < hi)
       {
           lo++;
           remove(map,strText[lo]);
       }
       if(map.size() == 2 && strMax.length() < (hi-lo))
       {
           //update max
           strMax = strText.substr(lo,hi-lo);
       }     
   }
   return strMax;

}
int main()
{
   string strText = "eceba";
   cout << "longest substring with at most two distinct characters is " << endl;
   cout << longestSub(strText);
}

