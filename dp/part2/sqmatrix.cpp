#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxSubmatrix(vector< vector<int>> mtx) {
    int n = mtx.size();
    int maxsize = 0;
    vector< vector<int>> table(n+1,vector<int>(n,0));

    //init base cases ie i = N and j =N
    for(int i=0; i <= n ; i++)
    {
       table[i][n] = 0;
       table[n][i] = 0;
    }
   
    for(int i = n-1; i >= 0 ; i--)
    {
       for(int j = n-1; j >= 0 ; j--)
       {
           int val = std::min(table[i+1][j],table[i][j+1]);
           table[i][j] = mtx[i][j] + std::min(val,table[i+1][j+1]);
           maxsize = std::max(maxsize,table[i][j]);
       }
     }
    return maxsize;
}



int main()
{
   vector< vector<int>> arr(6,vector<int>(6,0));
   
   cout << "largest square matrix with all 1s :" << endl;
   cout << maxSubmatrix(arr) << endl; 
}
