/* Longest Common Subsequence */
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


string dp_lcs(string str1,string str2)
{
     int m = str1.length();
     int n = str2.length();
     //grid will be m*n array
     vector<vector<int>> table(m+1,vector<int>(n+1,0));

     //init base cases
     for(int i = 0; i<= m ; i++)
     {
         table[i][n] = 0;
     }
     for(int i = 0; i<= n ; i++)
     {
         table[m][i] = 0;
     }
     //fill the table from bottom up
     string longestsequence;
     for(int i = m-1; i >= 0 ; i--)
     {
        for(int j = n-1; j >= 0 ;j--)
        {
             int max = 0;
             max = std::max(table[i+1][j],table[i][j+1]);
             int diagcell = table[i+1][j+1];
             if( str1[i] == str2[j]) 
             {
                  diagcell += 1;
             }
             max = std::max(max,diagcell);
             //update (i,j)
             table[i][j] = max;    
        }
     }  

     // length of lcs is in table[0][0];
     cout << "Length of LCS is : " << table[0][0];
     int i = 0, j = 0;
     while(i < m && j < n )
     {
         if(table[i][j] == table[i+1][j+1] + 1 && str1[i] == str2[j])
         {
              longestsequence.push_back(str1[i]);
              i++;j++;
         }
         else if(table[i][j] == table[i+1][j])
         {
               i++;
         }
         else
         {
               j++;
         }
     }
     return longestsequence;
}


int main()
{
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    string lcs = dp_lcs(str1,str2);
    cout << "LCS is " << lcs << endl;
}
