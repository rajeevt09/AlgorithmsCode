#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
int main()
{
   unordered_map<int,vector<char>>  map{{1,{'a','b'}}};
   vector<vector<int>> arr{{1,10},{5,2},{2,4},{7,15},{3,6}};
   std::sort(arr.begin(),arr.end(),[](vector<int> &a,vector<int> &b){return a[1] < b[1];});
   for(vector<int> v:arr) cout << v[0] << " : "  << v[1] << " , ";
   priority_queue<int,vector<int>,less<int>> pq;
   pq.push(3);
   pq.push(1);
   pq.push(8);
   while(!pq.empty())
   {
      cout << pq.top();
      pq.pop();
   }
}
