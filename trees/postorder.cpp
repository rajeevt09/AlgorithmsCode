#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(nullptr), right(nullptr) {}
};

class NodeNew
{
public:
   Node *m_pnode = nullptr;
   char m_c;
   NodeNew(Node *p,char c):m_pnode(p),m_c(c){};
   ~NodeNew(){};    
};


/*
 * Complete the function below.
 */
void postorderTraversal(Node* root) {
    stack<NodeNew *> s;
    s.push(new NodeNew(root,'0'));
    //int i = 10;
    while(!s.empty())
    {
       // i--;
        NodeNew *n = s.top();
        root = n->m_pnode;
        //cout << "top in stack " << n->m_pnode->val << "Marker  " << n->m_c;
        if(n->m_c == '#')
        {
            delete n;
            s.pop();
            NodeNew *n = s.top();
            cout << n->m_pnode->val << " ";
            s.pop();
            delete n;
            continue;
        }
        s.push(new NodeNew(root,'#'));
        if(root->right) s.push(new NodeNew(root->right,'0')); 
        if(root->left) s.push(new NodeNew(root->left,'0'));
        
    }
}

int main()
{
    cout << "PostOrderTraversal" << endl;	
int _size;
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    Node *r = root->right;
    Node *l = root->left;
    l->left = new Node(3);
    l->right = new Node(7);
    r->left = new Node(18);
    r->right = new Node(22);
    postorderTraversal(root);
}
