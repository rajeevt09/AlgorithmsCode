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



/*
      2
    1   6
      4   8
     3 5 7 9
PREOrder: 2,1,6,4,3,5,8,7,9
  Ptr    Stack           o/p
  2      [6]               2
  1      [6]               1
  null   
  6      [8]               6
  4      [5,8]             4
  3                        3
  5      [8]               5
  8      [9]               8
  7      [9]               7
 null   
  9                        9


PostOrder:  1,3,5,4,7,9,8,6,2

same as preorder except :
print , enque left child in stack and go right 

o/p : 2,6,8,9,7,4,5,3,1 and then reverse

  Ptr    Stack           o/p
  2      [1]              2
  6      [4,1]            6
  8      [7,4,1]          8
  9      [7,4,1]          9
  null
  7      [4,1]            7
  4      [3,1]            4     
  5                       5
  3      [1]              3
  1                       1

//iterative inorder traversal

1. Init pNode to root
2.  repate 3 in loop
3 if (pNode) print .push right to stack and go left
   else pnode = pop from stack



*/

using sp = shared_ptr<node>;
vector<int> preorder(sp root)
{
    vector<int> results;
    stack<sp> s;
    sp p = root;
    while( p || !s.empty())
    {
        if(p)
        {
             results.push_back(p->val);
             if(p->right) s.push(p->right);
             p = p->left;
        }
        else
        {
            p = s.top();s.pop();
        } 
    }
    return results;    
}
vector<int> postorder(sp root)
{
    vector<int> results;
    stack<sp> s;
    sp p = root;
    while( p || !s.empty())
    {
        if(p)
        {
             results.push_back(p->val);
             if(p->left) s.push(p->left);
             p = p->right;
        }
        else
        {
            p = s.top();s.pop();
        } 
    }
    std::reverse(results.begin(),results.end());
    return results;    
}

int main()
{
   vector<int> preOrder = {2,1,6,4,3,5,8,7,9};
   vector<int> inOrder  = {1,2,3,4,5,6,7,8,9};
   shared_ptr<node> root = rebuildTree(preOrder,inOrder);
   printTree(root);
   cout << "printing pre order iter" << endl;
   for(auto i:preorder(root)) cout << i << ",";
   cout << endl;
   cout << "printing post order iter" << endl;
   for(auto i:postorder(root)) cout << i << ",";
   cout << endl;

}
