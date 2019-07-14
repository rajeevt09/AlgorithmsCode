#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n = 6;
    vector<vector<int>> results;
    queue<int> q;
    q.push(1);
    cout << "1" << endl;
    for(int i=1;i<n;i++)
    {
       //generate each row;
       int val =0;
       int size = q.size();
       while(size)
       {
           int next = q.front();
           q.pop();
           // generate next elem
           int nextelem = val + next;
           cout << nextelem << " ";
           val = next;
           //push the next elemnt on to q
           q.push(nextelem);
           size--;   
       }
       cout << val << " ";
       q.push(val);
       //we are moving to next row now
       cout << endl;
    }    
   
}
