#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <memory>
using namespace std;
class TreeNode
{
public:
   int val;
   shared_ptr<TreeNode> left = nullptr;
   shared_ptr<TreeNode> right = nullptr;
   TreeNode(int v):val(v),left(nullptr),right(nullptr)
   {
   }
   ~TreeNode()
   {
       cout << "destroy " << val << endl;
   }
};

void printTree(shared_ptr<TreeNode> root)
{
    int val;
    if(root == nullptr) return;
    queue<pair<shared_ptr<TreeNode>,int>> q;
    int level =0;
    q.push(make_pair(root,level));
    cout << "Displaying Tree : " << endl;
    
    while(!q.empty())
    {
        pair<shared_ptr<TreeNode>,int> pr = q.front();
        shared_ptr<TreeNode> p = pr.first;
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

shared_ptr<TreeNode> _buildTree(vector<int> array,int lo,int hi,stack<int> &s);
shared_ptr<TreeNode> rebuildTree(vector<int> preOrder,vector<int> inOrder)
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

shared_ptr<TreeNode> _buildTree(vector<int> array,int lo,int hi,stack<int> &s)
{
    if(lo > hi) return nullptr;
    int val = s.top();
    shared_ptr<TreeNode> pNode = make_shared<TreeNode>(val);
    int mid = lo;
    while(array[mid] != val && mid <= hi) mid++;
    //determine mid 
    s.pop();
    pNode->left = _buildTree(array,lo,mid-1,s);
    pNode->right = _buildTree(array,mid+1,hi,s);
    return pNode;
}
shared_ptr<TreeNode> constructBST(vector<int> &list,int &index,int min,int max)
{
       cout << index << "," << min << "," << max << endl;
       shared_ptr<TreeNode> pNode = nullptr;
       if(index >= list.size()) return pNode;
       //check if node val is in range 
       if((list[index] < min) || (list[index] > max)) return pNode; //if not does not belong here
       pNode = make_shared<TreeNode>(list[index]);
       index++;
       if(index <= list.size()-1) pNode->left = constructBST(list,index,min,pNode->val);
       if(index <= list.size()-1) pNode->right = constructBST(list,index,pNode->val,max);
       return pNode;
}

void inorder(shared_ptr<TreeNode> pNode,vector<int> &list)
{
    if(pNode == nullptr) return;
    list.push_back(pNode->val);
    inorder(pNode->left,list);
    inorder(pNode->right,list);
}

vector<int> serializeBST(shared_ptr<TreeNode> pNode)
{
    vector<int> list;
    inorder(pNode,list);
    return list;
}

shared_ptr<TreeNode> deserializeBST(vector<int> &list)
{
    cout << "Inpout List Size :" << list.size() << endl;
    int i =0;
    return constructBST(list,i,INT_MIN,INT_MAX);
}

 
int main()
{
   vector<int> preOrder = {4,2,1,3,6,5,7};
   vector<int> inOrder  = {1,2,3,4,5,6,7};
   shared_ptr<TreeNode> root = rebuildTree(preOrder,inOrder);

   printTree(root);
   //we now have the tree 
   cout << "serializing tree" << endl;
   //serialize it to vector<int>
   vector<int> list = serializeBST(root);
   for(auto i:list) cout << i << "," ;
   //Deserialize it
   shared_ptr<TreeNode> deserializedBST = deserializeBST(list);
   cout << "printing deserialized BST" << endl;
   printTree(deserializedBST);

}

