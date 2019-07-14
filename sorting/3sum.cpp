#include <iostream>
#include <vector>
#include <string>
using namespace std;

void twosum(int sum,vector<int> arr , int ignore,vector<string> &triplets,string instr)
{
    int lo = ignore+1;
    int hi = arr.size() -1;
    if(lo == ignore) lo++;
    if(hi == ignore) hi--;
    while(lo<hi)
    {
        int currsum = arr[lo] + arr[hi];
        if(currsum < sum) 
        {
            lo++;
            if(lo == ignore) lo++;
        }
        else if(currsum > sum) 
        {
            hi--;
            if(hi == ignore) hi--;
        }
        else
        {
            string s =  instr;
            s += std::to_string(arr[lo]);
            s += std::to_string(arr[hi]);
            s += "\r\n";
            triplets.push_back(s);
            cout << s;
            lo++;
            hi--;
        }
        
    }
}
/*
 * Complete the function below.
 */
vector <string> printTriplets(vector <int> intArr) {
      vector<string> triplets;
      std::sort(intArr.begin(),intArr.end());
      for(int i=0;i<intArr.size();i++)
      {
          string s = std::to_string(intArr[i]);
          twosum(-intArr[i],intArr,i,triplets,s);
      }
      return triplets;
}


int main()
{
    vector<int> arr = {-2,0,3,1,-1,4};
    vector<string> tuples = printTriplets(arr);
   
}

