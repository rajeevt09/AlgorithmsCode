#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void print(vector<int> table)
{
   int n = table.size();
   for(int i=0;i<n;i++)
   {
      cout <<  table[i] << ",";
   }
}

int max_robbery(vector<int> hvals)
{
   int n = hvals.size();
   vector<int> table(n,0);
   //initialize base case
   table[n-1] = hvals[n-1];
   for(int i = n-2; i >= 0; i--) // for each House starting at index i :n
   {
       unsigned int max = hvals[i];
       for(int j = i+2;j < n; j++) // for each j possible after i pick max
       {
          
          if( hvals[i] + table[j]  > max )
              max = hvals[i] + table[j];     
       }
       table[i] = max;
   }
   print(table);
   return table[0];
}

int main()
{
   vector<int> arrHouseValues = {6,1,2,7};
   cout << "Max Robbery for Houses " << " : " << max_robbery(arrHouseValues);
}
