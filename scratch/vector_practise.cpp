#include <vector>
#include <algorithm>
#include <iostream>
using namespace std ;

void print_table(vector< vector<int>> &t)
{
   int n = t.size();
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<n;j++)
    {
     cout << t[i][j] << ",";
    }
    cout << endl;
   }
}

int main()
{
   int n = 5;
   vector<int> vec = {5,2,3,1,4};
   vector< vector<int>> table(n,vector<int>(n,-1));
   print_table(table);
   cout << "reverse Array " << endl;
   std::reverse(vec.begin(),vec.end());
   for(int i:vec)
    cout << i;
   cout << endl;
   std::sort(vec.begin(),vec.end());
   for(int i:vec)
    cout << i;
   cout << endl;

}
