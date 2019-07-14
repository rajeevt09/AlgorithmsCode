#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct Node
{
   Node *left;
   Node *right;
   int val;
   Node(int v):val(v),left(nullptr),right(nullptr){}
};
int findUnivalTrees(Node *pNode,int &uniVal);
int findSingleValueTreesBup(Node *node)
{
    int unival;
    return findUnivalTrees(node,unival);
}

int findUnivalTrees(Node *pNode,int &uniVal)
{
    if(pNode==nullptr) return 0;
    int lcount = 0,rcount = 0,lval,rval;
    if(pNode->left)
    {
        lcount = findUnivalTrees(pNode->left,lval);
    }
    if(pNode->right)
    {
        rcount = findUnivalTrees(pNode->right,rval);
    }
    int count = lcount + rcount;
    //if left , right and this node are same unival
    if (((pNode->left == nullptr) || (pNode->left && pNode->val == lval)) && 
      ((pNode->right == nullptr) || (pNode->right && pNode->val == rval)))
   {
    count = count+1;  
   }
   uniVal = pNode->val;
   return count;
}

int main()
{
    cout << "Count Unival Trees" << endl;
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(5);
    Node *tl = root->left;
    tl->left = new Node(4);
    tl->right = new Node(4);
    tl = root->right;
    tl->left = nullptr;
    tl->right = new Node(5);
    cout << " " <<  findSingleValueTreesBup(root) << endl;
	
}
