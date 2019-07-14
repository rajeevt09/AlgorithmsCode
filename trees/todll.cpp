#include <iostream>
using namespace std;
struct Node
{
   Node *left;
   Node *right;
   int val;
   Node(int v):val(v),left(nullptr),right(nullptr){}
};
/*
 * Complete the function below.
 */
void todll(Node *p,Node **head,Node **tail);

void printdll(Node *head)
{
    Node *p = head;
    do
    { 
        cout << p->val;
        p = p->right;
    }while(p);
}

void BSTtoLL(Node* root) {
   Node *head;
   Node *tail;
   todll(root,&head,&tail);
//   cout << "Head/Tails : " << head << "/" << tail << endl;
   if(head&&tail)
   {
      tail->right = head;
      head->left = tail;
      printdll(head);
   }
}

void pushtodll(Node *h,Node *p)
{
    if(h&&p)
    {
        h->right = p;
        p->left = h;
    }
}

void todll(Node *p,Node **head,Node **tail)
{
    Node *left_head;
    Node *left_tail;
    Node *right_head;
    Node *right_tail;
    *head = *tail = nullptr;
    if(p==nullptr) return;
    todll(p->left,&left_head,&left_tail);
    todll(p->right,&right_head,&right_tail);
    
    //Link Self to Left and Right DLL's
    pushtodll(left_tail,p);
    pushtodll(p,right_head);
    if(left_head == nullptr)
    {
        left_head = p;
    }
    if(right_tail == nullptr)
    {
        right_tail = p;
    }
    //return new DLL's head and Tail
    *head = left_head;
    *tail = right_tail;
   cout << "p Head/Tails : " << p->val << " " <<  (*head)->val << " "  << (*tail)->val << ";"  << endl;
    return;
}

int main()
{
    cout << "Tree To DLL" << endl;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    Node *tl = root->left;
    tl->left = new Node(4);
    tl->right = new Node(5);
    tl = root->right;
    tl->left = new Node(6);
    tl->right = new Node(7);
    BSTtoLL(root);
	
}
