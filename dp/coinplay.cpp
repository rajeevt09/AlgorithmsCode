#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(vector<vector<int>> &table)
{
 //   cout << "size is " << table.size() << endl;
    int n = table.size();
    for(int i = 0 ; i < n ; i++)
    {
   //    cout << table[i].size() << endl;
       cout << endl;
       for(int j = 0 ; j < table[i].size() ; j++)
       {
         cout << table[i][j] << " ";
       }
     }
}

int dp_coin_play(vector<int> arr, int n)
{
    vector<vector<int>> table;
    table.resize(n);
    for(int i = 0 ; i < n ; i++)
    {
       table[i].resize(n);
    }
    //initialize the base cases
    for(int i = 0 ; i < n ; i++)
    {
       table[i][i] = arr[i];
       if(i+1 < n)
       table[i][i+1] = std::max(arr[i],arr[i+1]);        
    } 
    
    for(int i = n-3; i >= 0 ; i--)
    {
     cout << endl;
     for(int j = i+2 ; j < n ; j++)
     {
        //cout << i << "," << j << ";" ;
        //player 1 chooses left 
        int choice1 = std::min(table[i+2][j],table[i+1][j-1]) ;   //player 2 can choose left or right
        choice1 += arr[i];

        //player 1 choose right
        int choice2 = std::min(table[i+1][j-1],table[i][j-2]) ;
        choice2 += arr[j];

        table[i][j] =  std::max(choice1,choice2);
     }
    }
    //print(table); 
    return table[0][n-1];

}


int main()
{
    vector<int> coins = {8,15,3,7} ;
    cout << endl << "Most Coins Player1 can collect is " << dp_coin_play(coins,coins.size()) << endl;
}
