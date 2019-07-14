#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<bool>> queens;
vector < vector<string> > res;
void print_state(int n);

void snapboard(int n)
{
   
       vector<string> row;
       int vecindex = res.size();
       res.push_back(row);
       for(int i=1;i<=n;i++)
       {
          string solution;
          for(int j=1;j<=n;j++)
          {  
               if(queens[i][j])
               {
                  solution = solution + "q" ;
               }
               else
               {
                   solution = solution + ";";
               }
           }
           res[vecindex].push_back(solution);
       }
       print_state(n);
    
}

bool attacks(int n,int row,int col)
{
    for(int i=1;i<=n;i++)
       if(queens[row][i]) return true;
    for(int i=1;i<=n;i++)
       if(queens[i][col]) return true;

    int crow = row,ccol =col;
    while(crow > 1 && ccol >1)
    {
       crow--;
       ccol--;
       if(queens[crow][ccol]) return true;
    }
    crow = row,ccol =col;
    while(crow > 1 && ccol <n)
    {
       crow--;
       ccol++;
       if(queens[crow][ccol]) return true;
    }
    crow = row,ccol =col;
    while(crow < n && ccol >1)
    {
       crow++;
       ccol--;
       if(queens[crow][ccol]) return true;
    }
    crow = row,ccol =col;
    while(crow < n && ccol < n)
    {
       crow++;
       ccol++;
       if(queens[crow][ccol]) return true;
    }
    return false;   
}

bool place(int n,int row,int col)
{
    //clear rows/cols
    if(!attacks(n,row,col))
    {
        queens[row][col] = true;
        //cout << row << "," << col << ";" << endl ;
        return true;
    }
    else
    {
        return false;
    }
}

void unplace(int n,int row,int col)
{
    queens[row][col] = false;
    //updateboard(n,row,col,false);
}

int nqueens(int n , int level)
{
    int sum = 0;
    if(level > n) 
    {
        //snapshot memo;
        snapboard(n);
        return 1;
    }
    for(int i=1;i<=n;i++)
    {
        bool b = place(n,level,i);
        if(false == b) continue;
//        if(level == n) print_state(n);
        sum = sum + nqueens(n,level+1);
        unplace(n,level,i);
    }
    return sum;
}

/*
 * Complete the function below.
 */
vector < vector<string> > find_all_arrangements(int n) {
    for(int i=0;i<=n;i++)
    {
        vector<bool> vec;
        vector<bool> vec2;
        queens.push_back(vec2);
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
         {
            queens[i].push_back(false);
         }
  int cnt = 0;
  cnt = nqueens(n,1);
  return res;   
}

void print_state(int n)
{
      cout << endl << endl;
      cout << "queens :" << endl;
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
         {
            cout << queens[i][j] << "'";
         }
         cout << endl;
     }
}

int main()
{
    int n =4;
     find_all_arrangements(4);
   // cout << "there are levels : " << cnt << endl;
    cout << res.size();
 
     for(int res_i = 0; res_i < res.size(); res_i++) {
        for(int res_j = 0; res_j < res[res_i].size(); res_j++) {
            cout << res[res_i][res_j] << " ";;
        }
        cout << endl;
    }  
}
