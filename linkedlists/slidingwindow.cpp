#include <iostream>
#include <deque>
#include <vector>
using namespace std;
/*
* Complete the function below.
*/
vector<int> max_in_sliding_window(vector <int> arr, int w) 
{
   std::deque<int> q;
   std::vector<int> maxes;
   int index =0;
   for(int i =0 ; i < w ; i++)
   {
      while(!q.empty() && arr[i] > arr[q.front()])
      q.pop_front();
      q.push_front(i);
   }
  maxes.push_back(arr[q.back()]);
  for(int i = w ;i < arr.size() ; i++)
  {
     while(!q.empty() && arr[i] > arr[q.front()])
     q.pop_front();
     /*while(!q.empty() && q.back() <= i-w)
     q.pop_back();*/
     if(!q.empty() && q.back() == i-w) q.pop_back();
     q.push_front(i);
     maxes.push_back(arr[q.back()]);
  }
  return maxes;
}

int main()
{
   //vector<int> arr = {1,3,-1,-3,5,3,6,7};
   vector<int> arr = {4,7,2,6,4,3,5,1};
   vector<int> ans = max_in_sliding_window(arr,3);
   for(auto i:ans)
   {
      cout << i;
   }
   return 0;
}
