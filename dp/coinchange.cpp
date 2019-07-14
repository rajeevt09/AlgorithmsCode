#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void print_rec(vector<pair<int,vector<int>>> &table, int total)
{
    if (total == 0) 
    {
      cout << endl;
      return;
    }
    //print all elements at current level
    for(int denomination: table[total].second)
    {
       cout << denomination << ",";
       //proceed to print next level
       print_rec(table,total-denomination); 
    }
} 

void print(vector<pair<int,vector<int>>> table)
{
    cout << " table contents :" << endl;
    for(auto i:table)
    {
       cout << i.first << " " ;
    }

    cout << "choices : " << endl;
    print_rec(table,table.size()-1);   
    cout << endl;
}

int makeChange(int C, vector<int> denom)
{
   int n = C+1;
   vector<pair<int,vector<int>>> table(n);
   //init the base case
   table[0] = make_pair(0,vector<int>());
   for(int i=1;i<=C;i++) //for verey possible value i
   {  
      int min = 0x7fffffff;
      //try every possible denomination and pick min
      for(int j:denom)
      {
          if(i >= j)
          {
              min = std::min(min,table[i-j].first);
          }
      }
      //remember all min choices
      for(int j:denom)
      {
         if( (i >= j) && (table[i-j].first == min))
            table[i].second.push_back(j);
      }
      //update table for value = i
      table[i].first = min + 1;
   }
   print(table);
   return table[C].first;
}

int main()
{
   vector<int> vec={1,2,3};
   cout << "Total Ways to Make Coin Change is : " << makeChange(4,vec);
}
