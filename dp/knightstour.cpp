#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

#define MAX_DIGITS 10

void print(vector<vector<unsigned int>> &table)
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

int maxPhNos(int digit,int len,unordered_map<int,vector<int>> &neighbours)
{
    vector< vector<unsigned int>> table(MAX_DIGITS,vector<unsigned int>(len,0));
    
    //initialize the base cases
    for(int digit=0; digit<=9;digit++)
    {
        table[digit][0] = 1;
    }   
   for(int i=1; i < len; i++) //for increasing length
   {
       for(int j=0; j<=9; j++) //for each possible digit
       {
            unsigned int sum =0;
            //fill table for every[i][j]
            if(neighbours.find(j) != neighbours.end())
            {
                vector<int> adjacent = neighbours[j];
                for(int k : adjacent) //for every possible neighbour for digit 'j'
                {
                     sum += table[k][i-1];
                }   
            }
            table[j][i] = sum;
       }
   }
   print(table);
   cout << endl;
   return table[digit][len-1];
}

void genNeighbours(unordered_map<int,vector<int>> &neighbours)
{
   neighbours.insert(make_pair(1,vector<int>{6,8}));     
   neighbours.insert(make_pair(2,vector<int>{7,9}));     
   neighbours.insert(make_pair(3,vector<int>{4,8}));     
   neighbours.insert(make_pair(4,vector<int>{0,3,9}));     
   neighbours.insert(make_pair(6,vector<int>{0,1,7}));     
   neighbours.insert(make_pair(7,vector<int>{6,2}));     
   neighbours.insert(make_pair(8,vector<int>{1,3}));     
   neighbours.insert(make_pair(9,vector<int>{2,4}));     
   neighbours.insert(make_pair(0,vector<int>{4,6}));     
/*   for(int i=0;i <=9 ;i++)
   {
    vector<int> adj = neighbours[i];
    cout << i << ": ";
    for(int k : adj)
      cout << k << ",";
    cout << endl;
   }*/
}

int main()
{
   int digit = 1;
   unordered_map<int, vector<int>> neighbours;
   genNeighbours(neighbours);
   cout << "Max Phones Numbers using Knights Tour starting with digit " << digit << " :  " << maxPhNos(digit,30,neighbours);
}
