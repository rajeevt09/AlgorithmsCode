#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


void print(vector<unsigned int> &table)
{
 //   cout << "size is " << table.size() << endl;
    int n = table.size();
    for(int i = 0 ; i < n ; i++)
    {
   //    cout << table[i].size() << endl;
       cout << endl;
       {
         cout << table[i] << " ";
       }
     }
}

int maxWaysToClimb(vector<int> steps,int n)
{
    vector<unsigned int> table(n+1,0);
    
    //initialize the base cases
    table[0] = 1;
       
   for(int i=1; i <= n; i++) //for increasing steps
   {
         unsigned int sum =0;
         //fill table for every[i]
         for(int k : steps) //for every possible step 'k' that is before step 'i'
         {
              if(k <= i)
              sum += table[i-k];
         }   
         table[i] = sum; //step 'i' can be reached in sum ways
   }
   print(table);
   cout << endl;
   return table[n];
}


int main()
{
   int numSteps = 7;
   vector<int> steps = {2,3};
   cout << "Max Ways To Reach Step  " << numSteps << " :  " << maxWaysToClimb(steps,7);
}
