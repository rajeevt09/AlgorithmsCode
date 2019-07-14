/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isBST(TreeNode *node,int &min,int &max);
    
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int min,max;
        return isBST(root,min,max);
    }
};


bool isBST(TreeNode *node,int &min,int &max)
{
int lmin,lmax,rmin,rmax;
if(node==nullptr) {return true;}
lmin=lmax=rmin=rmax=node->val;
if(node->left && !isBST(node->left,lmin,lmax)) return false;
if(node->right && !isBST(node->right,rmin,rmax)) return false;
if(((node->left) && (node->val <= lmax)))
{
//min = lmin;
return false;
}
else
{
min = lmin;
}
if((node->right) &&(node->val >= rmin))
{
//max= rmax;
return false;
}
else
{
max = rmax;
}
return true;
}
