#include <unordered_map>
#include <vector>
#include <iostream>
#include <unistd.h>

using namespace std;
class KVStore
{
public:
  string get(string key,string timestamp = "")
  {
      string s;
      if(myMap.find(key) != myMap.end())
      {
           if(timestamp.length())
           {
                if(myMap[key].find(timestamp) != myMap[key].end())
                {
                   return myMap[key][timestamp];
                }
                else
                {
                   return s;
                }
           }
           else
           {
              cout << "no time sepcified" << endl;
              //return last
              string val;
              for(auto v :myMap[key]){ val = v.second;break;}
              cout << "last val is " << val << endl;
              return val;         
           }
      }
      return s;
  }

  string put(string key,string val)
  {
     time_t rawtime;
     time(&rawtime);
     string timestamp = ctime(&rawtime);
   
     cout << "Put val " << val << " with Time : " << timestamp << endl;
     myMap[key].insert(make_pair(timestamp,val));
     return timestamp;
  }


private:
  unordered_map<string,unordered_map<string,string>> myMap;
};

int main()
{
   KVStore kvstore;
   string time = kvstore.put("abc","cat");  
   usleep(200000);
   kvstore.put("abc","bat");

   cout << kvstore.get("abc",time);  // must get 
   cout << kvstore.get("abc");


   unordered_map<char,int> map;
   cout << "checking not present char" << endl;
   int val = map['a'];
   cout << val << "Map size" << map.size()  << endl;
   
   string s="abc";
   unordered_map<char,int> charmap;
   for(char c:s)
   {
       charmap[c] = c - 'a';
   }
   cout << "map size is  " << charmap.size() << endl;

   using myp = pair<string,int>;
   //unordered_map<string,int> strFrequencies {{"hello",3},{"how",10},{"are",8},{"you",3}};
   unordered_map<string,int> strFrequencies {{"h",3}};
   //lets find the string that occurs most
   auto it = std::max_element(strFrequencies.begin(),strFrequencies.end(),[](const myp &a,const myp &b){return a.second < b.second; });
   cout << it->first;
}
