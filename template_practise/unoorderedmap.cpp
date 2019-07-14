#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
   cout << "practise using unordered_map";
   unordered_map < string, int > names;
   names["Rajeev"] = 37;
   names["Soumya"] = 30;
   names["Kartheek"] = 2;
   names["Mahathi"] = 7;

   for(auto it:names)
   {
       cout << " " <<  it.first;
       cout << " " << it.second;
   }
   cout << endl;
   std::unordered_map<string,int>::iterator it = names.find("Kartheek");
   if(it != names.end())
   {
     cout << " Found : " << it->first << ": " << it->second; 
   }
   
   names.insert(std::make_pair<string,int>(string("dummy"),22));
  
   for(auto it:names)
   {
       cout << " " << it.first;
       cout << " " << it.second;
   }
   cout << endl;
   names.erase(names.find("dummy"));
   for(auto it:names)
   {
       cout << " " << it.first;
       cout << " " << it.second;
   }
   cout << endl;
}
