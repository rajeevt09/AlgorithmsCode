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

shared_ptr<node> createtree(vector<int> &list);
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

shared_ptr<node> createtree(vector<int> &list,int i,int j);
shared_ptr<node> createtree(vector<int> &list)
{
   return createtree(list,0,list.size()-1);
}

shared_ptr<node> createtree(vector<int> &list,int i,int j)
{
     if( i > j ) return nullptr;
     int mid = i + (j-i)/2;
     //create the mid node and recurse veerything to left and right
     shared_ptr<node> pnode = make_shared<node>(list[mid]);
     pnode->left = createtree(list,i,mid-1);
     pnode->right = createtree(list,mid+1,j);
     return pnode;
}

void merge(vector<int> &v1,vector<int> &v2,vector<int> &merged)
{
   int n1 = v1.size();
   int n2 = v2.size();
   int i=0,j=0;
   while(i < n1 && j < n2)
   {
       if(v1[i] <= v2[j])
       {
          merged.push_back(v1[i++]);
       }
       else
       {
          merged.push_back(v2[j++]);
       }
   }

   //now copy rest of the array
   while(i < n1)  merged.push_back(v1[i++]);
   while(j < n2) merged.push_back(v2[j++]);

}

void inorder(shared_ptr<node> pnode,vector<int> &list)
{
     if(pnode == nullptr) return;
     inorder(pnode->left,list);
     list.push_back(pnode->val);
     inorder(pnode->right,list);
}

/*
* Complete the function below.
Return merge of two input BST's
*/
shared_ptr<node> mergeTrees(shared_ptr<node> t1, shared_ptr<node> t2) {
    shared_ptr<node> mergetree;
    vector<int> v1;
    inorder(t1,v1);
    vector<int> v2;
    inorder(t2,v2);
    vector<int> v3;
    merge(v1,v2,v3);
    mergetree = createtree(v3);
    return mergetree;
}

int main()
{
   vector<int> preOrder1 = {13,4,1,7,20,15,29};
   vector<int> inOrder1  = {1,4,7,13,15,20,29};

   vector<int> preOrder2 = {10,6,2,24,22,31};
   vector<int> inOrder2  = {2,6,10,22,24,31};


   shared_ptr<node> bst1 = rebuildTree(preOrder1,inOrder1);
   shared_ptr<node> bst2 = rebuildTree(preOrder2,inOrder2);
   printTree(bst1);
   printTree(bst2);
   shared_ptr<node> mergedtree = mergeTrees(bst1,bst2);
   printTree(mergedtree);
   vector<int> mergelist;
   inorder(mergedtree,mergelist);
   cout << "inorder of merged tree" << endl;
   for(auto val:mergelist) cout << val << " , " ;
 
}
