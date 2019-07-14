#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

class strTokenizer
{
public:
     strTokenizer(string s,string delims):m_str(s),m_delims(delims)
     {
         auto it = s.begin();
         auto it_next = it;
         while(it != s.end())
         {
             it_next = find_first_of(it,s.end(),m_delims.begin(),m_delims.end());
             if(it_next == s.end()) break;
             size_t pos = distance(s.begin(),it);
             size_t nlen = distance(it,it_next);
             if(nlen)
             {
                 string sub = s.substr(pos,nlen);
                 int val = atoi(sub.c_str());
                 //cout << val << " ";
                 m_tokens.push(val);
             }
             it = it_next +1;
         }
     }
     
     bool getNext(int &num)
     {
         if(m_tokens.empty()) return false;
         num = m_tokens.front();
         m_tokens.pop();
         return true;
     }

private:
     string m_str;
     string m_delims;
     queue<int> m_tokens;
};

class TreeNode
{
   public:
     TreeNode(int dist):m_dist(dist){}
     int getDist(){return m_dist;};
     vector<TreeNode *> getChildren(){return m_children;};
     void insert(TreeNode *node)
     {
         m_children.push_back(node);    
     }
   private:
     int m_dist;  //distance to this node;
     vector<TreeNode *> m_children;
};

class Tree
{  
public:
    Tree(string s):m_tokens(s,"{,}")
    { 
         int dist;
         m_tokens.getNext(dist);
         int n;
         m_tokens.getNext(n);
         cout << endl <<  "{" << dist << "," << n << "}";
         m_root = new TreeNode(dist);
         construct(m_root,n,s,1);   
    }
    TreeNode * getRoot(){return m_root;};

private:
    TreeNode *m_root;
    strTokenizer m_tokens;
    void construct(TreeNode *node,int num,string s, int pos)
    {
        if(num == 0) return ;
        for(int i=0;i<num;i++)
        {
                int dist;
                m_tokens.getNext(dist);
                int  numChildren;
                m_tokens.getNext(numChildren);
                cout << "pos : " << pos ;
                cout << "{" << dist << "," << numChildren << "}" << "," ;
                TreeNode *child = nullptr;
                child = new TreeNode(dist);
                node->insert(child);
                //cout << "Inserted to -> " << node->getDist();
                if(numChildren) construct(child,numChildren,s,pos+1);
                
        }
        return;
    }

    void printTree(TreeNode *node)
    {
 
       cout << endl << node->getDist() << "-->";
       for(TreeNode *child : node->getChildren())
       {
           printTree(child);
       }
    }

    void getDiameter(TreeNode * node,int &height,int &diameter)
    {
        //initialize
        height = diameter = 0;
        if(node == nullptr) {return;}
        vector<int> aheight;
        vector<int>  adiameter;
        vector<TreeNode *> children = node->getChildren();
        //collect child heights and diameters
        for(TreeNode *pChild : children)
        {
            int h,d;
            getDiameter(pChild,h,d);
            aheight.push_back(h + pChild->getDist());
            adiameter.push_back(d);   
        }
        //update height to best height of all children
        if(aheight.size())
           height = *max_element(aheight.begin(),aheight.end());
        //recalculate diameters and choose the best
        //pick top two heights
        if(aheight.size() >= 2)
        {
           //for(int h:aheight) cout << h << ",";
           vector<int> toptwo = {0,0};
           partial_sort_copy(aheight.begin(),aheight.end(),toptwo.begin(),toptwo.end(),std::greater<int>());
           int newDiameter = toptwo[0] + toptwo[1];
           adiameter.push_back(newDiameter);
        }
        //update to diameter to best of all children
        if(adiameter.size())
           diameter = *max_element(adiameter.begin(),adiameter.end());
        cout << "NODE :" << node->getDist() << "<" << height << "," << diameter << ">" << endl;
    }
 public:
    int getDiameter()
    {
         int height = 0;
         int diameter = 0;
         getDiameter(m_root,height,diameter);
         return diameter;
    }
    void printTree(){printTree(m_root);}
};

/*
 * Complete the diameter_of_a_tree function below.
 */
void diameter_of_a_tree(string tree, int ans) {
    /*
     * Write your code here.
     */
     
}


int main()
{
   string s = "{0,3,{5,2,{8,0},{7,0}},{5,2,{9,0},{8,0}},{5,2,{10,0},{9,0}}}";
   string tokens = "{,}";
   int expAnswer = 16;
   strTokenizer tokenizer(s,tokens);
   int num;
   cout << "Tokens : " << endl;
   while(tokenizer.getNext(num))
   {
       cout << num << ",";
   }
   Tree myTree(s);
   //myTree.printTree();
   cout << "Best Diameter " << " : ";
   cout << myTree.getDiameter();
   //diameter_of_a_tree(s,expAnswer);
   cout << endl;
}

