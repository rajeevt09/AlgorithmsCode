#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> badness;
#define VERY_BAD 0xffffff
void print_table(vector<int> &table,vector<int> &linebreaks)
{
     cout << "badness" << endl;
     for(int i=0; i < badness.size() ; i++)
     {
         cout << endl;
         for(int j = 0; j < badness.size(); j++)
         {
              cout << badness[i][j] << " ";
         }
     }
     cout << endl << "Table : ";
     for(int i:table) cout << i << ",";
     cout << endl << "Breaks : ";
     for(int i:linebreaks) cout << i << ",";
     cout << endl;
}


void fill_badness(vector<string> &strArr,int lineWidth)
{
    int n = strArr.size();
    badness.resize(n);
    for(int i=0;i<n;i++)
        badness[i].resize(n);
    
    for(int i=0;i<n;i++)
    {
        int tlen = 0;
        for(int j=i;j<n;j++)
        {
            tlen += strArr[j].length();
            if((tlen + (j-i)) > lineWidth) {badness[i][j] = VERY_BAD;}
            else
            {
               //calculate badness for words i-j on a line
                badness[i][j] = lineWidth - (tlen + (j-i));
                badness[i][j] = badness[i][j] * badness[i][j] * badness[i][j];
            }
        }
    }
}    

//f(i) - is the min badness for paragrah with words(i:n)

/*
 * Complete the function below.
 */
int minSpaceCost(vector <string> strArr, int lineWidth) {

    int n = strArr.size();
    vector<int> lineBreaks(n+1,0);
    // we will have a table that stores the min badness for word ending at index 'i'
    vector<int> table(n+1,0);
    table[n] = 0;

    fill_badness(strArr,lineWidth);

    for(int i = n-1; i>= 0 ; i--)
    {
        int minCost = VERY_BAD;
        int minIndex = 0;
        //update the min Cost at Index i
        //Try word break at every possible position for i : i - (n-1)
        for(int j = i; j <= n-1; j++)
        {
             int cost = badness[i][j] + table[j+1];
             if(cost <= minCost)
             {
                 minIndex = j;
             }
             minCost = std::min(cost,minCost);
        } 
        // update the min badness at position i
        table[i] = minCost;
        lineBreaks[i] = minIndex;
    }

    print_table(table,lineBreaks);

    //print the paragraph at the optimized line breaks
    int i = lineBreaks[0];
    int last = 0;
    do
    {
         //print words from last to i
         for(int j = last;j <= i;j++)
         {
              cout << strArr[j] << " ";
         }
         cout << endl;
         last = i+1;
         i = lineBreaks[i+1];
    }
    while(last < n-1);
    return table[0];
}

int main()
{
    //minimize the badness of paragraph alignment
    vector<string> para = {"The","Cat","In","my","hat"};
    cout << "Min Badness Is " << minSpaceCost(para,10);
}
