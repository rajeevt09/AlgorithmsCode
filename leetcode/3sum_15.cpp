#include <iostream>
#include <vector>
using namespace std;    

 void twoSum(vector<int>& nums,int sum,int skipIndex,vector<vector<int>> &results) ;
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        std::sort(nums.begin(),nums.end());
        //attempt two sum for each element
        for(int i=0;i<nums.size();i++)
        {
            if(i && nums[i-1] == nums[i]) continue;
            cout << "getting 3 sum for " << nums[i] << "at" << " " << i << endl;
            int val = nums[i];
            //this element is nums[i] , so we are looking for -nums[i]
            twoSum(nums,-val,i,results);
        }
        return results;
    }
    
    void twoSum(vector<int>& nums,int sum,int index,vector<vector<int>> &results) 
    {
        //find all pairs that add up to sum
        int lo = index + 1,hi = nums.size() -1;
        while(lo < hi)
        {
            int tempSum = nums[lo] + nums[hi];
            if( tempSum > sum)
            {
                hi--;
            }
            else if (tempSum < sum)
            {
                lo++;
            }
            else
            {
                vector<int> resVec;
                {
                   resVec.push_back(nums[lo]);
                   resVec.push_back(nums[hi]);
                   resVec.push_back(-sum);
                   //they add up to sum
                   results.push_back(resVec);
                }
                hi--;
                lo++;
                    
            }
        }
    }

int main()
{
   vector<int> v{-1,0,1,2,-1,-4};
   vector<vector<int>> results = threeSum(v);
   for(vector<int> result:results)
   {
      for(auto i:result)
      {
         cout << i << ",";
      }
      cout << endl;
   }
}
