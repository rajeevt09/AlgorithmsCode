#include <unordered_map>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
     using myp = pair<int,int>;
     using sp = shared_ptr<myp>;
     class node{
         string name;
         sp left;
         sp right;
     };
     priority_queue<myp,vector<myp>> pq;
     sp p = make_shared<myp>(1,2);

}
