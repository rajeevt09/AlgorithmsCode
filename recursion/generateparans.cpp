#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> generate(int i)
{
   vector<string> results;
   if(i == 1) 
   {
      results.push_back("()");
      return results;
   }
   vector<string> subres = generate(i-1);
   for(string s:subres)
   {
        int n = s.length();
        //for each s place a '(' at each possible index and append to results
        for(int i=0;i<=n-1;i++)
        {
            string temp1 = s.substr(0,i);            
            string temp2 = s.substr(i,n);            
            string combination = "(" + temp1 + ")" + temp2;
            results.push_back(combination);
        }
   }

   return results;
}



int main()
{
  vector<string> res = generate(3);
  for(string s:res)
  {
    cout << s << " , ";
  }
}

