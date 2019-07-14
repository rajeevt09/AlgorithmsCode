#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef pair<int,int> myp;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> results;
        priority_queue<myp,vector<myp>> pq; // keep only k elems in the pq(use a maxpq)
        for(int &elem:arr)
        {
            //put the diff into pq 
            int diff = abs(x-elem);
            if(!pq.empty() && pq.size() == k) // capacity reached
            {
               myp top = pq.top();
               if(top.first < diff && top.second < elem  )
               {
                  //this element can be ignored as it has greater distance to x or is larger than what we have for tie
                  continue;
                }
                else
                {
                    //need to replace 
                    pq.pop();
                }
            }
            //insert into the pq
             pq.push(make_pair(diff,elem));
        }
        
        while(!pq.empty())
        {
            results.push_back(pq.top().second);
            pq.pop();
        }
        return results;
    }
};

int main()
{
   vector<int> arr = {8,2,4,10,3,100,23};
   std::priority_queue<int,vector<int>,less<int>> pq(arr.begin(),arr.end());
   for(int i=0;i<3;i++) 
   {
      cout  << pq.top() << ",";
      pq.pop();
   }

};
