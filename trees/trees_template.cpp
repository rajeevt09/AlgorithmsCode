#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <memory>
using namespace std;
class node
{
public:
   int val;
   shared_ptr<node> left;
   shared_ptr<node> right;
   node(int v)
   {
      val = v;
   }
   ~node()
   {
//     cout << "destroy " << val << endl;
   }
};

void printTree(shared_ptr<node> root)
{
    int val;
    queue<pair<shared_ptr<node>,int>> q;
    int level =0;
    q.push(make_pair(root,level));
    cout << "Displaying Tree : " << endl;
    while(!q.empty())
    {
        pair<shared_ptr<node>,int> pr = q.front();
        shared_ptr<node> p = pr.first;
        if(level < pr.second)
        {
          cout << endl;
        }
        level = pr.second;
        cout << p->val << ",";
        q.pop();
        if(p->left) q.push(make_pair(p->left,level+1));
        if(p->right) q.push(make_pair(p->right,level+1));
    }
 
}

shared_ptr<node> _buildTree(vector<int> array,int lo,int hi,stack<int> &s);
shared_ptr<node> rebuildTree(vector<int> preOrder,vector<int> inOrder)
{
  int n = preOrder.size();
  stack<int> s;
  for(auto it = preOrder.rbegin();it != preOrder.rend(); it++)
  {
     cout << *it << ",";
     s.push(*it);
  }
  return _buildTree(inOrder,0,n-1,s);   
}

shared_ptr<node> _buildTree(vector<int> array,int lo,int hi,stack<int> &s)
{
    if(lo > hi) return nullptr;
    int val = s.top();
    shared_ptr<node> pNode = make_shared<node>(val);
    int mid = lo;
    while(array[mid] != val && mid <= hi) mid++;
    //determine mid 
    s.pop();
    pNode->left = _buildTree(array,lo,mid-1,s);
    pNode->right = _buildTree(array,mid+1,hi,s);
    return pNode;
}

int main()
{
   vector<int> preOrder = {2,1,6,4,3,5,8,7,9};
   vector<int> inOrder  = {1,2,3,4,5,6,7,8,9};
   shared_ptr<node> root = rebuildTree(preOrder,inOrder);
   printTree(root);
}
