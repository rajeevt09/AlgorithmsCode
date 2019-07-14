/* DP solution for matrix multiplication*/
#include <vector>
#include <iostream>
using namespace std;

void print_table(vector<vector<int>> &table)
{
   int n=table.size();
   for(int i=0; i<n ; i++)
   {
      cout << endl;
      for(int j=0; j<n ; j++)
      {
          cout << table[i][j] << " " ;
      }
   }
}

int matrix_mult_dp(vector<int> &d)
{
   int n=d.size() - 1;
   vector<vector<int>> table(n,vector<int>(n,0));

   //fill in base cases
   for(int i=0; i < n ; i++)
   {
      table[i][i] = 0;
   }

   for(int col= 1; col < n ;col++)
   {
        int j = col;
        for(int i = 0; i < n - col  ;i++)
        {
            cout << "(" << i << "," << j << ")" << " " << "," << " ";
            int min = 0x7fffffff;

            //calculate value at table[i,j]
            /*  For Each position k in (i,j) get min of :
            //  table[i,k] + table[k+1,j] + d[i] * d[k+1] * d[j+1];
            */
            for(int k = i; k < j ; k++)
            {
                int cost = table[i][k] + table[k+1][j] + d[i] * d[k+1] * d[j+1];
                if(cost < min)
                  min = cost;
            }            
            //update best product for matrix from [i-j] inclusive
            table[i][j] = min;
            j++;
        }
        cout << endl;
   }
   print_table(table);
   return table[0][n-1];

}

int main()
{
   //Matrix M[i] has dimensions D[i-1] * D[i]
   vector<int> dimensions = {1,3,1,4};
   cout << "DP Solution For Matrix Multiplication : " << matrix_mult_dp(dimensions) << endl; 

}
